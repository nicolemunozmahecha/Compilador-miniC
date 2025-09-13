
###########################
# Seccion de datos
	.data

_a:
	.word 0
_b:
	.word 0
_e56:
	.word 0
_y:
	.word 0
_c:
	.word 0
_z:
	.word 0
$str1:
	.asciiz "Comienza \t  simulación \\ junio 2025\n"
$str2:
	.asciiz "Esto no va bien con a*1000="
$str3:
	.asciiz "\n"
$str4:
	.asciiz "Esto no va bien con b-1=\n"
$str5:
	.asciiz "Introduce valores de 'y' y 'z' 3 veces\n"
$str6:
	.asciiz "e56="
$str7:
	.asciiz ", y="
$str8:
	.asciiz ", z="
$str9:
	.asciiz "\n"
$str10:
	.asciiz "Termina correctamente con e56="
$str11:
	.asciiz "\n"
$str12:
	.asciiz "-----------------------"
$str13:
	.asciiz "\n"
$str14:
	.asciiz "Expresion triple a 1: ------------"
$str15:
	.asciiz "-----------\n"

###########################
# Seccion de código
	.text
	.globl main

main:
	li	$t0,   0
	sw	$t0,   _a
	li	$t0,   1
	sw	$t0,   _b
	li	$t0,   10
	sw	$t0,   _c
	lw	$t0,   _a
	lw	$t1,   _b
	li	$t2,   20
	mul	$t3,   $t1,   $t2
	add	$t1,   $t0,   $t3
	lw	$t0,   _b
	li	$t2,   19
	li	$t3,   2
	div	$t4,   $t2,   $t3
	add	$t2,   $t0,   $t4
	sub	$t0,   $t1,   $t2
	li	$t1,   2
	div	$t2,   $t0,   $t1
	sw	$t2,   _e56
	la	$a0,   $str1 
	li	$v0,   4
	syscall
	lw	$t0,   _a
	li	$t1,   1000
	mul	$t2,   $t0,   $t1
	beqz	$t2,   $l1 
	la	$a0,   $str2 
	li	$v0,   4
	syscall
	lw	$t0,   _a
	li	$t1,   1000
	mul	$t3,   $t0,   $t1
	move	$a0,   $t3
	li	$v0,   1
	syscall
	la	$a0,   $str3 
	li	$v0,   4
	syscall
$l1: 
	lw	$t0,   _b
	li	$t1,   1
	sub	$t2,   $t0,   $t1
	beqz	$t2,   $l4 
	la	$a0,   $str4 
	li	$v0,   4
	syscall
	lw	$t0,   _b
	li	$t1,   1
	sub	$t3,   $t0,   $t1
	move	$a0,   $t3
	li	$v0,   1
	syscall
	b	$l5 
$l4: 
$l2: 
	lw	$t0,   _e56
	li	$t1,   2
	sub	$t3,   $t0,   $t1
	beqz	$t3,   $l3 
	lw	$t0,   _e56
	li	$t1,   1
	sub	$t4,   $t0,   $t1
	sw	$t4,   _e56
	la	$a0,   $str5 
	li	$v0,   4
	syscall
	li	$v0,   5
	syscall
	sw	$v0,   _y
	li	$v0,   5
	syscall
	sw	$v0,   _z
	la	$a0,   $str6 
	li	$v0,   4
	syscall
	lw	$t0,   _e56
	move	$a0,   $t0
	li	$v0,   1
	syscall
	la	$a0,   $str7 
	li	$v0,   4
	syscall
	lw	$t0,   _y
	li	$t1,   0
	add	$t4,   $t0,   $t1
	li	$t0,   1
	div	$t1,   $t4,   $t0
	move	$a0,   $t1
	li	$v0,   1
	syscall
	la	$a0,   $str8 
	li	$v0,   4
	syscall
	lw	$t0,   _z
	li	$t1,   0
	sub	$t4,   $t0,   $t1
	li	$t0,   1
	mul	$t1,   $t4,   $t0
	move	$a0,   $t1
	li	$v0,   1
	syscall
	la	$a0,   $str9 
	li	$v0,   4
	syscall
	b	$l2 
$l3: 
$l5: 
	la	$a0,   $str10 
	li	$v0,   4
	syscall
	lw	$t0,   _e56
	move	$a0,   $t0
	li	$v0,   1
	syscall
	la	$a0,   $str11 
	li	$v0,   4
	syscall
	la	$a0,   $str12 
	li	$v0,   4
	syscall
	la	$a0,   $str13 
	li	$v0,   4
	syscall
	la	$a0,   $str14 
	li	$v0,   4
	syscall
	lw	$t0,   _e56
	beqz	$t0,   $l6 
	li	$t1,   1
	move	$t3,   $t1
	b	$l7 
$l6: 
	li	$t2,   0
	move	$t3,   $t2
$l7: 
	move	$a0,   $t3
	li	$v0,   1
	syscall
	la	$a0,   $str15 
	li	$v0,   4
	syscall

###########################
# Fin
	li	$v0,   10
	syscall
