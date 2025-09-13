
###########################
# Seccion de datos
	.data

_a:
	.word 0
_b:
	.word 0
_c:
	.word 0
$str1:
	.asciiz "c = "

###########################
# Seccion de código
	.text
	.globl main

main:
	li	$t0,   1
	sw	$t0,   _a
	li	$t0,   0
	sw	$t0,   _b
	lw	$t0,   _a
	beqz	$t0,   $l1 
	lw	$t1,   _b
	lw	$t2,   _a
	add	$t3,   $t1,   $t2
	sw	$t3,   _c
	b	$l2 
$l1: 
	li	$t1,   0
	sw	$t1,   _c
$l2: 
	la	$a0,   $str1 
	li	$v0,   4
	syscall
	lw	$t0,   _c
	move	$a0,   $t0
	li	$v0,   1
	syscall

###########################
# Fin
	li	$v0,   10
	syscall
