;
; Practica01.asm
;
; Created: 26/08/2024 08:51:32 a. m.
; Author : Madris
;


; Replace with your application code
start:

	ldi r16,0xff
	ldi r17, 0xca
	
	out ddrd, r16
	out portd, r17
	fin: rjmp fin

