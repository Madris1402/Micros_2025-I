;
; Practica03.asm
;
; Created: 03/10/2024 11:40:50 a. m.
; Author : Madris
;


start:
	ldi r16, 0xF0 ; cargamos nibles 1111 0000
	ldi r17, 0x0F ; cargamos nibles 0000 1111

	out ddrd, r16 ; cargamos en puerto D r16
	out portd, r17 ; Activamos pull-up yen Nible del 0 al 3

	A:
		in r18, pind ; todo lo que ingresa al puerto D lo pone en r18
		swap r18 ; Invierte los nibles
		or r18, r17 ; mascara, regresa todo al origen

		out portd, r18 ; muestra por el puerto D en el nible 4 a 7 lo que hay en r18
	rjmp A