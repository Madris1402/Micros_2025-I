;
; Practica05.asm
;
; Created: 17/10/2024 11:05:23 a. m.
; Author : Madris
;

	LDI R16, 0XFF    ; metemos 8 bits en r16 (1111 1111)
	OUT DDRB, R16    ; programamos como salida (B)

	LDI R16, 0X55    ; iniciando cuenta 0x55
	OUT PORTB, R16   ; nos muestra por puerto B lo que este en r16
	CUENTA:

	RCALL RETARDO

INC R16         ; hace el incremento de cuenta (0X56)
	OUT PORTB, R16  ; sale por r16
	RJMP CUENTA     ; salto a cuenta para que se haga el ciclo

	; EMPIEZA RETARDO
RETARDO:
	LDI R17, 0X00
	LDI R18, 0X00
	LDI R19, 0X00
	LDI R20, 0X04
	LDI R21, 0X00

	INCREMENTO:
	INC R17
	CPSE R17, R21
	RJMP INCREMENTO
	INC R18
	CPSE R18, R21
	RJMP INCREMENTO
	INC R19
	CPSE R19, R20
	RJMP INCREMENTO
	RET ; FIN DE LA SUBRUTINA
	; FIN DEL RETARDO