;
; Practica02.asm
;
; Created: 03/10/2024 11:25:35 a. m.
; Author : Madris
;


start:
ldi r16, 0x00 ; Se carga B Hexadecimal 0000 0000
ldi r17, 0xff ; Se carga B Hexadecimal 1111 1111

out ddrb, r16 ; Se configura el puerto B como entrada
out ddrd, r17 ; Se configura el puerto D como salida

out portb, r17 ; Se activa el Pull-up
out portd, r16 ; Limpia las salidas

fin:
in r18, pinb  ; Ingresa los datos del puerto B al registro r18
out portd, r18 ; Nods muestra lo que esta en el r18 por el puerto D
rjmp fin ; Salto hacia el ciclo  
