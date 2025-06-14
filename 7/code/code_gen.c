#include <stdio.h>
#include <string.h>
#include "code_gen.h"


char *opcode_name[] = {"OP_NULL", "LOD", "LDX", "LDXB", "LDA", "LITI", "STO", "STOB", "STX", "STXB", "SUBI",
"SUBF", "DIVI", "DIVF", "ADDI", "ADDF", "OFFSET", "MULI", "MULF", "MOD", "LSSI", "LSSF", "GTRI", "GTRF",
"LEQI", "LEQF", "GEQI", "GEQF", "NEQI", "NEQF", "EQLI", "EQLF", "NOT", "OR", "AND", "CVTI", "CVTF", "JPC",
"JPCR", "JMP", "JPT", "JPTR", "INT", "INCI", "INCF", "DECI", "DECF", "SUP", "CAL", "ADDR", "RET", "MINUSI", 
"MINUSF", "CHK", "LDI", "LDIB", "SWITCH", "SWVALUE", "SWDEFAULT", "SWLABEL", "SWEND", "POP", "POPB"};

int label_no = 0;
int gen_err = 0;
extern FILE *fout;
extern A_TYPE *int_type, *float_type, *char_type, *void_type, *string_type;
extern A_LITERAL literal_table[];
extern int literal_no;

void code_generation(A_NODE *node) {
    gen_program(node);
    gen_literal_table();
}

void gen_literal_table() {
    int i;
    for (i = 1; i <= literal_no; i++) {
        fprintf(fout,".literal %5d ", literal_table[i].addr);
        if (literal_table[i].type == int_type) {
            fprintf(fout, "%d\n", literal_table[i].value.i);
        }
        else if (literal_table[i].type == float_type) {
            fprintf(fout, "%f\n", literal_table[i].value.f);
        }
        else if (literal_table[i].type == char_type) {
            fprintf(fout, "%d\n", literal_table[i].value.c);
        }
        else if (literal_table[i].type == string_type) {
            fprintf(fout, "%s\n", literal_table[i].value.s);
        }
    }
}

void gen_program(A_NODE *node) {
    switch(node -> name) {
        case N_PROGRAM :
            gen_code_i(INT, 0, node -> value);
            gen_code_s(SUP, 0, "main");
            gen_code_i(RET, 0, 0);
            gen_declaration_list(node -> clink);
            break;
        default :
            gen_error(100,node -> line);
            break;
    }
}

void gen_expression(A_NODE *node) {
    A_ID *id;
    A_TYPE *t;
    int i,ll;
    switch(node -> name) {
        case N_EXP_IDENT :
            id = node -> clink;
            t = id -> type;
            switch (id -> kind) {
                case ID_VAR:
                case ID_PARM:
                    switch (t -> kind) {
                        case T_ENUM:
                        case T_POINTER:
                            gen_code_i(LOD, id -> lvel, id -> address);
                            break;
                        case T_ARRAY:
                            if (id -> kind == ID_VAR) {
                                gen_code_i(LDA, id -> level, id -> address);
                            }
                            else {
                                gen_code_i(LOD, id -> level, id -> address) // param일 때 인듯
                            }
                            break;
                        case T_STRUCT:
                        case T_UNION:
                            gen_code_i(LDA, id -> level, id -> address);
                            i = id -> type -> size;
                            gen_code_i(LDI, 0, i%4 ? i/4+1 : i/4);
                            break;
                        default :
                            gen_error(11, id -> line);
                            break;
                    }
                case ID_ENUM_LITERAL:
                    gen_code_i(LITI, 0, id -> init);
                    break;
                default:
                    gen_error(11, node -> line);
                    break;
            }
        case N_EXP_INT_CONST:
            gen_code_i(LITI, 0, node -> clink);
            break;
        case N_EXP_FLOAT_CONST:
            i = node -> clink;
            gen_code_i(LOD, 0, literal_table[i].addr);
            break;
        case N_EXP_CHAR_CONST:
            gen_code_i(LITI, 0, node -> clink);
            break;
        case N_EXP_STRING_LITERAL:
            i = node -> clink;
            gen_code_i(LDA, 0, literal_table[i].addr);
            break;
        case N_EXP_ARRAY:
            gen_expression(node -> llink);
            gen_expression(node -> rlink);
            // gen_code_i(CHK, 0, node -> llink -> type -> expr);
            if (node -> type -> size > 1) {
                gen_code_i(LITI, 0, node -> type -> size);
                gen_code_i(MULI, 0, 0);
            }
            gen_code_i(OFFSET, 0, 0);
            if (!isArrayType(node -> type)) { // ARRAY가 아니면 배열 참조는 LDI로 값 가져오기 
                i = node -> type -> size;
                if (i == 1) {
                    gen_code_i(LDIB, 0, 0);
                }
                else {
                    gen_code_i(LDI, 0, i%4 ? i / 4 + 1 : i / 4); 
                }
            }
            break;
        case N_EXP_FUNCTION_CALL:
            t = node -> llink -> type;
            i = t -> element_type -> element_type -> size;
            if (i % 4) {
                i = i / 4 * 4 + 4;
            }
            if (node -> rlink) {
                gen_code_i(INT, 0,12 + i);
                gen_arg_expression(node -> rlink);
                gen_code_i(POP, 0, node -> rlink -> value/4 + 3);
            }
            else {
                gen_code_i(INT, 0, i);
            }
            gen_expression(node -> llink);
            gen_code_i(CAL, 0, 0);
            break;
        // struct는 제거하고 진행
        case N_EXP_POST_INC:
            gen_expression(node -> clink);
            gen_expression_left(node -> clink);
            t = node -> type;
            if (node -> type -> size == 1) {
                gen_code_i(LDXB, 0, 0);
            }
            else {
                gen_code_i(LDXB)
            }
    }
}