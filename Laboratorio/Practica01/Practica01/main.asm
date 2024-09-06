;
; Practica01.asm
;
; Created: 05/09/2024 11:27 a.m.
; Author : Madris
;


; Replace with your application code
start:

	ldi r16,0xff ; se introduce la constante 0xff b 1111 1111 al r16.
	ldi r17, 0xca ; se introduce la constante 0xaa b 1010 1010 al r17.
	
	out ddrd, r16 ;  programamos el puerto d como salida.
	out portd, r17 ; mostramos lo que esté en el registro 17 en el puerto D
	fin: rjmp fin ; salto al fin, es un ciclo.