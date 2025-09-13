
###########################
# Seccion de datos
	.data

_x:
	.word 0
_a:
	.word 0

###########################
# Seccion de código
	.text
	.globl main

main:
	li	$t0,   1
	sw	$t0,   _a
	lw	$t0,   _a
	li	$t1,   2
	add	$t2,   $t0,   $t1
	beqz	$t2,   $l1 
	li	$t0,   3
	sw	$t0,   _x
$l1: 
	li	$t0,   0
	sw	$t0,   _x

###########################
# Fin
	li	$v0,   10
	syscall
