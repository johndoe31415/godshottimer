/*
	godshottimer - ATtiny88-based espresso extraction timer.
	Copyright (C) 2021-2021 Johannes Bauer

	This file is part of godshottimer.

	godshottimer is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; this program is ONLY licensed under
	version 3 of the License, later versions are explicitly excluded.

	godshottimer is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with godshottimer; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

	Johannes Bauer <JohannesBauer@gmx.de>
*/


#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "godshottimer.h"
#include "hal.h"

#define STOPWATCH_START_VALUE		250
#define STOPWATCH_LOWEST_VALUE		-999
#define SEGMENT_DOT					0x80
#define BUTTON_THRESHOLD			25
#define BUZZER_DURATION_2MS			25		/* 50ms beep */

enum modus_t {
	MODE_STOPWATCH_STOPPED = 0,
	MODE_STOPWATCH_RUNNING = 1,
	MODE_DISPLAY_CLOCK = 2,
	MODE_SET_CLOCK = 3,
};

static volatile enum modus_t current_mode = MODE_STOPWATCH_STOPPED;
static volatile char display_text1[4], display_text2[4];
static volatile uint8_t active_display = 0;
static volatile uint8_t current_digit;
static volatile int16_t stopwatch_value;
static volatile uint8_t button_outer_ctr, button_inner_ctr;
static volatile bool button_outer_pressed, button_inner_pressed;
static volatile uint8_t hours, minutes;
static volatile uint16_t hundreds;
static volatile uint8_t buzzer_off_threshold;

static void all_segments_off(void) {
	SegmentA_SetInactive();
	SegmentB_SetInactive();
	SegmentC_SetInactive();
	SegmentD_SetInactive();
	SegmentE_SetInactive();
	SegmentF_SetInactive();
	SegmentG_SetInactive();
	SegmentDot_SetInactive();
}

static void show_segment_char(char x) {
	all_segments_off();
	if (x & SEGMENT_DOT) {
		SegmentDot_SetActive();
	}
	switch (x & ((~SEGMENT_DOT) & 0xff)) {
		case '0':
			SegmentA_SetActive();
			SegmentB_SetActive();
			SegmentC_SetActive();
			SegmentD_SetActive();
			SegmentE_SetActive();
			SegmentF_SetActive();
			break;

		case '1':
			SegmentB_SetActive();
			SegmentC_SetActive();
			break;

		case '2':
			SegmentA_SetActive();
			SegmentB_SetActive();
			SegmentG_SetActive();
			SegmentD_SetActive();
			SegmentE_SetActive();
			break;

		case '3':
			SegmentA_SetActive();
			SegmentB_SetActive();
			SegmentC_SetActive();
			SegmentD_SetActive();
			SegmentG_SetActive();
			break;

		case '4':
			SegmentF_SetActive();
			SegmentG_SetActive();
			SegmentB_SetActive();
			SegmentC_SetActive();
			break;

		case '5':
			SegmentA_SetActive();
			SegmentF_SetActive();
			SegmentG_SetActive();
			SegmentC_SetActive();
			SegmentD_SetActive();
			break;

		case '6':
			SegmentA_SetActive();
			SegmentF_SetActive();
			SegmentE_SetActive();
			SegmentD_SetActive();
			SegmentC_SetActive();
			SegmentG_SetActive();
			break;

		case '7':
			SegmentA_SetActive();
			SegmentB_SetActive();
			SegmentC_SetActive();
			break;

		case '8':
			SegmentA_SetActive();
			SegmentB_SetActive();
			SegmentC_SetActive();
			SegmentD_SetActive();
			SegmentE_SetActive();
			SegmentF_SetActive();
			SegmentG_SetActive();
			break;

		case '9':
			SegmentA_SetActive();
			SegmentB_SetActive();
			SegmentC_SetActive();
			SegmentD_SetActive();
			SegmentF_SetActive();
			SegmentG_SetActive();
			break;

		case '-':
			SegmentG_SetActive();
			break;
	}
}

static void all_digits_off(void) {
	Digit1_SetInactive();
	Digit2_SetInactive();
	Digit3_SetInactive();
	Digit4_SetInactive();
}

static void set_digit_on(uint8_t i) {
	if (i == 0) {
		Digit1_SetActive();
	} else if (i == 1) {
		Digit2_SetActive();
	} else if (i == 2) {
		Digit3_SetActive();
	} else if (i == 3) {
		Digit4_SetActive();
	}
}

static volatile char* get_active_display(void) {
	if (active_display == 0) {
		return display_text1;
	} else {
		return display_text2;
	}
}

static volatile char* get_shadow_display(void) {
	if (active_display == 0) {
		return display_text2;
	} else {
		return display_text1;
	}
}

static void set_display_number(uint8_t pos, uint8_t length, uint16_t value, int8_t leading_zero_count) {
	volatile char *display_text = get_shadow_display();
	for (int8_t i = length - 1; i >= 0; i--) {
		uint8_t next_digit = value % 10;
		if ((leading_zero_count > 0) && (next_digit == 0) && (i < length - leading_zero_count)) {
			break;
		}
		value = value / 10;
		display_text[pos + i] = '0' + next_digit;
	}
}

static void set_signed_display_number(uint8_t pos, uint8_t length, int16_t value, int8_t leading_zero_count) {
	if (value >= 0) {
		set_display_number(pos, length, value, leading_zero_count);
	} else {
		volatile char *display_text = get_shadow_display();
		set_display_number(pos, length, -value, leading_zero_count);
		display_text[0] = '-';
	}

}

static void display_commit(void) {
	active_display = 1 - active_display;
}

static void erase_display(volatile char *display_text) {
	memset((char*)display_text, 0, 4);
}

static void buzzer_on(uint8_t ocr) {
	OCR2A = ocr;
	TCCR2A = _BV(WGM21) | _BV(COM2B0) | _BV(COM2A0);
	Buzzer_ModeOutput();
}

static void buzzer_off(void) {
	TCCR2A = 0;
	Buzzer_ModeInput();
}

ISR(TIMER0_OVF_vect) {
	volatile char *display_text = get_active_display();
	all_digits_off();
	show_segment_char(display_text[current_digit]);
	set_digit_on(current_digit);
	current_digit = (current_digit + 1) % 4;

	if (SwitchOuter_IsActive() && SwitchInner_IsActive()) {
		uint8_t lower_ctr = (button_outer_ctr < button_inner_ctr) ? button_outer_ctr : button_inner_ctr;
		button_outer_ctr = lower_ctr;
		button_inner_ctr = lower_ctr;
	}

	if (SwitchOuter_IsActive()) {
		if (button_outer_ctr < BUTTON_THRESHOLD) {
			button_outer_ctr++;
		} else if (button_outer_ctr == BUTTON_THRESHOLD) {
			button_outer_ctr++;
			button_outer_pressed = true;
		}
	} else {
		button_outer_ctr = 0;
	}

	if (SwitchInner_IsActive()) {
		if (button_inner_ctr < BUTTON_THRESHOLD) {
			button_inner_ctr++;
		} else if (button_inner_ctr == BUTTON_THRESHOLD) {
			button_inner_ctr++;
			button_inner_pressed = true;
		}
	} else {
		button_inner_ctr = 0;
	}

	buzzer_off_threshold++;
	if (buzzer_off_threshold == BUZZER_DURATION_2MS) {
		buzzer_off();
	}
}

ISR(TIMER1_OVF_vect) {
	TCNT1 = 65536 - 3125;		 /* 100ms */
	if (current_mode == MODE_STOPWATCH_RUNNING) {
		if (stopwatch_value > STOPWATCH_LOWEST_VALUE) {
			stopwatch_value--;
			if (stopwatch_value == 0) {
				buzzer_on(200);
				buzzer_off_threshold = 0;
			}
		} else {
			current_mode = MODE_STOPWATCH_STOPPED;
		}
	}
	hundreds++;
	if (hundreds >= 600) {
		if (current_mode == MODE_SET_CLOCK) {
			current_mode = MODE_DISPLAY_CLOCK;
		}
		hundreds = 0;
		minutes++;
		if (minutes == 60) {
			hours++;
			minutes = 0;
			if (hours == 24) {
				hours = 0;
			}
		}
	}
}

int main(void) {
	initHAL();

	/* Initialize components */
	stopwatch_value = STOPWATCH_START_VALUE;
	current_mode = MODE_SET_CLOCK;

	/* Set Timer0 to overflow ~2 ms */
	TCCR0B = _BV(CS00) | _BV(CS01);
	TIMSK0 = _BV(TOIE0);

	/* Set Timer1 to overflow every 100ms, preload at 65536 - 3125, CK/256 */
	TCNT1 = 65536 - 3125;		 /* 100ms */
	TCCR1B = _BV(CS12);
	TIMSK1 = _BV(TOIE1);

	/* Set Timer2 to connect to buzzer via OC2B, CTC Mode (mode 2), CK/8 */
	TCCR2B |= _BV(CS21);

	/* Enable IRQs */
	sei();

	while (true) {
		if (button_outer_pressed && button_inner_pressed) {
			if (current_mode == MODE_STOPWATCH_STOPPED) {
				current_mode = MODE_DISPLAY_CLOCK;
			} else if ((current_mode == MODE_DISPLAY_CLOCK) || (current_mode == MODE_SET_CLOCK)) {
				current_mode = MODE_STOPWATCH_STOPPED;
				stopwatch_value = STOPWATCH_START_VALUE;
			}

			button_outer_pressed = false;
			button_inner_pressed = false;
		} else if (button_outer_pressed) {
			if (current_mode == MODE_STOPWATCH_STOPPED) {
				if (stopwatch_value > STOPWATCH_LOWEST_VALUE) {
					current_mode = MODE_STOPWATCH_RUNNING;
				}
			} else if (current_mode == MODE_STOPWATCH_RUNNING) {
				current_mode = MODE_STOPWATCH_STOPPED;
			} else if (current_mode == MODE_SET_CLOCK) {
				minutes++;
				if (minutes == 60) {
					minutes = 0;
				}
			}
			button_outer_pressed = false;
		} else if (button_inner_pressed) {
			if (current_mode == MODE_STOPWATCH_STOPPED) {
				stopwatch_value = STOPWATCH_START_VALUE;
			} else if (current_mode == MODE_STOPWATCH_RUNNING) {
				current_mode = MODE_STOPWATCH_STOPPED;
			} else if (current_mode == MODE_SET_CLOCK) {
				hours++;
				if (hours == 24) {
					hours = 0;
				}
			}
			button_inner_pressed = false;
		}

		if ((current_mode == MODE_STOPWATCH_STOPPED) || (current_mode == MODE_STOPWATCH_RUNNING)) {
			volatile char *display_text = get_shadow_display();
			erase_display(display_text);
			set_signed_display_number(1, 3, stopwatch_value, 2);
			display_text[3] |= SEGMENT_DOT;
			display_commit();
		} else if ((current_mode == MODE_DISPLAY_CLOCK) || (current_mode == MODE_SET_CLOCK)) {
			volatile char *display_text = get_shadow_display();
			erase_display(display_text);
			set_display_number(0, 2, hours, 1);
			set_display_number(2, 2, minutes, 2);

			if (current_mode == MODE_SET_CLOCK) {
				display_text[hundreds % 4] |= SEGMENT_DOT;
			} else {
				bool show = (hundreds % 10) < 5;
				if (show) {
					display_text[1] |= SEGMENT_DOT;
					display_text[2] |= SEGMENT_DOT;
				}
			}
			display_commit();
		}
	}
}
