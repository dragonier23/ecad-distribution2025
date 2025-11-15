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
    
    li t0, 0 # Q, alternatively, addi t0, x0, 0
    li t1, 0 # R
    mv t2, a0 # loop counter alternatively, we might just keep shifting right, until equal to 0? 
.loop: 
    blt t2, 0, .exit  
    slli t1, t1, 1 
    srli t5, a0, t2
    ori t5, t5, 1  
    or t1, t1, t5  
    blt t1, a1, loop 
    sub t1, t1, a1 
    li t3, 1 
    slli t3, t3, t2
    or t0, t0, t3
.exit: 
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




