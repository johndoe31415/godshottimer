/* Automatically generated HAL from hal.xml */
/* NEVER EDIT MANUALLY */

/* Generated on: 2021-11-06 21:40:21 */

#ifndef __HAL_H__
#define __HAL_H__

#include <avr/io.h>

#define nop()                                    __asm__ __volatile__("nop")

/* Digit4 -> PD0 (Output, Initially Inactive) */
#define Digit4_BIT                               0
#define Digit4_PIN                               PIND
#define Digit4_PORT                              PORTD
#define Digit4_DDR                               DDRD
#define Digit4_ModeOutput()                      Digit4_DDR |= _BV(Digit4_BIT)
#define Digit4_IsOutput()                        ((Digit4_DDR & _BV(Digit4_BIT)) != 0)
#define Digit4_SetHIGH()                         Digit4_PORT |= _BV(Digit4_BIT)
#define Digit4_SetLOW()                          Digit4_PORT &= ~_BV(Digit4_BIT)
#define Digit4_Get()                             (Digit4_PIN & _BV(Digit4_BIT))
#define Digit4_SetInactive()                     Digit4_SetLOW()
#define Digit4_SetActive()                       Digit4_SetHIGH()
#define Digit4_Toggle()                          Digit4_PORT ^= _BV(Digit4_BIT)
#define Digit4_SetConditional(condition)         if (condition) Digit4_SetActive(); else Digit4_SetInactive()
#define Digit4_SetConditionalToggle(conditionon, conditionoff, conditiontoggle) if (conditionon) { Digit4_SetActive(); } else if (conditionoff) { Digit4_SetInactive(); } else if (conditiontoggle) { Digit4_Toggle(); }
#define Digit4_Pulse()                           { Digit4_SetActive(); Digit4_SetInactive(); }
#define Digit4_PulseNop()                        { Digit4_SetActive(); nop(); Digit4_SetInactive(); }
#define Digit4_IsInactive()                      (Digit4_Get() == 0)
#define Digit4_IsActive()                        (Digit4_Get() != 0)
#define Digit4_Init()                            { Digit4_SetInactive(); Digit4_ModeOutput(); }

/* SegmentD -> PD1 (Output, Initially Inactive, Active-Low) */
#define SegmentD_BIT                             1
#define SegmentD_PIN                             PIND
#define SegmentD_PORT                            PORTD
#define SegmentD_DDR                             DDRD
#define SegmentD_ModeOutput()                    SegmentD_DDR |= _BV(SegmentD_BIT)
#define SegmentD_IsOutput()                      ((SegmentD_DDR & _BV(SegmentD_BIT)) != 0)
#define SegmentD_SetHIGH()                       SegmentD_PORT |= _BV(SegmentD_BIT)
#define SegmentD_SetLOW()                        SegmentD_PORT &= ~_BV(SegmentD_BIT)
#define SegmentD_Get()                           (SegmentD_PIN & _BV(SegmentD_BIT))
#define SegmentD_SetInactive()                   SegmentD_SetHIGH()
#define SegmentD_SetActive()                     SegmentD_SetLOW()
#define SegmentD_Toggle()                        SegmentD_PORT ^= _BV(SegmentD_BIT)
#define SegmentD_SetConditional(condition)       if (condition) SegmentD_SetActive(); else SegmentD_SetInactive()
#define SegmentD_SetConditionalToggle(conditionon, conditionoff, conditiontoggle) if (conditionon) { SegmentD_SetActive(); } else if (conditionoff) { SegmentD_SetInactive(); } else if (conditiontoggle) { SegmentD_Toggle(); }
#define SegmentD_Pulse()                         { SegmentD_SetActive(); SegmentD_SetInactive(); }
#define SegmentD_PulseNop()                      { SegmentD_SetActive(); nop(); SegmentD_SetInactive(); }
#define SegmentD_IsInactive()                    (SegmentD_Get() != 0)
#define SegmentD_IsActive()                      (SegmentD_Get() == 0)
#define SegmentD_Init()                          { SegmentD_SetInactive(); SegmentD_ModeOutput(); }

/* SegmentC -> PD2 (Output, Initially Inactive, Active-Low) */
#define SegmentC_BIT                             2
#define SegmentC_PIN                             PIND
#define SegmentC_PORT                            PORTD
#define SegmentC_DDR                             DDRD
#define SegmentC_ModeOutput()                    SegmentC_DDR |= _BV(SegmentC_BIT)
#define SegmentC_IsOutput()                      ((SegmentC_DDR & _BV(SegmentC_BIT)) != 0)
#define SegmentC_SetHIGH()                       SegmentC_PORT |= _BV(SegmentC_BIT)
#define SegmentC_SetLOW()                        SegmentC_PORT &= ~_BV(SegmentC_BIT)
#define SegmentC_Get()                           (SegmentC_PIN & _BV(SegmentC_BIT))
#define SegmentC_SetInactive()                   SegmentC_SetHIGH()
#define SegmentC_SetActive()                     SegmentC_SetLOW()
#define SegmentC_Toggle()                        SegmentC_PORT ^= _BV(SegmentC_BIT)
#define SegmentC_SetConditional(condition)       if (condition) SegmentC_SetActive(); else SegmentC_SetInactive()
#define SegmentC_SetConditionalToggle(conditionon, conditionoff, conditiontoggle) if (conditionon) { SegmentC_SetActive(); } else if (conditionoff) { SegmentC_SetInactive(); } else if (conditiontoggle) { SegmentC_Toggle(); }
#define SegmentC_Pulse()                         { SegmentC_SetActive(); SegmentC_SetInactive(); }
#define SegmentC_PulseNop()                      { SegmentC_SetActive(); nop(); SegmentC_SetInactive(); }
#define SegmentC_IsInactive()                    (SegmentC_Get() != 0)
#define SegmentC_IsActive()                      (SegmentC_Get() == 0)
#define SegmentC_Init()                          { SegmentC_SetInactive(); SegmentC_ModeOutput(); }

/* Digit3 -> PC1 (Output, Initially Inactive) */
#define Digit3_BIT                               1
#define Digit3_PIN                               PINC
#define Digit3_PORT                              PORTC
#define Digit3_DDR                               DDRC
#define Digit3_ModeOutput()                      Digit3_DDR |= _BV(Digit3_BIT)
#define Digit3_IsOutput()                        ((Digit3_DDR & _BV(Digit3_BIT)) != 0)
#define Digit3_SetHIGH()                         Digit3_PORT |= _BV(Digit3_BIT)
#define Digit3_SetLOW()                          Digit3_PORT &= ~_BV(Digit3_BIT)
#define Digit3_Get()                             (Digit3_PIN & _BV(Digit3_BIT))
#define Digit3_SetInactive()                     Digit3_SetLOW()
#define Digit3_SetActive()                       Digit3_SetHIGH()
#define Digit3_Toggle()                          Digit3_PORT ^= _BV(Digit3_BIT)
#define Digit3_SetConditional(condition)         if (condition) Digit3_SetActive(); else Digit3_SetInactive()
#define Digit3_SetConditionalToggle(conditionon, conditionoff, conditiontoggle) if (conditionon) { Digit3_SetActive(); } else if (conditionoff) { Digit3_SetInactive(); } else if (conditiontoggle) { Digit3_Toggle(); }
#define Digit3_Pulse()                           { Digit3_SetActive(); Digit3_SetInactive(); }
#define Digit3_PulseNop()                        { Digit3_SetActive(); nop(); Digit3_SetInactive(); }
#define Digit3_IsInactive()                      (Digit3_Get() == 0)
#define Digit3_IsActive()                        (Digit3_Get() != 0)
#define Digit3_Init()                            { Digit3_SetInactive(); Digit3_ModeOutput(); }

/* Digit2 -> PD4 (Output, Initially Inactive) */
#define Digit2_BIT                               4
#define Digit2_PIN                               PIND
#define Digit2_PORT                              PORTD
#define Digit2_DDR                               DDRD
#define Digit2_ModeOutput()                      Digit2_DDR |= _BV(Digit2_BIT)
#define Digit2_IsOutput()                        ((Digit2_DDR & _BV(Digit2_BIT)) != 0)
#define Digit2_SetHIGH()                         Digit2_PORT |= _BV(Digit2_BIT)
#define Digit2_SetLOW()                          Digit2_PORT &= ~_BV(Digit2_BIT)
#define Digit2_Get()                             (Digit2_PIN & _BV(Digit2_BIT))
#define Digit2_SetInactive()                     Digit2_SetLOW()
#define Digit2_SetActive()                       Digit2_SetHIGH()
#define Digit2_Toggle()                          Digit2_PORT ^= _BV(Digit2_BIT)
#define Digit2_SetConditional(condition)         if (condition) Digit2_SetActive(); else Digit2_SetInactive()
#define Digit2_SetConditionalToggle(conditionon, conditionoff, conditiontoggle) if (conditionon) { Digit2_SetActive(); } else if (conditionoff) { Digit2_SetInactive(); } else if (conditiontoggle) { Digit2_Toggle(); }
#define Digit2_Pulse()                           { Digit2_SetActive(); Digit2_SetInactive(); }
#define Digit2_PulseNop()                        { Digit2_SetActive(); nop(); Digit2_SetInactive(); }
#define Digit2_IsInactive()                      (Digit2_Get() == 0)
#define Digit2_IsActive()                        (Digit2_Get() != 0)
#define Digit2_Init()                            { Digit2_SetInactive(); Digit2_ModeOutput(); }

/* Digit1 -> PD7 (Output, Initially Inactive) */
#define Digit1_BIT                               7
#define Digit1_PIN                               PIND
#define Digit1_PORT                              PORTD
#define Digit1_DDR                               DDRD
#define Digit1_ModeOutput()                      Digit1_DDR |= _BV(Digit1_BIT)
#define Digit1_IsOutput()                        ((Digit1_DDR & _BV(Digit1_BIT)) != 0)
#define Digit1_SetHIGH()                         Digit1_PORT |= _BV(Digit1_BIT)
#define Digit1_SetLOW()                          Digit1_PORT &= ~_BV(Digit1_BIT)
#define Digit1_Get()                             (Digit1_PIN & _BV(Digit1_BIT))
#define Digit1_SetInactive()                     Digit1_SetLOW()
#define Digit1_SetActive()                       Digit1_SetHIGH()
#define Digit1_Toggle()                          Digit1_PORT ^= _BV(Digit1_BIT)
#define Digit1_SetConditional(condition)         if (condition) Digit1_SetActive(); else Digit1_SetInactive()
#define Digit1_SetConditionalToggle(conditionon, conditionoff, conditiontoggle) if (conditionon) { Digit1_SetActive(); } else if (conditionoff) { Digit1_SetInactive(); } else if (conditiontoggle) { Digit1_Toggle(); }
#define Digit1_Pulse()                           { Digit1_SetActive(); Digit1_SetInactive(); }
#define Digit1_PulseNop()                        { Digit1_SetActive(); nop(); Digit1_SetInactive(); }
#define Digit1_IsInactive()                      (Digit1_Get() == 0)
#define Digit1_IsActive()                        (Digit1_Get() != 0)
#define Digit1_Init()                            { Digit1_SetInactive(); Digit1_ModeOutput(); }

/* SegmentE -> PB0 (Output, Initially Inactive, Active-Low) */
#define SegmentE_BIT                             0
#define SegmentE_PIN                             PINB
#define SegmentE_PORT                            PORTB
#define SegmentE_DDR                             DDRB
#define SegmentE_ModeOutput()                    SegmentE_DDR |= _BV(SegmentE_BIT)
#define SegmentE_IsOutput()                      ((SegmentE_DDR & _BV(SegmentE_BIT)) != 0)
#define SegmentE_SetHIGH()                       SegmentE_PORT |= _BV(SegmentE_BIT)
#define SegmentE_SetLOW()                        SegmentE_PORT &= ~_BV(SegmentE_BIT)
#define SegmentE_Get()                           (SegmentE_PIN & _BV(SegmentE_BIT))
#define SegmentE_SetInactive()                   SegmentE_SetHIGH()
#define SegmentE_SetActive()                     SegmentE_SetLOW()
#define SegmentE_Toggle()                        SegmentE_PORT ^= _BV(SegmentE_BIT)
#define SegmentE_SetConditional(condition)       if (condition) SegmentE_SetActive(); else SegmentE_SetInactive()
#define SegmentE_SetConditionalToggle(conditionon, conditionoff, conditiontoggle) if (conditionon) { SegmentE_SetActive(); } else if (conditionoff) { SegmentE_SetInactive(); } else if (conditiontoggle) { SegmentE_Toggle(); }
#define SegmentE_Pulse()                         { SegmentE_SetActive(); SegmentE_SetInactive(); }
#define SegmentE_PulseNop()                      { SegmentE_SetActive(); nop(); SegmentE_SetInactive(); }
#define SegmentE_IsInactive()                    (SegmentE_Get() != 0)
#define SegmentE_IsActive()                      (SegmentE_Get() == 0)
#define SegmentE_Init()                          { SegmentE_SetInactive(); SegmentE_ModeOutput(); }

/* SegmentG -> PD6 (Output, Initially Inactive, Active-Low) */
#define SegmentG_BIT                             6
#define SegmentG_PIN                             PIND
#define SegmentG_PORT                            PORTD
#define SegmentG_DDR                             DDRD
#define SegmentG_ModeOutput()                    SegmentG_DDR |= _BV(SegmentG_BIT)
#define SegmentG_IsOutput()                      ((SegmentG_DDR & _BV(SegmentG_BIT)) != 0)
#define SegmentG_SetHIGH()                       SegmentG_PORT |= _BV(SegmentG_BIT)
#define SegmentG_SetLOW()                        SegmentG_PORT &= ~_BV(SegmentG_BIT)
#define SegmentG_Get()                           (SegmentG_PIN & _BV(SegmentG_BIT))
#define SegmentG_SetInactive()                   SegmentG_SetHIGH()
#define SegmentG_SetActive()                     SegmentG_SetLOW()
#define SegmentG_Toggle()                        SegmentG_PORT ^= _BV(SegmentG_BIT)
#define SegmentG_SetConditional(condition)       if (condition) SegmentG_SetActive(); else SegmentG_SetInactive()
#define SegmentG_SetConditionalToggle(conditionon, conditionoff, conditiontoggle) if (conditionon) { SegmentG_SetActive(); } else if (conditionoff) { SegmentG_SetInactive(); } else if (conditiontoggle) { SegmentG_Toggle(); }
#define SegmentG_Pulse()                         { SegmentG_SetActive(); SegmentG_SetInactive(); }
#define SegmentG_PulseNop()                      { SegmentG_SetActive(); nop(); SegmentG_SetInactive(); }
#define SegmentG_IsInactive()                    (SegmentG_Get() != 0)
#define SegmentG_IsActive()                      (SegmentG_Get() == 0)
#define SegmentG_Init()                          { SegmentG_SetInactive(); SegmentG_ModeOutput(); }

/* SegmentF -> PD5 (Output, Initially Inactive, Active-Low) */
#define SegmentF_BIT                             5
#define SegmentF_PIN                             PIND
#define SegmentF_PORT                            PORTD
#define SegmentF_DDR                             DDRD
#define SegmentF_ModeOutput()                    SegmentF_DDR |= _BV(SegmentF_BIT)
#define SegmentF_IsOutput()                      ((SegmentF_DDR & _BV(SegmentF_BIT)) != 0)
#define SegmentF_SetHIGH()                       SegmentF_PORT |= _BV(SegmentF_BIT)
#define SegmentF_SetLOW()                        SegmentF_PORT &= ~_BV(SegmentF_BIT)
#define SegmentF_Get()                           (SegmentF_PIN & _BV(SegmentF_BIT))
#define SegmentF_SetInactive()                   SegmentF_SetHIGH()
#define SegmentF_SetActive()                     SegmentF_SetLOW()
#define SegmentF_Toggle()                        SegmentF_PORT ^= _BV(SegmentF_BIT)
#define SegmentF_SetConditional(condition)       if (condition) SegmentF_SetActive(); else SegmentF_SetInactive()
#define SegmentF_SetConditionalToggle(conditionon, conditionoff, conditiontoggle) if (conditionon) { SegmentF_SetActive(); } else if (conditionoff) { SegmentF_SetInactive(); } else if (conditiontoggle) { SegmentF_Toggle(); }
#define SegmentF_Pulse()                         { SegmentF_SetActive(); SegmentF_SetInactive(); }
#define SegmentF_PulseNop()                      { SegmentF_SetActive(); nop(); SegmentF_SetInactive(); }
#define SegmentF_IsInactive()                    (SegmentF_Get() != 0)
#define SegmentF_IsActive()                      (SegmentF_Get() == 0)
#define SegmentF_Init()                          { SegmentF_SetInactive(); SegmentF_ModeOutput(); }

/* SegmentDot -> PB1 (Output, Initially Inactive, Active-Low) */
#define SegmentDot_BIT                           1
#define SegmentDot_PIN                           PINB
#define SegmentDot_PORT                          PORTB
#define SegmentDot_DDR                           DDRB
#define SegmentDot_ModeOutput()                  SegmentDot_DDR |= _BV(SegmentDot_BIT)
#define SegmentDot_IsOutput()                    ((SegmentDot_DDR & _BV(SegmentDot_BIT)) != 0)
#define SegmentDot_SetHIGH()                     SegmentDot_PORT |= _BV(SegmentDot_BIT)
#define SegmentDot_SetLOW()                      SegmentDot_PORT &= ~_BV(SegmentDot_BIT)
#define SegmentDot_Get()                         (SegmentDot_PIN & _BV(SegmentDot_BIT))
#define SegmentDot_SetInactive()                 SegmentDot_SetHIGH()
#define SegmentDot_SetActive()                   SegmentDot_SetLOW()
#define SegmentDot_Toggle()                      SegmentDot_PORT ^= _BV(SegmentDot_BIT)
#define SegmentDot_SetConditional(condition)     if (condition) SegmentDot_SetActive(); else SegmentDot_SetInactive()
#define SegmentDot_SetConditionalToggle(conditionon, conditionoff, conditiontoggle) if (conditionon) { SegmentDot_SetActive(); } else if (conditionoff) { SegmentDot_SetInactive(); } else if (conditiontoggle) { SegmentDot_Toggle(); }
#define SegmentDot_Pulse()                       { SegmentDot_SetActive(); SegmentDot_SetInactive(); }
#define SegmentDot_PulseNop()                    { SegmentDot_SetActive(); nop(); SegmentDot_SetInactive(); }
#define SegmentDot_IsInactive()                  (SegmentDot_Get() != 0)
#define SegmentDot_IsActive()                    (SegmentDot_Get() == 0)
#define SegmentDot_Init()                        { SegmentDot_SetInactive(); SegmentDot_ModeOutput(); }

/* SegmentA -> PB2 (Output, Initially Inactive, Active-Low) */
#define SegmentA_BIT                             2
#define SegmentA_PIN                             PINB
#define SegmentA_PORT                            PORTB
#define SegmentA_DDR                             DDRB
#define SegmentA_ModeOutput()                    SegmentA_DDR |= _BV(SegmentA_BIT)
#define SegmentA_IsOutput()                      ((SegmentA_DDR & _BV(SegmentA_BIT)) != 0)
#define SegmentA_SetHIGH()                       SegmentA_PORT |= _BV(SegmentA_BIT)
#define SegmentA_SetLOW()                        SegmentA_PORT &= ~_BV(SegmentA_BIT)
#define SegmentA_Get()                           (SegmentA_PIN & _BV(SegmentA_BIT))
#define SegmentA_SetInactive()                   SegmentA_SetHIGH()
#define SegmentA_SetActive()                     SegmentA_SetLOW()
#define SegmentA_Toggle()                        SegmentA_PORT ^= _BV(SegmentA_BIT)
#define SegmentA_SetConditional(condition)       if (condition) SegmentA_SetActive(); else SegmentA_SetInactive()
#define SegmentA_SetConditionalToggle(conditionon, conditionoff, conditiontoggle) if (conditionon) { SegmentA_SetActive(); } else if (conditionoff) { SegmentA_SetInactive(); } else if (conditiontoggle) { SegmentA_Toggle(); }
#define SegmentA_Pulse()                         { SegmentA_SetActive(); SegmentA_SetInactive(); }
#define SegmentA_PulseNop()                      { SegmentA_SetActive(); nop(); SegmentA_SetInactive(); }
#define SegmentA_IsInactive()                    (SegmentA_Get() != 0)
#define SegmentA_IsActive()                      (SegmentA_Get() == 0)
#define SegmentA_Init()                          { SegmentA_SetInactive(); SegmentA_ModeOutput(); }

/* SegmentB -> PC0 (Output, Initially Inactive, Active-Low) */
#define SegmentB_BIT                             0
#define SegmentB_PIN                             PINC
#define SegmentB_PORT                            PORTC
#define SegmentB_DDR                             DDRC
#define SegmentB_ModeOutput()                    SegmentB_DDR |= _BV(SegmentB_BIT)
#define SegmentB_IsOutput()                      ((SegmentB_DDR & _BV(SegmentB_BIT)) != 0)
#define SegmentB_SetHIGH()                       SegmentB_PORT |= _BV(SegmentB_BIT)
#define SegmentB_SetLOW()                        SegmentB_PORT &= ~_BV(SegmentB_BIT)
#define SegmentB_Get()                           (SegmentB_PIN & _BV(SegmentB_BIT))
#define SegmentB_SetInactive()                   SegmentB_SetHIGH()
#define SegmentB_SetActive()                     SegmentB_SetLOW()
#define SegmentB_Toggle()                        SegmentB_PORT ^= _BV(SegmentB_BIT)
#define SegmentB_SetConditional(condition)       if (condition) SegmentB_SetActive(); else SegmentB_SetInactive()
#define SegmentB_SetConditionalToggle(conditionon, conditionoff, conditiontoggle) if (conditionon) { SegmentB_SetActive(); } else if (conditionoff) { SegmentB_SetInactive(); } else if (conditiontoggle) { SegmentB_Toggle(); }
#define SegmentB_Pulse()                         { SegmentB_SetActive(); SegmentB_SetInactive(); }
#define SegmentB_PulseNop()                      { SegmentB_SetActive(); nop(); SegmentB_SetInactive(); }
#define SegmentB_IsInactive()                    (SegmentB_Get() != 0)
#define SegmentB_IsActive()                      (SegmentB_Get() == 0)
#define SegmentB_Init()                          { SegmentB_SetInactive(); SegmentB_ModeOutput(); }

/* SwitchOuter -> PC5 (Input, Initially Pullup On, Active-Low) */
#define SwitchOuter_BIT                          5
#define SwitchOuter_PIN                          PINC
#define SwitchOuter_PORT                         PORTC
#define SwitchOuter_DDR                          DDRC
#define SwitchOuter_SetPullupActive()            SwitchOuter_PORT |= _BV(SwitchOuter_BIT)
#define SwitchOuter_SetPullupInactive()          SwitchOuter_PORT &= ~_BV(SwitchOuter_BIT)
#define SwitchOuter_ModeInput()                  SwitchOuter_DDR &= ~_BV(SwitchOuter_BIT)
#define SwitchOuter_IsInput()                    ((SwitchOuter_DDR & _BV(SwitchOuter_BIT)) == 0)
#define SwitchOuter_Get()                        (SwitchOuter_PIN & _BV(SwitchOuter_BIT))
#define SwitchOuter_GetBit()                     (SwitchOuter_Get() >> SwitchOuter_BIT)
#define SwitchOuter_IsInactive()                 (SwitchOuter_Get() != 0)
#define SwitchOuter_IsActive()                   (SwitchOuter_Get() == 0)
#define SwitchOuter_Init()                       { SwitchOuter_SetPullupActive(); SwitchOuter_ModeInput(); }

/* SwitchInner -> PC4 (Input, Initially Pullup On, Active-Low) */
#define SwitchInner_BIT                          4
#define SwitchInner_PIN                          PINC
#define SwitchInner_PORT                         PORTC
#define SwitchInner_DDR                          DDRC
#define SwitchInner_SetPullupActive()            SwitchInner_PORT |= _BV(SwitchInner_BIT)
#define SwitchInner_SetPullupInactive()          SwitchInner_PORT &= ~_BV(SwitchInner_BIT)
#define SwitchInner_ModeInput()                  SwitchInner_DDR &= ~_BV(SwitchInner_BIT)
#define SwitchInner_IsInput()                    ((SwitchInner_DDR & _BV(SwitchInner_BIT)) == 0)
#define SwitchInner_Get()                        (SwitchInner_PIN & _BV(SwitchInner_BIT))
#define SwitchInner_GetBit()                     (SwitchInner_Get() >> SwitchInner_BIT)
#define SwitchInner_IsInactive()                 (SwitchInner_Get() != 0)
#define SwitchInner_IsActive()                   (SwitchInner_Get() == 0)
#define SwitchInner_Init()                       { SwitchInner_SetPullupActive(); SwitchInner_ModeInput(); }

/* SwitchExternal -> PC3 (Input, Initially Pullup On, Active-Low) */
#define SwitchExternal_BIT                       3
#define SwitchExternal_PIN                       PINC
#define SwitchExternal_PORT                      PORTC
#define SwitchExternal_DDR                       DDRC
#define SwitchExternal_SetPullupActive()         SwitchExternal_PORT |= _BV(SwitchExternal_BIT)
#define SwitchExternal_SetPullupInactive()       SwitchExternal_PORT &= ~_BV(SwitchExternal_BIT)
#define SwitchExternal_ModeInput()               SwitchExternal_DDR &= ~_BV(SwitchExternal_BIT)
#define SwitchExternal_IsInput()                 ((SwitchExternal_DDR & _BV(SwitchExternal_BIT)) == 0)
#define SwitchExternal_Get()                     (SwitchExternal_PIN & _BV(SwitchExternal_BIT))
#define SwitchExternal_GetBit()                  (SwitchExternal_Get() >> SwitchExternal_BIT)
#define SwitchExternal_IsInactive()              (SwitchExternal_Get() != 0)
#define SwitchExternal_IsActive()                (SwitchExternal_Get() == 0)
#define SwitchExternal_Init()                    { SwitchExternal_SetPullupActive(); SwitchExternal_ModeInput(); }

#define initHAL() {\
		Digit4_Init();\
		SegmentD_Init();\
		SegmentC_Init();\
		Digit3_Init();\
		Digit2_Init();\
		Digit1_Init();\
		SegmentE_Init();\
		SegmentG_Init();\
		SegmentF_Init();\
		SegmentDot_Init();\
		SegmentA_Init();\
		SegmentB_Init();\
		SwitchOuter_Init();\
		SwitchInner_Init();\
		SwitchExternal_Init();\
}

#endif
