
###########################
# Seccion de datos
	.data

_x:
	.word 0
_y:
	.word 0

###########################
# Seccion de código
	.text
	.globl main

main:
	li	$v0,   5
	syscall
	sw	$v0,   _x
	li	$v0,   5
	syscall
	sw	$v0,   _y
	li	$t0,   0
	sw	$t0,   _x

###########################
# Fin
	li	$v0,   10
	syscall
