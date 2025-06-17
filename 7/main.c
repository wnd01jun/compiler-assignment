#include <stdio.h>
#include <stdlib.h>
#include "type.h"
extern FILE *yyin;
extern int syntax_err;
extern int semantic_err;
extern A_NODE *root;
FILE *fout;
int line_no = 1;
void initialize();
void print_ast();
void print_sem_ast();
void semantic_analysis();
void code_generation();
extern FILE *yyin;
void main(int argc, char *argv[]) 
{	if (argc<2){
		printf("source file not given\n");
		exit(1);}
	if (strcmp(argv[1],"-o")==0) 
		if (argc>3) 
			if ((fout=fopen(argv[2],"w"))==NULL) {
				printf("can not open output file: %s\n",argv[3]); 
				exit(1);}
			else ;
		else  { printf("out file not given\n");
			exit(1);} 
	else if (argc==2)
 		if ((fout=fopen("a.asm","w"))==NULL) {
 			printf("can not open output file: a.asm\n"); 
 			exit(1);}
	if ((yyin=fopen(argv[argc-1],"r"))==NULL){
		printf("can not open input file: %s\n",argv[argc-1]);
		exit(1);}
	printf("\nstart syntax analysis\n");
	initialize();
	yyparse();
	if (syntax_err) exit(1);
	print_ast(root);
	printf("\nstart semantic analysis\n");
	semantic_analysis(root);
	if (semantic_err) exit(1);
	print_sem_ast(root);
	printf("start code generation\n");
	code_generation(root);
	printf("end code generation\n");
	exit(0);
}

int yywrap() {
    return 1;
}

int yyerror(char *s) {
  fprintf(stderr , "line num = %d, Error : %s\n", line_no, s);
}
