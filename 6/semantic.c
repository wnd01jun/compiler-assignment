#include "type.h"
#include "semantic.h"
#define LIT_MAX 100

/*
    과제의 환경은 pointer 주소가 4byte인 환경을 가정한다.
    inializier는 없다고 가정한다.
*/

extern A_TYPE *int_type, *float_type, *char_type, *string_type, *void_type;
int global_address = 12; // activation record 구조상, 변수는 12부터 저장
int semantic_err = 0;
A_LITERAL literal_table[LIT_MAX];
int literal_no = 0;
int literal_size = 0;

void semantic_analysis(A_NODE *node) {
    sem_program(node);
    set_literal_address(node); // 전역변수 크기 계산도 수행
}

void set_literal_address(A_NODE *node) {
    int i;
    for (i = 1; i <= literal_no; i++) {
        literal_table[i].addr += node -> value;
    }
    node -> value += literal_size;
}

void set_program(A_NODE *node) {
    int i;
    switch(node -> name) { // 첫 시작은 N_PROGRAM부터
        case N_PROGRAM :
            i - sem_declaration_list(node -> clink, 12);
            node -> value = global_address;
            break;
        default :
            semantic_error(90, node -> line);
            break;
    }
}

int put_literal(A_LITERAL lit, int ll) {
    float ff;
    if( literal_no >= LIT_MAX) { // literal 최대 개수가 LIT_MAX로 제한되어 있는듯
        semnatic_error(93, ll);
    }
    else {
        literal_no++;
    }

    literal_table[literal_no] = lit;
    literal_table[literal_no].addr = literal_size;
    if (lit.type -> kind == T_ENUM) {
        literal_size += 4;
    }
    else if (isStringType(lit.type)) {
        literal_size += strlen(lit.value.s) + 1;
    }
    if (literal_size % 4) {
        literal_size = literal_size / 4 * 4 + 4; // 4의 배수로 맞추기 (word alignment)
    }
    return literal_no;
}

A_TYPE *sem_expression(A_NODE *node) {
    A_TYPE *result = NIL, *t, *t1, *t2;
    A_ID *id;
    A_LITERAL lit;
    int i;
    BOOLEAN lvalue = FALSE;

    switch (node -> name) {
        case N_EXP_IDENT:
            id = node -> clink;
            switch (id -> kind) {
                case ID_VAR:
                case ID_PARM:
                    result = id -> type;
                    if (!isArrayType(result)) {
                        lvalue = TRUE;
                    }
                    break;
                case ID_FUNC:
                    result = id -> type;
                    break;
                case ID_ENUM_LITERAL:
                    result = int_type;
                    break;
                default:
                    semantic_error(38, node -> line, id -> name);
                    break;
            }
            break;
        case N_EXP_INT_CONST:
            result = int_type;
            break;
        case N_EXP_FLOAT_CONST:
            lit.type = float_type;
            lit.value.f = atof(node -> clink); // string -> float
            node -> clink = put_literal(lit, node -> line); // 교체해주는듯? clink
            result = float_type;
            break;
        case N_EXP_CHAR_CONST:
            result = char_type;
            break;
        case N_EXP_STRING_LITERAL:
            lit.type = string_type;
            lit.value.s = node -> clink;
            node -> clink = put_literal(lit, node -> line);
            result = string_type; // float 비슷하게 동작
            break;
        case N_EXP_ARRAY:
            t1 = sem_expression(node -> llink);
            t2 = sem_expression(node -> rlink);
            t = convertUsualBinaryConversion(node); // 이항 연산자 변환 if float -> all float
            t1 = node -> llink -> type;
            t2 = node -> rlink -> type;
            if (isPointerOrArrayType(t1)){
                result = t1 -> element_type;
            }
            else {
                semantic_error(32, node -> line);
            }
            if (!isIntegralType(t2)) {
                semantic_error(29, node -> line);
            }
            if (!isArrayType(result)) {
                lvalue = TRUE;
            }
            break;
        case N_EXP_STRUCT: // struct.a  << 이런 형식
            t = sem_expression(node -> llink); // 최종적으로 얘가 어떤 struct인지 알아내야 할듯?
            id = getStructFieldIdentifier(t, node -> rlink); // sturct안에 identifier가 있는지 가져오는듯?
            if (id) {
                result = id -> type;
                if (node -> llink -> value && !isArrayType(result)) {
                    lvalue = TRUE;
                }
                else {
                    semantic_error(37, node -> line);
                }
                node -> rlink = id;
                break;
            }
        case N_EXP_FUNCTION_CALL:
            t = sem_expression(node -> llink);

            node -> llink = convertUsualUnaryConversion(node -> llink);
            t = node -> llink -> type;
            if (isPointerType(t) && isFUnctionType(t -> element_type)) {
                sem_arg_expr_list(node -> rlink, t -> element_type -> field);
                result = t -> element_type -> element_type; // 함수의 return 형
                // 근데 함수의 return형이 int *, int **와 같은 형식이면 pointer가 리턴되지 않을까?
            }
            else {
                semantic_error(21, node -> line);
            }
            break;
        case N_EXP_POST_INC:
        case N_EXP_POST_DEC:
            result = sem_expression(node -> clink);
            if (!isScalarType(result)) {
                semantic_error(27, node -> line);
            }
            if (!isModifiableLvalue(node -> clink)) { // const 검사하나?
                semantic_error(60, node -> line);
            }
            break;
        case N_EXP_CAST:
            result = node -> llink;
            i = sem_A_TYPE(result); // llink로 casting
            t = sem_expression(node -> rlink);

            if (!isAllowableCastingConversion(result, t)) {
                semantic_error(58, node -> line);
            }
            break;
        case N_EXP_SIZE_TYPE: // sizeof(int)
            t = node -> clink;
            i = sem_A_TYPE(t);

            if (isArrayType(t) && t -> size == 0 || isFunctionType(t) || isVoidType(t)) {
                semantic_error(39, node -> line); // void, array, function은 sizeof불가
                // array?
            }
            else {
                node -> clink = i;
            }
            result = int_type;
            break;
        case N_EXP_SIZE_EXP: // sizeof(exp)
            t = sem_expression(node -> clink);
            if (node -> clink -> name != N_EXP_IDENT || ((A_ID*)node -> clink -> clink) -> kind != ID_PARM &&  
            (isArrayType(t) && t -> size == 0 || isFunctionType(t))) { // void func(int arr[], int f());
                semantic_error(39, node->line);
            }
            else {
                node -> clink = t -> size;
            }
            result = int_type;
            break;
        case N_EXP_PLUS:
        case N_EXP_MINUS:
            t = sem_expression(node -> clink);
            if (isArithmeticType(t)) {
                node -> clink = convertUsualUnaryConversion(node -> clink);
                result = node -> clink -> type;
            }
            else {
                semantic_error(13, node -> line);
            }
            break;
        case N_EXP_NOT: // ! cast
            t = sem_expression(node -> clink);
            if (isScalarType(t)) {
                node -> clink = convertUsualUnaryConversion(node -> clink);
                result = int_type;
            }
            else {
                semantic_error(27, node -> line);
            }
            break;
        case N_EXP_AMP:
            t = sem_expression(node -> clink);
            if (node -> clink -> value == TRUE || isFunctionType(t)) { // 함수 포인터도 리턴
                result = setTypeElementType(makeType(T_POINTER), t); // 포인터 생성
                result -> size = 4; // 포인터 사이즈
            }
            else {
                semnatic_error(60, node -> line);
            }
        case N_EXP_STAR: // *a
            t = sem_expression(node -> clink);
            node -> clink = convertUsualUnaryConversion(node -> clink);
            if (isPointerType(t)) {
                result =t -> element_type;
                if (isStructOrUnionType(result) || isScalarType(result)) {
                    lvalue = TRUE;
                }
            }
            else {
                semantic_error(31, node -> line);
            }
            break;
        case N_EXP_PRE_INC:
        case N_EXP_PRE_DEC:
            result = sem_expression(node -> clink);
            if (!isScalarType(result)) {
                semantic_error(27, node -> line);
            }
            if (!isModifiableLvalue(node -> clink)) {
                semantic_error(60, node -> line);
            }
            break;
        case N_EXP_MUL:
        case N_EXP_DIV:
            t1 = sem_expression(node -> llink);
            t2 = sem_expression(node -> rlink);
            if (isArithmeticType(t1) && isArithmeticType(t2)) {
                result = convertUsualBinaryConversion(node); // implicty casting
            }
            else {
                semantic_error(28, node -> line);
            }
            break;


    }
}
