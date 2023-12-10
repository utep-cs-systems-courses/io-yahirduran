	.arch msp430g2553
	.p2align 1, 0
	.text
	.global count
sound:
	cmp #125, count
	jc over
	mov #250, r12
	jmp end		
over:
	mov #1000, r12
	jmp end
end:
	pop r0
