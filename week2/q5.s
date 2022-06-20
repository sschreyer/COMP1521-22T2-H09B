main: 
	la	$a0, input_str
	li	$v0, 4
	syscall 			# printf("Enter a number: ");

	li 	$v0, 5
	syscall 
	move 	$t0, $v0 		# scanf("%d", &x);

	ble 	$t0, 46340, square	# if (x <= 46340) goto square;

	la 	$a0, square_too_big
	li 	$v0, 4 
	syscall 			# printf("square too big for 32 bits\n");

	b 	end

square: 
	mul 	$t1, $t0, $t0 		# y = x * x;

	move 	$a0, $t1 		# printf("%d", y);
	li 	$v0, 1 
	syscall 

	li 	$a0, '\n'
	li 	$v0, 11
	syscall 			# printf("\n");

end: 	li 	$v0, 0
	jr 	$ra			# return 0;


    	.data 
input_str:
   	 .asciiz "Enter a number: "
square_too_big:
	.asciiz "square too big for 32 bits\n"