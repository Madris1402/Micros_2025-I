;
; Practica08.asm
;
; Created: 07/11/2024 11:34:40 a. m.
; Author : Madris
;

sbi ddrd, 6
ldi r16, 0x83
ldi r17, 0x05
ldi r18, 0x7F

out tccr0a, r16
out tccr0b, r17
out ocr0a, r18

fin: rjmp fin