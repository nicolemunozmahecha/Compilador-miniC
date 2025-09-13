
###########################
# Seccion de datos
	.data

_a:
	.word 0
_b:
	.word 0
$str1:
	.asciiz "a = "
$str2:
	.asciiz "\nb = "
$str3:
	.asciiz "\n SON IGUALES"
$str4:
	.asciiz "\nNO SON IGUALES : \na = "
$str5:
	.asciiz "\nb = "

###########################
# Seccion de código
	.text
	.globl main

main:
	li	$t0,   2
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
	lw	$t0,   _a
	lw	$t1,   _b
	xor	$t2,   $t0,   $t1
	sltiu	$t0,   $t2,   1
	beqz	$t0,   $l1 
	la	$a0,   $str3 
	li	$v0,   4
	syscall
	b	$l2 
$l1: 
	la	$a0,   $str4 
	li	$v0,   4
	syscall
	lw	$t1,   _a
	move	$a0,   $t1
	li	$v0,   1
	syscall
	la	$a0,   $str5 
	li	$v0,   4
	syscall
	lw	$t1,   _b
	move	$a0,   $t1
	li	$v0,   1
	syscall
$l2: 

###########################
# Fin
	li	$v0,   10
	syscall
