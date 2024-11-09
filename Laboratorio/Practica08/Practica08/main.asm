;
; Practica08.asm
;
; Created: 07/11/2024 11:34:40 a. m.
; Author : Madris
;

SBI ddrd, 6
LDI r16, 0x83
LDI r17, 0x05
LDI r18, 0x7F

OUT tccr0a, r16
OUT tccr0b, r17
OUT ocr0a, r18

FIN: rjmp FIN