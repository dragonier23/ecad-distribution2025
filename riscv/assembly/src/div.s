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
    beq  a1, x0, .div_by_zero   # if denominator == 0
    
    li t0, 0 # Q, alternatively, addi t0, x0, 0
    li t1, 0 # R
    li t2, 31 
.loop: 
    blt t2, zero, .exit  
    
    slli t1, t1, 1 
    
    srl t5, a0, t2
    andi t5, t5, 1  
    
    or t1, t1, t5  
    
    bltu t1, a1, .dec
    
    sub t1, t1, a1 
    
    li t3, 1 
    sll t3, t3, t2
    or t0, t0, t3

.dec: 
    addi t2, t2, -1
    j .loop
    
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

.div_by_zero:
    li   a0, 0
    li   a1, 0
    lw   ra, 28(sp)
    lw   s0, 24(sp)
    addi sp, sp, 32
    ret



