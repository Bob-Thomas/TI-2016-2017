   .cpu cortex-m0
   .text
   .align 1
   .global	convert
convert:
	MOV R2, #'A'
	SUB R1, R0, R2
	BGE upperZCheck
	b .return
upperZCheck:
	MOV R2, #'Z'
	SUB R1, R0, R2
	BGE lowerACheck
	SUB R0, #('A' - 'a')
	b .return
lowerACheck:
	MOV R2, #'a'
	SUB R1, R0, R2
	BGE lowerZCheck
	b .return
lowerZCheck:
	MOV R2, #'z'
	SUB R1, R0, R2
	BGE .return
	SUB R0, #('a' - 'A')
.return:
	bx lr

@COMPILER SOLUTION
@convert:
@	mov R2, #'A'
@	sub r1, R0, R2
@	cmp r1, #25 
@	bhi .upper
@	add r0, r0, #('a' - 'A')
@	b .return
@.upper:
@	mov R2, #'a'
@	sub r1, R0, r2
@	cmp R1, #25
@	bhi .return
@	sub	r0, r0, #('a' - 'A')
@.return:
@	bx lr
