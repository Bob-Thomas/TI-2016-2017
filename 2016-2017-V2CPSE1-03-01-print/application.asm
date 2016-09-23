   .cpu cortex-m0
   .global application
   .align 1
   .text
   hello_str:
   	.asciz "Hello world, the ANSWER is 42!\n"
application:
   ldr r0, =hello_str
   bl print_asciz
