
###########################
# Seccion de datos
	.data

_c:
	.word 0
$str1:
	.asciiz "c ="
$str2:
	.asciiz "\n"
$str3:
	.asciiz "Final"
$str4:
	.asciiz "\n"

###########################
# Seccion de código
	.text
	.globl main

main:
	li	$t0,   5
	sw	$t0,   _c
$l1: 
	lw	$t0,   _c
	beqz	$t0,   $l2 
	la	$a0,   $str1 
	li	$v0,   4
	syscall
	lw	$t1,   _c
	move	$a0,   $t1
	li	$v0,   1
	syscall
	la	$a0,   $str2 
	li	$v0,   4
	syscall
	lw	$t1,   _c
	li	$t2,   2
	sub	$t3,   $t1,   $t2
	li	$t1,   1
	add	$t2,   $t3,   $t1
	sw	$t2,   _c
	b	$l1 
$l2: 
	la	$a0,   $str3 
	li	$v0,   4
	syscall
	la	$a0,   $str4 
	li	$v0,   4
	syscall

###########################
# Fin
	li	$v0,   10
	syscall
