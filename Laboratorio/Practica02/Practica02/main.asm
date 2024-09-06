;
; Practica02.asm
;
; Created: 04/09/2024 22:58:05
; Author : madris
;


; Replace with your application code
start:
    LDI r16, 0x00 ;se carga en hexadecimal 0000 0000
	LDI r17, 0xff ;se carga en hexadecimal 1111 1111

	OUT DDRD, r16 ;se configura puerto D como entrada
	OUT DDRB, r17 ;se configura puerto B como salida

	OUT PORTD, r17	;activa pull-up puerto D
	OUT PORTB, r16	;activa salida puerto B
	
	loop:


	IN r18,PIND ;ingresa los datos de puerto D al r18
	OUT PORTB, r18 ;escribe los datos del r18 al puerto B
	RJMP loop
