main:
main__reverse_loop:
	li 	$t0, 1		# i = 0;
	bge 	$t0, 5, main__end # while (i < 5) {

	la 	$t1, numbers 	# calculate &numbers[i];
	mul	$t2, $t0, 4
	add 	$t3, $t1, $t2 
	lw 	$t5, ($t3)	# int x = numbers[i];

	sub 	$t2, $t0, 9	# calc &numbers[9 - i];
	mul 	$t2, $t2, 4 
	add 	$t4, $t1, $t2 
	lw 	$t6, ($t4)	# int y = numbers[9 - i];

	sw 	$t6, ($t3)	#  numbers[i] = y;
	sw 	$t5, ($t4)	#  numbers[9 - i] = x;

	addi 	$t0, 1

main__end:
	jr 	$ra 		

	.data 
numbers:
	.word 0, 1, 2, 3, 4, 5, 6, 7, 8, 9	# int numbers[10] = {0,1,2,3,4,5,6,7,8,9};