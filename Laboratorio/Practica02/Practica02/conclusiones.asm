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

	OUT DDRB, r16 ;se configura puerto B como entrada
	OUT DDRD, r17 ;se configura puerto D como salida

	OUT PORTB, r17	;activa pull-up puerto B
	OUT PORTD, r16	;activa salida puerto D
	
	loop:


	IN r18,PINB ;ingresa los datos de puerto B al r18
	OUT PORTD, r18 ;escribe los datos del r18 al puerto D
	RJMP loop
