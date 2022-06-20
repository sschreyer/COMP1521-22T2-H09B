main:
	li 	$t0, 24	# int x = 24; 
main__loop:
	bge 	$t0, 42, main__end	# if (x >= 42) goto end;

	move 	$a0, $t0 
	li 	$v0, 1 
	syscall 			# printf("%d", x);

	li 	$a0, '\n'
	li 	$v0, 11
	syscall 			# printf("\n");

	add 	$t0, $t0, 3		# x += 3;
	b 	main__loop

main__end:
	li 	$v0, 0
	jr 	$ra 			# return 0;