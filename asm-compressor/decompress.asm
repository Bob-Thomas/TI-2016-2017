.cpu cortex-m3
.data
.global decompressed_data
decompressed_data:
.asciz ""
.skip 4096
.text
.align 1
.global decompress

decompress:
	ldr r0, =compressed_data //load compressed
	ldr r1, =decompressed_data //place to dump my buffer
	mov r7, #0

loop:
	ldrb r2, [r0] //put first char in r2

	cmp r2, #'@'
	beq history //start history buffer

	cmp r2, #0 //eof
	beq done

	strb r2, [r1] // store r1 in the bffer

	//print normal characters
	push {r0 - r3} // save
	mov r0, r2
	bl print_char
	pop {r0 - r3} // restore

	//increment registers
	add r0, #1
	add r1, #1 //step forward into the reserved buffer
	add r7, #1 //index
	b loop

history:
	add r0, #1 // go to the offset
	ldrb r3, [r0]  // save offset character
	add r3, #1 // add one to offset

	add r0, #1 // go to length character
	ldrb r4, [r0]  // save length character

	add r0, #1    // take another step
	mov r5, r1 	  // save current data in register

	sub r3, r3, #' ' //extract the actual offset
	sub r4, r4, #' ' //extract the actual length

	sub r5, r5, r3 //step back into the buffer with offset steps

history_loop:
	cmp r4, #0 //length reached
	beq loop   //proceed with them loops
	ldrb r2, [r5]  // load buffer into r2
	strb r2, [r1]  // store buffer into r1

	//print decoded characters
	push {r0 - r3} // save
	mov r0, r2
	bl print_char
	pop {r0 - r3} // restore


	//increment buffers, index and decrement length
	add r5, #1
	add r1, #1
	add r7, #1
	sub r4, #1
	b history_loop // rinse and repeat

done:
	mov pc, lr