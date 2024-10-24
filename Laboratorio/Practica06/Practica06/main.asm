;
; Practica06.asm
;
; Created: 24/10/2024 11:17:48 a. m.
; Author : Madris
;


RJMP INICIO

.ORG 0x002
RJMP RSI_INTO

INICIO:
    SEI
    LDI R16, 0xFF
    LDI R17, 0x02
    OUT SPL, R16
    OUT SPH, R17
    LDI R18, 0x00
    OUT DDRB, R16
    LDI R19, 0x01
    LDI R20, 0x03
    OUT EIMSK, R19
    STS EICRA, R20
FIN:
    RJMP FIN
RSI_INTO:
    INC R18
    OUT PORTB, R18
    RETI