.PHONY: all clean program


CFLAGS := -mmcu=atmega88 -Os -Wall -Wextra -Wstrict-prototypes -std=c11 -DF_CPU=8000000UL
OBJS := godshottimer.o

all: godshottimer

reset:
	avrdude -c stk500v2 -p m88p  -P /dev/ttyACM0 -V -B10	

clean:
	rm -f godshottimer godshottimer.bin $(OBJS)

halgen:
	../HALGen/halgen -o hal.h -a avr hal.xml

program: godshottimer.bin
	avrdude -c stk500v2 -p m88p  -P /dev/ttyACM0 -V -U flash:w:godshottimer.bin:r

godshottimer: $(OBJS)
	avr-gcc $(CFLAGS) -o $@ $(OBJS)

godshottimer.bin: godshottimer
	avr-objcopy -O binary -j .text -j .data $< $@

.c.o:	
	avr-gcc $(CFLAGS) -c -o $@ $<
