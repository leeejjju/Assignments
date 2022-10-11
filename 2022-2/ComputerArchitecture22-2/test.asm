.text
.global main
  main:	
  	addi $s0, $zero, 0
   	addi $t0, $zero, 0
	addi $t1, $zero, 10
  loop:	
  	slt $t8, $t0, $t1
	beq $t8, $zero, exit
  	addi $t0, $t0, 1
	add $s0, $s0, $t0
	j loop
  exit: 
.end