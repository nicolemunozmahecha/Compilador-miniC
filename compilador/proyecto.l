%{
#include "proyecto.tab.h" 
int errLexicos = 0;
int varError = 0;
%}
%option yylineno
digito              [0-9]
letra               [a-zA-Z]
entero              {digito}+

%%


"/*"([^*]|[*]+[^*/])*[*]+"/"		    ;
"//"(.*)[\n]         		            ;
[ \n\t\r]+                       	    ;
\"([^"\n\\]|\\.)*\"		    	    {yylval.lexema1 = strdup(yytext); return STRING;};
var					    return VAR;
const					    return CONST;
int					    return INT;
if					    return IF;
else					    return ELSE;
while					    return WHILE;
read					    return READ;
print					    return PRINT;
do					    return DO;
({letra}|\_)({letra}|{digito}|_)*           if (yyleng>(32)){printf("\nError léxico, identificador muy largo %s, linea %d\n",yytext, yylineno); errLexicos++;
						}else{yylval.lexema1 = strdup(yytext); return ID;}
{entero}                                    if(atoll(yytext)>(21447483648)){printf("\nError léxico, identificador fuera de rango %s, linea %d\n",yytext, yylineno); errLexicos++;
						}else{yylval.lexema1 = strdup(yytext); return NUM;}
"/"					    return DIV;
"("                                         return LPAREN;		
")"                                         return RPAREN;
";"                                         return PUNTOCOMA;
","                                         return COMA;
"="                                         return IGUAL;
"+"                                         return SUMA;
"-"                                         return MENOS;
"{"					    return LCORCHETE;
"}"					    return RCORCHETE;
"*"					    return MULT;
"?"					    return INTERR;
":"					    return DOSP;
">"					    return MAYOR;
"<"					    return MENOR;
"<="					    return MENORIGUAL;
">="					    return MAYORIGUAL;
"=="					    return IGUALIGUAL;
"!="					    return DISTINTO;

[^a-zA-Z0-9\n\t\+\-/\*()\[\]{}_,;:=?<>!]+       {printf("Error léxico en palabra %s, linea %d\n", yytext, yylineno); errLexicos++; varError = 1;}	// modo panico
%%


