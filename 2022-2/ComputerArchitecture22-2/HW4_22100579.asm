.data
str:
   .asciiz "Sum of multiples of 3 is "
debug:
    .asciiz " is added.\n"
.text
  main:	
    add $t0, $zero, $zero  #sum = 0
  	addi $t1, $zero, 1 #i = 1
    addi $t3, $zero, 3 #t3 = 3
    #addi $s0, $zero, 15 #test

  loop:	
    div $t1, $t3 #hi = i%3
    mfhi $t2 #t2 = hi
    bne $t2, $zero, skip #if(t2 != 0) goto skip

    add $t0, $t0, $t1 #sum += i

    #debug
    
    #li $v0, 1
    #add $a0, $t1, $zero
    #syscall

    #li $v0, 4
    #la $a0, debug
    #syscall


  skip:
    addi $t1, $t1, 1 #i++
    slt $t2, $s0, $t1 #for statement
    beq $t2, $zero, loop

    li $v0, 4
    la $a0, str
    syscall

    li $v0, 1
    add $a0, $t0, $zero
    syscall

  exit: 
.end