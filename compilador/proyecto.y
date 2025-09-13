%code requires{
	#include "listaCodigo.h"
}
%{
#include <stdio.h>
#include "listaSimbolos.h"
#include "listaCodigo.h"
Lista tablaSimb;
extern int yylex();
extern char* yytext;
void yyerror();
extern int yylineno;
int contadorCadenas = 0;
int errSemanticos = 0;
int errSintacticos = 0;
extern int errLexicos;
extern int varError;
%}

%union{ 
char* lexema1;
ListaC codigo;	
}
%token VAR CONST INT IF ELSE WHILE READ PRINT LPAREN RPAREN PUNTOCOMA COMA IGUAL LCORCHETE RCORCHETE INTERR DOSP DO 
%token <lexema1> ID STRING NUM
%type <codigo> expression statement const_list print_item print_list read_list statement_list declaration 

%nonassoc MAYOR MENOR MAYORIGUAL MENORIGUAL IGUALIGUAL DISTINTO	
%left SUMA MENOS	// suma y resta asociativos por la izquierda, para lo de desplazar y reduciR
%left MULT DIV		// asociativos por la izquierda, mas precedencia que la suma y resta (mas abajo mas precedencia)
%left UMENOS

%expect 1
%%

program	:		{tablaSimb = creaLS(); }
			ID LPAREN RPAREN LCORCHETE declaration statement_list RCORCHETE
			{if(varError == 1){printf("\n\nErrores lexicos: %d\nErrores sintacticos: %d\nErrores semanticos: %d\n", errLexicos, errSintacticos, errSemanticos);
			}else{imprimeTabla(tablaSimb); imprimeLista($6, $7); liberaLC($6); liberaLC($7);} liberaLS(tablaSimb); }

		;
declaration	:	declaration VAR tipo var_list PUNTOCOMA			{$$ = $1;}
		|	declaration CONST tipo const_list PUNTOCOMA		{concatenaLC($1, $4); liberaLC($4); $$ = $1;}
		|	{$$ = creaLC();}					
		;
tipo		:	INT		
		;
var_list	:	ID 			{if (!pertenece($1, tablaSimb)){insertaTabla($1, tablaSimb, VARIABLE);  }
						else{printf("\nError en linea %d: variable %s ya declarada", yylineno, $1); varError = 1; errSemanticos++;};}	
		|	var_list COMA ID 	{if (!pertenece($3, tablaSimb)){insertaTabla($3, tablaSimb, VARIABLE); }
						else{printf("\nError en linea %d: variable %s ya declarada", yylineno, $3); varError = 1; errSemanticos++;};}			
		;
const_list	:	ID IGUAL expression			{if(!pertenece($1, tablaSimb)){insertaTabla($1, tablaSimb, CONSTANTE);
								$$ = asignacion($3, $1); liberaLC($3);}
								else{printf("\nError en linea %d: variable %s ya declarada", yylineno, $1); $$ = creaLC();
								varError = 1; errSemanticos++;};}	
		|	const_list COMA ID IGUAL expression	{if(!pertenece($3, tablaSimb)){insertaTabla($3, tablaSimb, CONSTANTE);
								$$ = asignaConstList($1, $3, $5); liberaLC($1);}
								else{printf("\nError en linea %d: variable %s ya declarada", yylineno, $3); $$ = creaLC();
								varError = 1; errSemanticos++;};}	
		;
statement_list	:	statement_list statement	{$$ = concatenar($1, $2); liberaLC($2); liberaLC($1); }
		|	{$$ = creaLC($$);}
		;
statement	:	ID IGUAL expression PUNTOCOMA	{if (!pertenece($1, tablaSimb)){printf("\nError en linea %d: variable %s no declarada", yylineno, $1); 
							$$ = creaLC();varError = 1; errSemanticos++;}
							else{if (!compruebaTipo($1, tablaSimb)){printf("\nError en linea %d: variable %s es constante", yylineno, $1); 
							$$ = creaLC();varError = 1; errSemanticos++;}
							else{$$ = asignacion($3, $1); liberaLC($3); }}}
									
		|	LCORCHETE statement_list RCORCHETE						{$$ = asignaIgual($2); liberaLC($2); }
		|	IF LPAREN expression RPAREN statement ELSE statement				{$$ = asignaIfElse($3, $5, $7); }	
		|	IF LPAREN expression RPAREN statement						{$$ = asignaIf($3, $5); }
		|	WHILE LPAREN expression RPAREN statement					{$$ = asignaWhile($3, $5); }
		|	PRINT LPAREN print_list RPAREN PUNTOCOMA					{$$ = asignaIgual($3); liberaLC($3);}
		|	READ LPAREN read_list RPAREN PUNTOCOMA						{$$ = asignaIgual($3); liberaLC($3); }
		|	DO LCORCHETE statement_list RCORCHETE WHILE LPAREN expression RPAREN	PUNTOCOMA	{$$ = asignaDoWhile($3, $7);}
		;
print_list	:	print_item			{$$ = asignaIgual($1); liberaLC($1); }
		| 	print_list COMA print_item	{$$ = concatenar($1, $3); liberaLC($1); liberaLC($3);}
		;
print_item	:	expression			{$$ = asignaPrint2($1); liberaLC($1); }
		|	STRING				{insertaTabla($1, tablaSimb, CADENA); contadorCadenas++; $$ = asignaPrint();}	
		;
read_list	:	ID				{if (!pertenece($1, tablaSimb)){printf("\nError en linea %d: variable %s no declarada", yylineno, $1);
							 $$ = creaLC();varError = 1; errSemanticos++;}
							else{if (!compruebaTipo($1, tablaSimb)){printf("\nError en linea %d: variable %s es constante", yylineno, $1); 
							$$ = creaLC();varError = 1; errSemanticos++;}
							else{$$ = asignaRead($1); }}}
		|	read_list COMA ID		{if (!pertenece($3, tablaSimb)){printf("\nError en linea %d: variable %s no declarada", yylineno, $3);
							varError = 1; errSemanticos++;}
							else{if (!compruebaTipo($3, tablaSimb)){printf("\nError en linea %d: variable %s es constante", yylineno, $3); 
							$$ = creaLC();varError = 1; errSemanticos++;}
							else{$$ = asignaRead2($1, $3); liberaLC($1); }}}
		;
		
expression	:	expression SUMA expression 		{$$ = asignacionAritmetica($1, $3, "\tadd"); liberaLC($1); liberaLC($3);}
		|	expression MENOS expression 		{$$ = asignacionAritmetica($1, $3, "\tsub"); liberaLC($1); liberaLC($3);}
		|	expression MULT expression 		{$$ = asignacionAritmetica($1, $3, "\tmul"); liberaLC($1); liberaLC($3);}
		|	expression DIV expression		{$$ = asignacionAritmetica($1, $3, "\tdiv"); liberaLC($1); liberaLC($3);}
		
		|	expression MAYOR expression		{$$ = asignacionAritmetica($3, $1, "\tslt"); liberaLC($1); liberaLC($3);} 
		|	expression MENOR expression		{$$ = asignacionAritmetica($1, $3, "\tslt"); liberaLC($1); liberaLC($3);} 
		|	expression MAYORIGUAL expression	{$$ = asignacionMayorIgual($3, $1); }	
		|	expression MENORIGUAL expression	{$$ = asignacionMayorIgual($1, $3); }	
		|	expression IGUALIGUAL expression	{$$ = asignacionIgualIgual($1, $3); }
		|	expression DISTINTO expression		{$$ = asignacionAritmetica($1, $3, "\txor"); liberaLC($1); liberaLC($3);}
		| 	LPAREN expression INTERR expression DOSP expression RPAREN	{$$ = asignacionInterr($2, $4, $6);}
		|	MENOS expression %prec UMENOS 		{$$ = asignaNeg($2); liberaLC($2);}
		|	LPAREN expression RPAREN 		{$$ = $2;}
		|	ID					{if (!pertenece($1, tablaSimb)){printf("\nError en linea %d: variable %s no declarada", yylineno, $1); 
								$$ = creaLC();varError = 1; errSemanticos++;}
								else{$$ = asignaId($1, "\tlw");}}	
		|	NUM					{$$ = asignaNum($1, "\tli");}
		;

%%



void yyerror()
{
	if(errLexicos >= 1 ){
		//varError = 1;
		printf("\nErrores léxicos: %d\nErrores sintacticos: %d\nErrores semanticos: %d\n", errLexicos, errSintacticos, errSemanticos);
	}
	else{	printf("\nError sintactico en linea: %d, variable %s\n", yylineno, yytext);
		errSintacticos++;
		printf("\nErrores léxicos: %d\nErrores sintacticos: %d\nErrores semanticos: %d\n", errLexicos, errSintacticos, errSemanticos);
	}

}


