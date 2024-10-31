.section .text
.globl draw
.type draw, @function
draw:
	li a0,5
	li a1,5
	li a2,100
	li a3,50
	li a4,65535
	addi sp,sp,-4
	sw ra,0(sp)
	jal LCD_DrawRectangle
	lw ra,0(sp)
	addi sp,sp,4
	ret
