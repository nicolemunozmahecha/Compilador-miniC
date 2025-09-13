
###########################
# Seccion de datos
	.data

_a:
	.word 0
_b:
	.word 0
_e56:
	.word 0
_y:
	.word 0
_c:
	.word 0
$str1:
	.asciiz "e56: "

###########################
# Seccion de código
	.text
	.globl main

main:
	li	$t0,   0
	sw	$t0,   _a
	li	$t0,   1
	sw	$t0,   _b
	li	$t0,   10
	sw	$t0,   _c
	lw	$t0,   _a
	lw	$t1,   _b
	li	$t2,   20
	mul	$t3,   $t1,   $t2
	add	$t1,   $t0,   $t3
	lw	$t0,   _b
	li	$t2,   19
	li	$t3,   2
	div	$t4,   $t2,   $t3
	add	$t2,   $t0,   $t4
	sub	$t0,   $t1,   $t2
	li	$t1,   2
	div	$t2,   $t0,   $t1
	sw	$t2,   _e56
	la	$a0,   $str1 
	li	$v0,   4
	syscall
	lw	$t0,   _e56
	move	$a0,   $t0
	li	$v0,   1
	syscall

###########################
# Fin
	li	$v0,   10
	syscall
