
###########################
# Seccion de datos
	.data

_a:
	.word 0
_b:
	.word 0
$str1:
	.asciiz "tres = "
$str2:
	.asciiz ", a = "
$str3:
	.asciiz ", b = "

###########################
# Seccion de código
	.text
	.globl main

main:
	li	$t0,   1
	sw	$t0,   _a
	li	$t0,   0
	sw	$t0,   _b
	la	$a0,   $str1 
	li	$v0,   4
	syscall
	lw	$t0,   _a
	li	$t1,   2
	add	$t2,   $t0,   $t1
	move	$a0,   $t2
	li	$v0,   1
	syscall
	la	$a0,   $str2 
	li	$v0,   4
	syscall
	lw	$t0,   _a
	move	$a0,   $t0
	li	$v0,   1
	syscall
	la	$a0,   $str3 
	li	$v0,   4
	syscall
	lw	$t0,   _b
	move	$a0,   $t0
	li	$v0,   1
	syscall

###########################
# Fin
	li	$v0,   10
	syscall
