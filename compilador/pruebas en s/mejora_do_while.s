
###########################
# Seccion de datos
	.data

_x:
	.word 0
_d:
	.word 0
_a:
	.word 0
$str1:
	.asciiz "x = "
$str2:
	.asciiz "\nFin do while"

###########################
# Seccion de código
	.text
	.globl main

main:
	li	$t0,   5
	sw	$t0,   _a
	li	$t0,   4
	sw	$t0,   _d
$l1: 
	lw	$t0,   _a
	li	$t1,   2
	add	$t2,   $t0,   $t1
	sw	$t2,   _x
	lw	$t0,   _d
	li	$t1,   2
	sub	$t2,   $t0,   $t1
	li	$t0,   1
	add	$t1,   $t2,   $t0
	sw	$t1,   _d
	lw	$t0,   _d
	beqz	$t0,   $l2 
	b	$l1 
$l2: 
	la	$a0,   $str1 
	li	$v0,   4
	syscall
	lw	$t0,   _x
	move	$a0,   $t0
	li	$v0,   1
	syscall
	la	$a0,   $str2 
	li	$v0,   4
	syscall

###########################
# Fin
	li	$v0,   10
	syscall
