.macro DEBUG_PRINT reg
csrw 0x800, \reg
.endm
	
.text
.global div              # Export the symbol 'div' so we can call it from other files
.type div, @function
div:
    addi sp, sp, -32     # Allocate stack space

    # store any callee-saved register you might overwrite
    sw   ra, 28(sp)      # Function calls would overwrite
    sw   s0, 24(sp)      # If t0-t6 is not enough, can use s0-s11 if I save and restore them
    # ...

    # do your work
    # example of printing inputs a0 and a1
    
    # we let the qoutient and remainder be t0, t1 
    # we further let loop counter be t2 
    beq  a1, zero, .div_by_zero   # if denominator == 0
    
    # intitial initialisation of Q and R 
    li t0, 0 # Q, alternatively, addi t0, x0, 0
    li t1, 0 # R
    li t2, 31 # initialisation of counter
    
.loop: 
    # i < 0
    blt t2, zero, .exit  

    # bit shift R to the left by 1 
    slli t1, t1, 1 
    
    # extract the ith bit from N, and put it in the 0th index  
    srl t5, a0, t2
    andi t5, t5, 1  
    
    # assign the ith bit of N to the LSB of R 
    or t1, t1, t5  
    
    # if D < R, we skip the subtraction stages, and decrement the counter
    bltu t1, a1, .dec
    
    # subtract D from R 
    sub t1, t1, a1 
    
    # create a value with register i being of value 1, and 0s otherwise. Then, assign it to Q (a0)
    li t3, 1 
    sll t3, t3, t2
    or t0, t0, t3

.dec: 

    #decrement counter
    addi t2, t2, -1
    j .loop
    
.exit:
    # store the values in the appropriate registers, then return. 
    mv a0, t0 
    mv a1, t1 
    # DEBUG_PRINT a0
    # DEBUG_PRINT a1

    # load every register you stored above
    lw   ra, 28(sp)
    lw   s0, 24(sp)
    # ...
    addi sp, sp, 32      # Free up stack space
    ret

.div_by_zero:

    # edge case that numerator is 0. 
    li   a0, 0
    li   a1, 0
    lw   ra, 28(sp)
    lw   s0, 24(sp)
    addi sp, sp, 32
    ret



