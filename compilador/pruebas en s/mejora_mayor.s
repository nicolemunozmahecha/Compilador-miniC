
###########################
# Seccion de datos
	.data

_x:
	.word 0
_a:
	.word 0
_b:
	.word 0
$str1:
	.asciiz "a: "
$str2:
	.asciiz " b: "
$str3:
	.asciiz "\nx = "
$str4:
	.asciiz "\nfin codigo"

###########################
# Seccion de código
	.text
	.globl main

main:
	li	$t0,   1
	sw	$t0,   _a
	li	$t0,   2
	sw	$t0,   _b
	la	$a0,   $str1 
	li	$v0,   4
	syscall
	lw	$t0,   _a
	move	$a0,   $t0
	li	$v0,   1
	syscall
	la	$a0,   $str2 
	li	$v0,   4
	syscall
	lw	$t0,   _b
	move	$a0,   $t0
	li	$v0,   1
	syscall
	lw	$t1,   _a
	lw	$t0,   _b
	slt	$t2,   $t1,   $t0
	beqz	$t2,   $l1 
	li	$t0,   1
	sw	$t0,   _x
	b	$l2 
$l1: 
	li	$t0,   4
	sw	$t0,   _x
$l2: 
	la	$a0,   $str3 
	li	$v0,   4
	syscall
	lw	$t0,   _x
	move	$a0,   $t0
	li	$v0,   1
	syscall
	la	$a0,   $str4 
	li	$v0,   4
	syscall

###########################
# Fin
	li	$v0,   10
	syscall
