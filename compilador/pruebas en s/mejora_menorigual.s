
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
	.asciiz "b: "
$str2:
	.asciiz " a: "
$str3:
	.asciiz "\nx = "
$str4:
	.asciiz "\nfin codigo"

###########################
# Seccion de código
	.text
	.globl main

main:
	li	$t0,   7
	sw	$t0,   _a
	li	$t0,   5
	sw	$t0,   _b
	la	$a0,   $str1 
	li	$v0,   4
	syscall
	lw	$t0,   _b
	move	$a0,   $t0
	li	$v0,   1
	syscall
	la	$a0,   $str2 
	li	$v0,   4
	syscall
	lw	$t0,   _a
	move	$a0,   $t0
	li	$v0,   1
	syscall
	lw	$t0,   _b
	lw	$t1,   _a
	slt	$t2,   $t0,   $t1
	xor	$t0,   $t2,   1
	beqz	$t2,   $l1 
	li	$t1,   8
	sw	$t1,   _x
	b	$l2 
$l1: 
	li	$t1,   4
	sw	$t1,   _x
$l2: 
	la	$a0,   $str3 
	li	$v0,   4
	syscall
	lw	$t1,   _x
	move	$a0,   $t1
	li	$v0,   1
	syscall
	la	$a0,   $str4 
	li	$v0,   4
	syscall

###########################
# Fin
	li	$v0,   10
	syscall
