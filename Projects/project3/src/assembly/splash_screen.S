
.data
string_Flappy: .asciz "Flappy"           
string_Bird: .asciz "Bird"

.section .text
.globl show_splash_screen
.type show_splash_screen, @function


show_splash_screen:
    mv s0, a0                     # s0 = pos
    mv s1, a1                     # s1 = past_pos

# show white
    li t0, 20                     # t0 = 20
    li t1, 3                      # t1 = 3
    mul t2, s0, t1                # t2 = pos * 3
    add t2, t2, t0                # t2 = 20 + pos * 3

    li a0, 15                     
    mv a1, t2                   
    la a2, string_Flappy              
    li a3, 65535                

	addi sp,sp,-4
	sw ra,0(sp)
	jal LCD_ShowString
	lw ra,0(sp)
	addi sp,sp,4

	li a0, 25
	mv a1, t2   
	addi a1, a1, 20
	la a2, string_Bird       
	li a3, 65535  

	addi sp,sp,-4
	sw ra,0(sp)
	jal LCD_ShowString
	lw ra,0(sp)
	addi sp,sp,4

    mv a0, s0                   

    ret                   
