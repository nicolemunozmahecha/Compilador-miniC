proyecto:	lex.yy.c main.c	proyecto.tab.c	proyecto.tab.h	listaSimbolos.c	listaSimbolos.h listaCodigo.c listaCodigo.h
	gcc lex.yy.c main.c listaSimbolos.c listaSimbolos.h  listaCodigo.c listaCodigo.h proyecto.tab.c -lfl -o proyecto 

proyecto.tab.c proyecto.tab.h: proyecto.y
	bison -d -v proyecto.y

lex.yy.c: proyecto.l
	flex proyecto.l
	
limpiar:
	rm lex.yy.c proyecto proyecto.tab.c	proyecto.tab.h
run: 
	./proyecto prueba
