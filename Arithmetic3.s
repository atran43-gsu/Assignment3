.section .data
	val1: .byte -60 
	val2: .byte 11
	val3: .byte  16
.section .text
.globl  _start
_start:

	ldr r0, =val1		@ move memory address of val1 to r0
	ldrb r1, [r0]		@ load val1 as unsigned 8bit
	ldr r0, =val2		@ move memory address of val2 to r0
	ldrb r2, [r0]		@ load val2 as unsigned 8bit
	ldr  r0, =val3		@ move memory address of val3 to r0
	ldrsb r3, [r0]		@ load val3 as signed 8bit
	adds r4,r2,#3		@ add val2 and 3, store in r4
	adds r4,r4,r3		@ add val3 to r4, store in r4
	subs r4,r4,r1		@ add val1 to r4, store in r4
	
			
	mov r7, #1 	@ Program Termination: exit syscall
	svc #0  	@ Program Termination:wake kernel
.end
