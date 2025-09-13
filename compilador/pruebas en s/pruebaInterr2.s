
###########################
# Seccion de datos
	.data

_c:
	.word 0
_a:
	.word 0
$str1:
	.asciiz "c="

###########################
# Seccion de código
	.text
	.globl main

main:
	li	$t0,   0
	sw	$t0,   _a
	lw	$t0,   _a
	beqz	$t0,   $l1 
	li	$t1,   1
	move	$t3,   $t1
	b	$l2 
$l1: 
	li	$t2,   2
	move	$t3,   $t2
$l2: 
	sw	$t3,   _c
	la	$a0,   $str1 
	li	$v0,   4
	syscall
	lw	$t3,   _c
	move	$a0,   $t3
	li	$v0,   1
	syscall

###########################
# Fin
	li	$v0,   10
	syscall
