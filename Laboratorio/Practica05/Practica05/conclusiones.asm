/*
 * conclusiones.asm
 *
 *  Created: 23/10/2024 22:00:00
 *   Author: madris
 */


LDI R16, 0XFF ; iniciamos la cuenta en 255 (0xFF)
OUT DDRB, R16 ; programamos el puerto B como salida

CUENTA:
	OUT PORTB, R16 ; mostramos el valor en el puerto B
	RCALL RETARDO ; llamamos al retardo

	SUBI R16, 2 ; decrementamos de 2 en 2
	BRPL CUENTA ; seguimos si R16 es positivo o cero

	RJMP CUENTA ; salto para seguir el ciclo

; EMPIEZA RETARDO
RETARDO:
	LDI R17, 0X00
	LDI R18, 0X00
	LDI R19, 0X00
	LDI R20, 0X04 ; ajuste del retardo, puedes cambiar el valor
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
	RET ; fin de la subrutina
	; FIN DEL RETARDO