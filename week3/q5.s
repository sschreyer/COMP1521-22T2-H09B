# read 10 numbers into an array
# i in register $t0
main:

	li 	$t0, 0 		# int i = 0;
main__scan_loop:
    	bge 	$t0, 10, main__end

	li	$v0, 5
    	syscall 		# scanf("%d", &numbers[i]);

	la 	$t1, numbers	# calculate &numbers[i]
	mul 	$t2, $t0, 4
	add 	$t3, $t1, $t2 
	sw 	$v0, ($t3)	# store scanned value in numbers[i]

	add 	$t0, $t0, 1	# i++;
	b 	main__scan_loop
main__end:
	jr 	$ra


    .data
numbers: 
    .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0	# int numbers[10] = {0};	
