;
; Practica04.asm
;
; Created: 10/10/2024 11:27:36 a. m.
; Author : Madris
;

start:

	LDI R16,0xFF ; metemos 8 bits en r16 (1111 1111)
	OUT DDRB,R16 ; programamos como salida (B)

	LDI R16,0x55 ; iniciando cuenta 0x55 PB
	OUT PORTB,R16 ; nos muestra por puerto B lo que esté en r16

CUENTA:
	; EMPIEZA RETARDO

	LDI R17,0x00 ; A
	LDI R18,0x00 ; B
	LDI R19,0x00 ; C
	LDI R20,0x04 ; COMPARACIÓN CON C
	LDI R21,0x00 ; COMPARACIÓN CON A Y B

INCREMENTO:
	INC R17 ; INCREMENTA R17
	CPSE R17,R21 ; SE COMPARA R17 CON R21
	RJMP INCREMENTO ; REGRESA A INCREMENTO

	INC R18 ; INCREMENTA R18
	CPSE R18,R21 ; SE COMPARA R18 CON R21
	RJMP INCREMENTO ; REGRESA A INCREMENTO

	INC R19 ; INCREMENTA R19
	CPSE R19,R20 ; SE COMPARA R19 CON R20
	RJMP INCREMENTO ; REGRESA A INCREMENTO

	; FIN DEL RETARDO
	INC R16 ; hace el incremento de cuenta (0x56)
	OUT PORTB, R16 ; sale por r16
	RJMP CUENTA ; salto a cuenta para que se haga el ciclo