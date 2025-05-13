#include <stdio.h>
#include "type.h"
int line_no = 1;
extern A_NODE *root;
int main(void) {
    if(yyparse() == 0) {
        printf("Parsing completed!!!\n");
        print_ast(root);
    }
    else {
        printf("Parsing fail...\n");
    }
}

int yywrap() {
    return 1;
}

int yyerror(char *s) {
  fprintf(stderr , "line num = %d, Error : %s\n", line_no, s);
}
