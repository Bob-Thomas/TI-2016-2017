	.file	"main.cpp"
	.text
	.globl	put_char
	.type	put_char, @function
put_char:
.LFB0:
	.cfi_startproc
	rep ret
	.cfi_endproc
.LFE0:
	.size	put_char, .-put_char
	.globl	convert
	.type	convert, @function
convert:
.LFB1:
	.cfi_startproc
	leal	-65(%rdi), %eax
	cmpb	$25, %al
	ja	.L3
	leal	32(%rdi), %eax
	ret
.L3:
	leal	-97(%rdi), %edx
	leal	-32(%rdi), %eax
	cmpb	$25, %dl
	cmova	%edi, %eax
	ret
	.cfi_endproc
.LFE1:
	.size	convert, .-convert
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Debian 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",@progbits
