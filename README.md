# miniC → MIPS Compiler  

This project implements a compiler that translates programs written in the **miniC** language into **MIPS assembly code**.  

The translation process includes the following phases:  
1. **Lexical Analysis**  
2. **Syntax Analysis**  
3. **Semantic Analysis**  
4. **Assembly Code Generation**  

---

## 1. Definition of miniC  

The **miniC** language is a simplified version of C with the following restrictions:  

- Only supports **integer constants and variables**.  
- Allows only **integer arithmetic operators**.  
- Does not include **relational or logical operators**.  
- Arithmetic expressions can be used as logical conditions (0 = false, non-zero = true).  
- Does not support function definitions, except for the **main program**.  

---

## 2. MIPS Assembly Code Generation  

The compiler generates assembly code for the **MIPS** architecture using a subset of instructions.  

- The following registers are used:  
  - **t0–t9**  
  - **s0–s7**  

---

## 3. Build and Installation  

### Requirements  

* **Flex**  
* **Bison**  
* **GCC** (or another compiler)  
* **MARS** or **SPIM/QtSPIM** (for running MIPS code)  

### Build Instructions  

```bash
cd Proyecto
make
```  

This will generate the compiler executable named `miniC`.  

---

## 4. Execution and Evaluation  

The compiler takes as input a **miniC** file (`.mc`) and produces a **MIPS assembly** file (`.s`).  

### Running in MIPS  

You can run your file using **MARS** or **QtSPIM**:  

```bash
java -jar Mars.jar programa.s
```  

Example usage:  

```bash
./minic programa.mc > programa.s
```  

Where:  
- `programa.mc` → source code in miniC.  
- `programa.s` → resulting MIPS assembly code.  

After that, the assembly file can be executed and evaluated with the corresponding MIPS tools.  

---

## Example  

Example `.c` code for the **if_else** test:  

```c
pruebaifelse(){
  const int a=1, b=0;
  var int c;
  if(a) 
    c = b+a;
  else 
    c = 0;
  
  print("c = ", c); 
}
```

Example `.s` code:  

```asm
###########################
# Data section
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
# Code section
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
# End
	li	$v0,   10
	syscall
```



# Compilador miniC → MIPS

Este proyecto consiste en la implementación de un compilador que traduce programas escritos en el lenguaje **miniC** a **código ensamblador MIPS**.  

El proceso de traducción abarca las siguientes fases:  
1. **Análisis léxico**  
2. **Análisis sintáctico**  
3. **Análisis semántico**  
4. **Generación de código ensamblador**  

---

## 1. Definición de miniC  

El lenguaje **miniC** es una versión simplificada de C con las siguientes restricciones:  

- Sólo maneja **constantes y variables enteras**.  
- Permite únicamente **operadores aritméticos de enteros**.  
- No incluye **operadores relacionales ni lógicos**.  
- Las expresiones aritméticas pueden usarse como condiciones lógicas (0 = falso, distinto de 0 = verdadero).  
- No admite definición de funciones, salvo la del **programa principal**.  

---

## 2. Generación de código ensamblador MIPS  

El compilador genera código ensamblador para la arquitectura **MIPS**, usando un subconjunto de instrucciones.  

- Se emplearán los registros:  
  - **t0–t9**  
  - **s0–s7**  

---

## 3. Creación e Instalación

### Requerimientos

* **Flex**
* **Bison**
* **GCC** (u otro Compilador)
* **MARS** or **SPIM/QtSPIM** (para la generación del código Mips)

### Instrucciones de Construcción

```bash
cd Proyecto
make
```

Esto generará el ejecutable del compilador llamado `miniC`.

---


## 4. Ejecución y evaluación  

El compilador toma como entrada un archivo en **miniC** (`.mc`) y produce un archivo en ensamblador **MIPS** (`.s`).  

### Ejecución en MIPS

Puedes ejecutar tu fichero ya sea usando **MARS** o **QtSPIM**:

```bash
java -jar Mars.jar programa.s
```

Ejemplo de uso:  

```bash
./minic programa.mc > programa.s
```

Donde:  
- `programa.mc` → código fuente en miniC.  
- `programa.s` → código ensamblador MIPS resultante.  

Posteriormente, el archivo ensamblador puede ejecutarse y evaluarse con las herramientas MIPS correspondientes.  

## Ejemplo

Codigo en .c de la prueba if_else:

```bash
pruebaifelse(){
const int a=1, b=0;
var int c;
	if(a) c = b+a;
	else 
	c = 0;
	
	print("c = ", c); 
}
````

Codigo en .s:

```bash
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
````

