
###########################
# Seccion de datos
	.data

_x:
	.word 0
_a:
	.word 0
$str1:
	.asciiz "tres = "

###########################
# Seccion de código
	.text
	.globl main

main:
	li	$t0,   1
	sw	$t0,   _a
	la	$a0,   $str1 
	li	$v0,   4
	syscall
	lw	$t0,   _a
	li	$t1,   2
	add	$t2,   $t0,   $t1
	move	$a0,   $t2
	li	$v0,   1
	syscall
	li	$t0,   0
	sw	$t0,   _x

###########################
# Fin
	li	$v0,   10
	syscall
