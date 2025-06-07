#include "type.h"
#include "semantic.h"
#include "stdlib.h"
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

void sem_program(A_NODE *node) {
    int i;
    switch(node -> name) { // 첫 시작은 N_PROGRAM부터
        case N_PROGRAM :
            i - sem_declaration_list(node -> clink, 12);
            node -> value = global_address;
            break;
        default :
            semantic_error(90, node -> line, "");
            break;
    }
}

int put_literal(A_LITERAL lit, int ll) {
    float ff;
    if( literal_no >= LIT_MAX) { // literal 최대 개수가 LIT_MAX로 제한되어 있는듯
        semantic_error(93, ll, "");
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
                semantic_error(32, node -> line, "");
            }
            if (!isIntegralType(t2)) {
                semantic_error(29, node -> line, "");
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
                
            }
            else {
                    semantic_error(37, node -> line, "");
                }
            node -> rlink = id;
            break;
        case N_EXP_ARROW:
            t = sem_expression(node -> llink);
            id = getPointerFieldIdentifier(t, node -> rlink);
            if (id) {
                result = id -> type;
                if (!isArrayType(result)) {
                    lvalue = TRUE;
                }
            }
            else {
                semantic_error(37, node -> line, "");
            }
            node -> rlink = id;
            break;
        case N_EXP_FUNCTION_CALL:
            t = sem_expression(node -> llink);

            node -> llink = convertUsualUnaryConversion(node -> llink);
            t = node -> llink -> type;
            if (isPointerType(t) && isFunctionType(t -> element_type)) {
                sem_arg_expr_list(node -> rlink, t -> element_type -> field);
                result = t -> element_type -> element_type; // 함수의 return 형
                // 근데 함수의 return형이 int *, int **와 같은 형식이면 pointer가 리턴되지 않을까?
            }
            else {
                semantic_error(21, node -> line, "");
            }
            break;
        case N_EXP_POST_INC:
        case N_EXP_POST_DEC:
            result = sem_expression(node -> clink);
            if (!isScalarType(result)) {
                semantic_error(27, node -> line, "");
            }
            if (!isModifiableLvalue(node -> clink)) { // const 검사하나?
                semantic_error(60, node -> line, "");
            }
            break;
        case N_EXP_CAST:
            result = node -> llink;
            i = sem_A_TYPE(result); // llink로 casting
            t = sem_expression(node -> rlink);

            if (!isAllowableCastingConversion(result, t)) {
                semantic_error(58, node -> line, "");
            }
            break;
        case N_EXP_SIZE_TYPE: // sizeof(int)
            t = node -> clink;
            i = sem_A_TYPE(t);

            if (isArrayType(t) && t -> size == 0 || isFunctionType(t) || isVoidType(t)) {
                semantic_error(39, node -> line, ""); // void, array, function은 sizeof불가
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
                semantic_error(39, node->line, "");
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
                semantic_error(13, node -> line, "");
            }
            break;
        case N_EXP_NOT: // ! cast
            t = sem_expression(node -> clink);
            if (isScalarType(t)) {
                node -> clink = convertUsualUnaryConversion(node -> clink);
                result = int_type;
            }
            else {
                semantic_error(27, node -> line, "");
            }
            break;
        case N_EXP_AMP:
            t = sem_expression(node -> clink);
            if (node -> clink -> value == TRUE || isFunctionType(t)) { // 함수 포인터도 리턴
                result = setTypeElementType(makeType(T_POINTER), t); // 포인터 생성
                result -> size = 4; // 포인터 사이즈
            }
            else {
                semantic_error(60, node -> line, "");
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
                semantic_error(31, node -> line, "");
            }
            break;
        case N_EXP_PRE_INC:
        case N_EXP_PRE_DEC:
            result = sem_expression(node -> clink);
            if (!isScalarType(result)) {
                semantic_error(27, node -> line, "");
            }
            if (!isModifiableLvalue(node -> clink)) {
                semantic_error(60, node -> line, "");
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
                semantic_error(28, node -> line, "");
            }
            break;
        case N_EXP_MOD:
            t1 = sem_expression(node -> llink);
            t2 = sem_expression(node -> rlink);
            if (isIntegralType(t1) && isIntegralType(t2)) {
                result = convertUsualBinaryConversion(node);
            }
            else {
                semantic_error(29, node -> line, "");
            }
            result = int_type;
            break;
        case N_EXP_ADD:
            t1 = sem_expression(node -> llink);
            t2 = sem_expression(node -> rlink);
            if (isArithmeticType(t1) && isArithmeticType(t2)) {
                result = convertUsualBinaryConversion(node);
            }
            else if (isPointerType(t1) && isIntegralType(t2)) {
                result = t1;
            }
            else if (isPointerType(t2) && isIntegralType(t1)) {
                result = t2;
            }
            else {
                semantic_error(24, node -> line, "");
            }
            break;
        case N_EXP_SUB:
            t1 = sem_expression(node -> llink);
            t2 = sem_expression(node -> rlink);
            if (isArithmeticType(t1) && isArithmeticType(t2)) {
                result = convertUsualBinaryConversion(node);
            }
            else if (isPointerType(t1) && isIntegralType(t2)) {
                result = t1;
            }
            else if (isCompatiblePointerType(t1, t2)) {
                result = t1;
            }
            else {
                semantic_error(24, node -> line, "");
            }
            break;
        case N_EXP_LSS:
        case N_EXP_GTR:
        case N_EXP_LEQ:
        case N_EXP_GEQ:
            t1 = sem_expression(node -> llink);
            t2 = sem_expression(node -> rlink);
            if (isArithmeticType(t1) && isArithmeticType(t2)) {
                result = convertUsualBinaryConversion(node);
            }
            else if (!isCompatiblePointerType(t1, t2)) {
                semantic_error(40, node -> line, "");
            }
            result = int_type;
            break;
        case N_EXP_NEQ:
        case N_EXP_EQL: // != ==
            t1 = sem_expression(node -> llink);
            t2 = sem_expression(node -> rlink);
            if (isArithmeticType(t1) && isArithmeticType(t2)) {
                result = convertUsualBinaryConversion(node);
            }
            else if (!isCompatiblePointerType(t1, t2) && \
                (!isPointerType(t1) || !isConstantZeroExp(node -> rlink)) && \
                (!isPointerType(t1) || !isConstantZeroExp(node -> rlink))) {
                semantic_error(40, node -> line, "");
            }
            result = int_type;
            break;
        case N_EXP_AND:
        case N_EXP_OR:
            t = sem_expression(node -> llink);
            if (isScalarType(t)) {
                node -> llink = convertUsualUnaryConversion(node -> llink);
            }
            else {
                semantic_error(27, node -> line, "");
            }
            t = sem_expression(node -> rlink);
            if (isScalarType(t)) {
                node -> rlink = convertUsualUnaryConversion(node -> rlink);
            }
            else {
                semantic_error(27, node -> line, "");
            }
            result = int_type;
            break;
        case N_EXP_ASSIGN:
            result = sem_expression(node -> llink);
            if (!isModifiableLvalue(node -> llink)) {
                semantic_error(60, node -> line, "");
            }
            t = sem_expression(node -> rlink);
            if (isAllowableAssignmentConversion(result, t, node -> rlink)) {
                if (isArithmeticType(result) && isArithmeticType(t)) {
                    node -> rlink = convertUsualAssignmentConversion(result, node -> rlink);
                }
            }
            else {
                semantic_error(58, node -> line, "");
            }
            break;
        default:
            semantic_error(90, node -> line, "");
            break;
    }
    node -> type = result;
    node -> value = lvalue;
    return result;
}


void sem_arg_expr_list(A_NODE *node, A_ID *id) { // function call에 들어있는, arg list들
    A_TYPE *t; // 함수정의부 id랑 call에 쓰인 node랑 비교하는듯?
    A_ID *a;
    int arg_size = 0;
    switch(node -> name) {
        case N_ARG_LIST :
            if (id == 0) {
                semantic_error(34, node -> line, "");
            }
            else {
                if (id -> type) {
                    t = sem_expression(node -> llink) ;
                    node -> llink = convertUsualUnaryConversion(node -> llink);
                    if (isAllowableCastingConversion(id -> type, node -> llink -> type)) {
                        node -> llink = convertCastingConversion(node -> llink, id -> type);
                    }
                    else {
                        semantic_error(59, node -> line, "");
                    }
                    sem_arg_expr_list(node -> rlink, id -> link); // 다음 파라미터 검사?
                    
                }
                else { // DOTDOTDOT parameter
                    t = sem_expression(node -> llink);
                    sem_arg_expr_list(node -> rlink, id);
                }
                arg_size = node -> llink -> type -> size + node -> rlink -> value;
            }
            break;
        case N_ARG_LIST_NIL : // () 이런경우?
            if (id && id -> type) { // ... 인 경우 파라미터 하나는 와야하는듯?
                semantic_error(35, node -> line, "");
            }
            break;
        default:
            semantic_error(90, node -> line, "");
            break;
    }
    if (arg_size % 4) arg_size = arg_size/4 * 4 + 4; // word alignment
    node -> value = arg_size;
}

BOOLEAN isModifiableLvalue(A_NODE *node) { // void, function, FALSE인 경우 modifiable하지 않다...
    if (node -> value == FALSE || isVoidType(node -> type) || isFunctionType(node -> type)) {
        return FALSE;
    }
    else {
        return TRUE;
    }
}

int sem_statement(A_NODE *node, int addr, A_TYPE *ret, BOOLEAN sw, BOOLEAN brk, BOOLEAN cnt) {
    int local_size = 0, i;
    A_LITERAL lit;
    A_TYPE *t;

    switch(node -> name) {
        case N_STMT_LABEL_CASE: // case문
            if (sw == FALSE) {
                semantic_error(71, node -> line, "");
            }
            lit = getTypeAndValueOfExpression(node -> llink); // type 및 연산까지 가져오는듯?
            if (isIntegralType(lit.type)) {
                node -> llink = lit.value.i; // expression에 값 할당
            }
            else {
                semantic_error(51, node -> line, "");
            }
            local_size = sem_statement(node -> rlink, addr, ret, sw, brk, cnt); // 다음꺼 재귀적으로 호출
            break;
        case N_STMT_LABEL_DEFAULT:
            if (sw == FALSE) {
                semantic_error(72, node -> line, "");
            }
            local_size = sem_statement(node -> clink, addr, ret, sw, brk, cnt);
            break; // 딱히 볼게 없는듯? default는
        case N_STMT_COMPOUND: // 복합문
            if (node -> llink) {
                local_size = sem_declaration_list(node -> llink, addr); // llink는 declaration_list
            }
            local_size += sem_statement_list(node -> rlink, local_size + addr, ret, sw, brk, cnt); // rlink는 statmement_list
                
            
            break;
        case N_STMT_EMPTY:
            break;
        case N_STMT_EXPRESSION:
            t = sem_expression(node -> clink); // 수식 평가
            break;
        case N_STMT_IF:
            t = sem_expression(node -> llink); // llink 수식
            if (isScalarType(t)) { // 수식은 스칼라만 허용
                node -> llink = convertScalarToInteger(node -> llink);    
            }
            else {
                semantic_error(50, node -> line, "");
            }
            local_size = sem_statement(node -> rlink, addr, ret, FALSE, brk, cnt); // rlink는 statement
            break;
        case N_STMT_IF_ELSE:
            t = sem_expression(node -> llink);
            if (isScalarType(t)) { // 수식은 스칼라만 허용
                node -> llink = convertScalarToInteger(node -> llink);    
            }
            else {
                semantic_error(50, node -> line, "");
            }
            local_size = sem_statement(node -> clink, addr, ret, FALSE, brk, cnt); // clink인거 주의
            i = sem_statement(node -> rlink, addr, ret, FALSE, brk, cnt); // else문 가는듯
            if (local_size < i) { // else 보다 local이 작으면 else에 맞춘다?
                local_size = i;
            }
            break;
        case N_STMT_SWITCH:
            t = sem_expression(node -> llink);
            if (!isIntegralType(t)) {
                semantic_error(50, node -> line, "");
            }
            local_size = sem_statement(node -> rlink, addr, ret, TRUE, TRUE, cnt);
            break;
        case N_STMT_WHILE:
            t = sem_expression(node -> llink);
            if (isScalarType(t)) {
                node -> llink = convertScalarToInteger(node -> llink);
            }
            else {
                semantic_error(50, node -> line, "");
            }
            local_size = sem_statement(node -> rlink, addr, ret, FALSE, TRUE, TRUE);
            break;
        case N_STMT_DO:
            local_size = sem_statement(node -> llink, addr, ret, FALSE, TRUE, TRUE);
            t = sem_expression(node -> rlink);
            if (isScalarType(t)) {
                node -> rlink = convertScalarToInteger(node -> rlink);
            }
            else {
                semantic_error(50, node -> line, "");
            }
            break;
        case N_STMT_FOR:
            sem_for_expression(node -> llink); // 얘는 3개가 묶여있음
            // for문도 우리가 평소 쓰는 for(int i) << 이거 안됌(expression만 되므로) 그래서 local_size 안가져옴
            local_size = sem_statement(node -> rlink, addr, ret, FALSE, TRUE, TRUE);
            break;
        case N_STMT_CONTINUE:
            if (cnt == FALSE) {
                semantic_error(74, node -> line, "");
            }
            break;
        case N_STMT_BREAK:
            if (brk == FALSE) {
                semantic_error(73, node -> line, "");
            }
            break;
        case N_STMT_RETURN:
            if (node -> clink) {
                t = sem_expression(node -> clink);
                if (isAllowableCastingConversion(ret, t)) {
                    node -> clink = convertCastingConversion(node -> clink, ret);
                }
                else {
                    semantic_error(57, node -> line, "");
                }
            }
            break;
        default:
            semantic_error(90, node -> line, "");
            break;
    }
    node -> value = local_size;
    return local_size;
}

void sem_for_expression(A_NODE *node) {
    A_TYPE *t;
    switch (node -> name) {
        case N_FOR_EXP:
            if (node -> llink) {
              t = sem_expression(node -> llink);  
            }
            if (node -> clink) {
                t = sem_expression(node -> clink);
                if (isScalarType(t)) {
                    node -> clink = convertScalarToInteger(node -> clink);
                }
                else {
                    semantic_error(49, node -> line, "");
                }
            }
            if (node -> rlink) {
                t = sem_expression(node -> rlink);
            }
            break;
        default:
            semantic_error(90, node -> line, "");
            break;
    }
}

int sem_statement_list(A_NODE *node, int addr, A_TYPE *ret, BOOLEAN sw, BOOLEAN brk, BOOLEAN cnt) {
    int size = 0, i = 0;
    switch (node -> name) {
        case N_STMT_LIST:
            size = sem_statement(node -> llink, addr, ret, sw, brk, cnt); // statemet_list는 llink는 statement, rlink는 list로 연결
            i = sem_statement_list(node -> rlink, addr, ret, sw, brk, cnt);
            if (size < i) {
                size = i;
            }
            break;
        case N_STMT_LIST_NIL:
            size = 0;
            break; // NIL은 list의 가장 끝 부분에 연결
        default:
            semantic_error(90, node -> line, "");
            break;
    }
    node -> value = size;
    return size;
}

int sem_A_TYPE(A_TYPE *t) {
    A_ID *id;
    A_TYPE *tt;
    A_LITERAL lit;
    int result = 0, i;

    if (t -> check) {
        return t -> size; // 무한 싸이클 방지 및 중복 연산 방지를 위해서 사용
    }
    t -> check = 1;

    switch (t -> kind) {
        case T_NULL:
            semantic_error(80, t -> line, "");
            break;
        case T_ENUM:
            i = 0;
            id = t -> field;
            while (id) {
                if (id -> init) {
                    lit = getTypeAndValueOfExpression(id -> init);
                    if (!isIntType(lit.type)) {
                        semantic_error(81, id -> line, "");
                    }
                    i = lit.value.i; // init이 설정되어 있으면, 거기서 가져와서 i에 저장
                }
                id -> init = i++;  // init값에 i 할당하고 i는 +1 (다음값을 위해))
                id = id -> link;
            }
            result = 4;
            break;
        case T_ARRAY:
            if (t -> expr) {
                lit = getTypeAndValueOfExpression(t -> expr); // [ ] << 이 부분의 수식 판별
                if (!isIntType(lit.type) || lit.value.i <= 0) { // 0이하거나 정수가 아니면
                    semantic_error(82, t -> line, "");
                    t -> expr = 0;
                }
                else {
                    t -> expr = lit.value.i;
                }
                i = sem_A_TYPE(t -> element_type) * (int)t -> expr; // 원소타입의 크기 * expr의 크기
                if (isVoidType(t -> element_type) || isFunctionType(t -> element_type)) {
                    semantic_error(83, t -> line, ""); // 순서 위로 올려도 될꺼 같음
                }
                else {
                    result = i;
                }
            }
            else { // 무조건 expr이 존재해야한다 우리 프로그램에서는
                semantic_error(83, t -> line, "");
            }
            break;
        case T_STRUCT:
            id = t -> field;
            while (id) {
                result += sem_declaration(id, result); // 모든 값을 더하고 저장
                id = id -> link;
            }
            break;
        case T_UNION:
            id = t -> field;
            while (id) {
                i = sem_declaration(id, 0);
                if (i > result) {
                    result = i;
                }
                id = id -> link; // 제일 큰 값 지정
            }
            break;
        case T_FUNC:
            tt = t -> element_type;
            i = sem_A_TYPE(tt);
            if (isArrayType(tt) || isFunctionType(tt)){ // return type check
                semantic_error(85, t -> line, "");
            }
            i = sem_declaration_list(t -> field,12) + 12; // parameter check 12는 왜 더하지?
            if (t -> expr) {
                i = i + sem_statement(t -> expr, i, t -> element_type, FALSE, FALSE, FALSE); // statement내에서 변수 정의도 더함
            }
            t -> local_var_size = i;
            break;
        case T_POINTER:
            i = sem_A_TYPE(t -> element_type);
            result = 4; // 우리 프로그램은 포인터 사이즈가 4이다.
            break;
        case T_VOID:
            break;
        default:
            semantic_error(90, t -> line, "");
            break;

    }
    t -> size = result;
    return result;
    
}

// declaration에 대해 모두 주소설정하고, 그 합을 return
int sem_declaration_list(A_ID *id, int addr) {
    int i = addr;
    while (id) {
        addr += sem_declaration(id, addr);
        id = id -> link;
    }
    return addr - i;
}

// declaration인지 확인, 주소설정, 그리고 사이즈를 리턴
int sem_declaration(A_ID *id, int addr) {
    A_TYPE *t;
    int size = 0, i;
    A_LITERAL lit;
    switch (id -> kind) {
        case ID_VAR:
            i = sem_A_TYPE(id -> type); // 사이즈 리턴!
            if (isArrayType(id -> type) && id -> type -> expr == NIL) {
                semantic_error(86, id -> line, "");
            }
            if (i % 4) {
                i = i / 4 * 4 + 4; // word alignment
            }
            if (id -> specifier == S_STATIC) {
                id -> level = 0; // static타입은 level 0으로...
            }
            if (id -> level == 0) {
                id -> address = global_address;
                global_address += i; // 전역변수 or static인 경우 따로 global address 사용
            }
            else {
                id -> address = addr;
                size = i;
            }
            break;
        case ID_FIELD:
            i = sem_A_TYPE(id -> type);
            if (isFunctionType(id -> type) || isVoidType(id -> type)) {
                semantic_error(84, id -> line, ""); // 함수랑 void는 field로 불가
            }
            if (i % 4) {
                i = i/4 * 4 + 4;
            }
            id -> address = addr;
            size = i;
            break;
        case ID_FUNC:
            i = sem_A_TYPE(id -> type);
            break;
        case ID_PARM:
            if (id -> type) { // void나 ... 때문인듯
                size = sem_A_TYPE(id -> type);
                
                if (id -> type == char_type) {
                    id -> type = int_type;
                }
                else if (isArrayType(id -> type)) {
                    id -> type -> kind = T_POINTER;
                    id -> type -> size = 4;
                }
                else if (isFunctionType(id -> type)) { // 함수를 fucntion pointer로 제작(param)
                    t = makeType(T_POINTER);
                    t -> element_type = id -> type;
                    t -> size = 4;
                    id -> type = 4;
                }
                size = id -> type -> size;
                if (size % 4) {
                    size = size / 4 * 4 + 4;
                }
                id -> address = addr;

            }
            break;
        case ID_TYPE:
            i = sem_A_TYPE(id -> type);
            break;
        default:
            semantic_error(89, id -> line, id -> name);
            break;
    }
    return size;
}

A_ID *getStructFieldIdentifier(A_TYPE *t, char *s) {
    A_ID *id = NIL;
    if (isStructOrUnionType(t)) {
        id = t -> field;
        while (id) {
            if (strcmp(id -> name,s) == 0) {
                break;
            }
            id = id -> link;
        }
    }
    return id;
}

A_ID *getPointerFieldIdentifier(A_TYPE *t, char *s) {
    A_ID *id = NIL;
    if (t && t -> kind == T_POINTER) {
        t = t -> element_type;
        id = getStructFieldIdentifier(t, s);
    }
    return id;
}

BOOLEAN isSameParameterType(A_ID *a, A_ID *b) {
    while (a) {
        if (b == NIL || isNotSameType(a -> type, b -> type)) {
            return FALSE;
        }
        a = a -> link;
        b = b -> link;
    }
    if (b) {
        return FALSE;
    }
    else {
        return TRUE;
    }
}

BOOLEAN isCompatibleType(A_TYPE *t1, A_TYPE *t2) {
    if (isArrayType(t1) && isArrayType(t2)) {
        if (t1 -> size == 0 || t2 -> size == 0 || t1 -> size == t2 -> size) {
            return isCompatibleType(t1 -> element_type, t2 -> element_type);
        }
        else {
            return FALSE;
        }
    }
    else if (isFunctionType(t1) && isFunctionType(t2)) {
        if (isSameParameterType(t1 -> field, t2 -> field)) {
            return isCompatiblePointerType(t1 -> element_type, t2 -> element_type);
        }
        else {
            return FALSE;
        }
    }
    else if (isPointerType(t1) && isPointerType(t2)) {
        return isCompatibleType(t1 -> element_type, t2 ->element_type);
    }
    else {
        return t1 == t2;
    }
}

BOOLEAN isConstantZeroExp(A_NODE *node) {
    if (node -> name == N_EXP_INT_CONST && node -> clink == 0) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

BOOLEAN isCompatiblePointerType(A_TYPE *t1, A_TYPE *t2) { // 굳이 얘가 필요한가?
    if (isPointerType(t1) && isPointerType(t2)) {
        return isCompatibleType(t1 -> element_type, t2 -> element_type);
    }
    else {
        return FALSE;
    }
}

A_NODE *convertScalarToInteger(A_NODE *node) {
    if (isFloatType(node -> type)) {
        semantic_warning(16, node -> line);
        node = makeNode(N_EXP_CAST, int_type, NIL, node); // casting 처리
    }
    node -> type = int_type;
    return node;
}

A_NODE *convertUsualAssignmentConversion(A_TYPE *t1, A_NODE *node) {
    A_TYPE *t2;
    t2 = node -> type;
    if (!isCompatibleType(t1, t2)) {
        semantic_warning(11, node -> line); //t1? l1?
        node = makeNode(N_EXP_CAST,t1, NIL, node);
        node -> type = t1;
    }
    return node;
}

A_NODE *convertUsualUnaryConversion(A_NODE *node) {
    A_TYPE *t;
    t = node -> type;
    if (t == char_type) {
        t = int_type;
        node = makeNode(N_EXP_CAST, t, NIL, node);
        node -> type = t;
    }
    else if (isArrayType(t)) {
        t = setTypeElementType(makeType(T_POINTER), t -> element_type); // array는 pointer 생성
        t -> size = 4;
        node = makeNode(N_EXP_CAST, t, NIL, node);
        node -> type = t;
    }
    else if (isFunctionType(t)) {
        t = setTypeElementType(makeType(T_POINTER), t);
        t -> size = t;
        node = makeNode(N_EXP_AMP, NIL, node, NIL); // pointer로 만들고 & 연산자 적용
        node -> type = t;
    }
    return node;
}

A_TYPE *convertUsualBinaryConversion(A_NODE *node) {
    A_TYPE *t1, *t2, *result = NIL;
    t1 = node -> llink -> type;
    t2 = node -> rlink -> type;
    if (isFloatType(t1) && !isFloatType(t2)) {
        semantic_warning(14, node -> line);
        node -> rlink = makeNode(N_EXP_CAST, t1, NIL, node -> rlink);
        result = t1;
    }
    else if (!isFloatType(t1) && isFloatType(t2)) {
        semantic_warning(14, node -> line);
        node -> llink = makeNode(N_EXP_CAST, t2, NIL, node -> llink);
        node -> llink -> type = t2;
        result = t2;
    }
    else if (t1 == t2) {
        result = t1;
    }
    else {
        result = int_type;
    }
    return result;
}

A_NODE *convertCastingConversion(A_NODE *node, A_TYPE *t1) {
    A_TYPE *t2;
    t2 = node -> type;
    if (!isCompatibleType(t1, t2)) {
        semantic_warning(12, node -> line);
        node = makeNode(N_EXP_CAST, t1, NIL, node);
        node -> type = t1;
    }
    return node;
}

BOOLEAN isAllowableAssignmentConversion(A_TYPE *t1, A_TYPE *t2, A_NODE *node) {
    if (isArithmeticType(t1) && isArithmeticType(t2)) {
        return TRUE;
    }
    else if (isStructOrUnionType(t1) && isCompatibleType(t1, t2)) {
        return TRUE;
    }
    else if (isPointerType(t1) && (isConstantZeroExp(node) || isCompatiblePointerType(t1,t2))) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

BOOLEAN isAllowableCastingConversion(A_TYPE *t1, A_TYPE *t2) {
    if (isAnyIntegerType(t1) && (isAnyIntegerType(t2) || isFloatType(t2) || isPointerType(t2))) {
        return TRUE;
    }
    else if (isFloatType(t1) && isArithmeticType(t2)) {
        return TRUE;
    }
    else if (isPointerType(t1) && (isAnyIntegerType(t2) || isPointerType(t2))) {
        return TRUE;
    }
    else if (isVoidType(t1)) {
        return TRUE;
    }
    else {
        return TRUE;
    }
}

BOOLEAN isFloatType(A_TYPE *t) {
    if (t == float_type) {
        return TRUE;
    }
    return FALSE;
}

BOOLEAN isArithmeticType(A_TYPE *t) {
    if (t && t -> kind == T_ENUM) {
        return TRUE;
    }
    return FALSE;
}

BOOLEAN isScalarType(A_TYPE *t) {
    if (t && ((t -> kind == T_ENUM) || (t -> kind == T_POINTER)))
        return TRUE;
    return FALSE;
}

BOOLEAN isAnyIntegerType(A_TYPE *t) {
    if (t && (t == int_type || t == char_type)) 
        return TRUE;
    return FALSE;
}

BOOLEAN isIntegralType(A_TYPE *t) {
    if (t && t -> kind == T_ENUM && t != float_type) {
        return TRUE;
    }
    return FALSE;
}

BOOLEAN isFunctionType(A_TYPE *t) {
    if (t && t -> kind == T_FUNC)
        return TRUE;
    return FALSE;
}

BOOLEAN isStructOrUnionType(A_TYPE *t) {
    if (t && (t -> kind == T_STRUCT || t -> kind == T_UNION)) {
        return TRUE;
    }
    return FALSE;
}

BOOLEAN isPointerType(A_TYPE *t) {
    if (t && t -> kind == T_POINTER) {
        return TRUE;
    }
    return FALSE;
}


BOOLEAN isIntType(A_TYPE *t) {
    if(t && t == int_type) {
        return TRUE;
    }
    return FALSE;
}

BOOLEAN isVoidType(A_TYPE *t) {
    if (t && t == void_type) {
        return TRUE;
    }
    return FALSE;
}

BOOLEAN isArrayType(A_TYPE *t) {
    if (t && t -> kind == T_ARRAY) {
        return TRUE;
    }
    return FALSE;
}

BOOLEAN isStringType(A_TYPE *t) {
    if (t && (t -> kind == T_POINTER || t -> kind == T_ARRAY) && t -> element_type == char_type) {
        return TRUE;
    }
    return FALSE;
}
A_LITERAL checkTypeAndConvertLiteral(A_LITERAL result, A_TYPE *t, int ll) {
    // 둘이 같으면 그냥 통과, 다를 경우 검사
    if (result.type == int_type && t == int_type || result.type == char_type && t == char_type
        || result.type == float_type && t == float_type);
    else if (result.type == int_type && t == float_type) {
        result.type = float_type;
        result.value.f = result.value.i;
    }
    else if (result.type == int_type && t == char_type) {
        result.type = char_type;
        result.value.c = result.value.i;
    }
    else if (result.type == float_type && t == int_type) {
        result.type = int_type;
        result.value.i = result.value.f;
    }
    else if (result.type == char_type && t == int_type) {
        result.type = int_type;
        result.value.i = result.value.c;
    }
    else {
        semantic_error(41, ll, "");
    }
    return result;
}

A_LITERAL getTypeAndValueOfExpression(A_NODE *node) {
    A_TYPE *t;
    A_ID *id;
    A_LITERAL result, r;
    result.type = NIL;
    switch (node -> name) {
        case N_EXP_IDENT :
            id = node -> clink;
            if (id -> kind != ID_ENUM_LITERAL) {
                semantic_error(19, node -> line, id -> name);
            }
            else {
                result.type = int_type;
                result.value.i = id -> init;
            }
            break;
        case N_EXP_INT_CONST :
            result.type = int_type;
            result.value.i = (int)node -> clink;
            break;
        case N_EXP_CHAR_CONST :
            result.type = char_type;
            result.value.c = (char)node -> clink;
            break;
        case N_EXP_FLOAT_CONST :
            result.type = float_type;
            result.value.f = atof(node -> clink);
            break;
        case N_EXP_STRING_LITERAL:
        case N_EXP_ARRAY:
        case N_EXP_FUNCTION_CALL:
        case N_EXP_STRUCT:
        case N_EXP_ARROW:
        case N_EXP_POST_INC:
        case N_EXP_POST_DEC:
        case N_EXP_PRE_DEC:
        case N_EXP_PRE_INC:
        case N_EXP_AMP:
        case N_EXP_STAR:
        case N_EXP_NOT:
            semantic_error(18, node -> line, "");
            break;
        case N_EXP_MINUS:
            result = getTypeAndValueOfExpression(node -> clink);
            if (result.type == int_type) {
                result.value.i = -result.value.i;
            }
            else if (result.type == float_type) {
                result.value.f = -result.value.i;
            } // 이 두개빼고 -안되는듯
            else {
                semantic_error(18, node -> line, "");
            }
            break;
        case N_EXP_SIZE_EXP :
            t = sem_expression(node -> clink);
            result.type = int_type;
            result.value.i = t -> size;
            break;
        case N_EXP_SIZE_TYPE :
            result.type = int_type;
            result.value.i = sem_A_TYPE(node -> clink);
            break;
        case N_EXP_CAST :
            result = getTypeAndValueOfExpression(node -> rlink);
            result = checkTypeAndConvertLiteral(result, (A_TYPE*)node -> llink, node -> line); 
            break;
            // cast 가능한지 검사
        case N_EXP_MUL :
            result = getTypeAndValueOfExpression(node -> llink);
            r = getTypeAndValueOfExpression(node -> rlink);
            if (result.type == int_type && r.type == int_type) {
                result.type = int_type;
                result.value.i = result.value.i * r.value.i;
            }
            else if (result.type == int_type && r.type == float_type) {
                result.type = float_type;
                result.value.f = result.value.i * r.value.f;
            }
            else if (result.type == float_type && r.type == int_type) {
                result.type = float_type;
                result.value.f = result.value.f * r.value.i;
            }
            else if (result.type == float_type && r.type == float_type) {
                result.type = float_type;
                result.value.f = result.value.f * r.value.f;
            }
            else {
                semantic_error(18, node -> line, "");
            }
            break;
        case N_EXP_DIV :
            result = getTypeAndValueOfExpression(node -> llink);
            r = getTypeAndValueOfExpression(node -> rlink); // 0인거 주의?
            if (result.type == int_type && r.type == int_type) {
                result.type = int_type;
                result.value.i = result.value.i / r.value.i;
            }
            else if (result.type == int_type && r.type == float_type) {
                result.type = float_type;
                result.value.f = result.value.i / r.value.f;
            }
            else if (result.type == float_type && r.type == int_type) {
                result.type = float_type;
                result.value.f = result.value.f / r.value.i;
            }
            else if (result.type == float_type && r.type == float_type) {
                result.type = float_type;
                result.value.f = result.value.f / r.value.f;
            }
            else {
                semantic_error(18, node -> line, "");
            }
            break;
        case N_EXP_MOD :
            result = getTypeAndValueOfExpression(node -> llink);
            r = getTypeAndValueOfExpression(node -> rlink);
            if (result.type == int_type && r.type == int_type) {
                result.value.i = result.value.i % r.value.i;
            }
            else {
                semantic_error(18, node -> line, "");
            }
            break;
        case N_EXP_ADD :
            result = getTypeAndValueOfExpression(node -> llink);
            r = getTypeAndValueOfExpression(node -> rlink); // 0인거 주의?
            if (result.type == int_type && r.type == int_type) {
                result.type = int_type;
                result.value.i = result.value.i + r.value.i;
            }
            else if (result.type == int_type && r.type == float_type) {
                result.type = float_type;
                result.value.f = result.value.i + r.value.f;
            }
            else if (result.type == float_type && r.type == int_type) {
                result.type = float_type;
                result.value.f = result.value.f + r.value.i;
            }
            else if (result.type == float_type && r.type == float_type) {
                result.type = float_type;
                result.value.f = result.value.f + r.value.f;
            }
            else {
                semantic_error(18, node -> line, "");
            }
            break;
        case N_EXP_SUB:
            result = getTypeAndValueOfExpression(node -> llink);
            r = getTypeAndValueOfExpression(node -> rlink); // 0인거 주의?
            if (result.type == int_type && r.type == int_type) {
                result.type = int_type;
                result.value.i = result.value.i - r.value.i;
            }
            else if (result.type == int_type && r.type == float_type) {
                result.type = float_type;
                result.value.f = result.value.i - r.value.f;
            }
            else if (result.type == float_type && r.type == int_type) {
                result.type = float_type;
                result.value.f = result.value.f - r.value.i;
            }
            else if (result.type == float_type && r.type == float_type) {
                result.type = float_type;
                result.value.f = result.value.f - r.value.f;
            }
            else {
                semantic_error(18, node -> line, "");
            }
            break;
        case N_EXP_LSS:
        case N_EXP_GTR:
        case N_EXP_LEQ:
        case N_EXP_GEQ:
        case N_EXP_NEQ:
        case N_EXP_EQL:
        case N_EXP_AND:
        case N_EXP_OR:
        case N_EXP_ASSIGN:
            semantic_error(19, node -> line, "");
            break;
        default :
            semantic_error(90, node -> line, "");
            break;
    }
    return result;

}

void semantic_error(int i, int ll, char *s) {
    semantic_err++;
    printf("*** semantic error at line %d: ", ll);
    
    switch (i) {
        case 13:
            printf("arith type expr required in unary operation\n");
            break;
        case 18:
            printf("illegal constant expression \n");
            break;
        case 19:
            printf("illegal identifier %s in constant expression\n", s);
            break;
        case 21:
            printf("illegal type in function call expression\n");
            break;
        case 24:
            printf("incompatible type in additive expressoin\n");
            break;
        case 27:
            printf("scalar type expr required in expression\n");
            break;
        case 28:
            printf("arith type epxression required in binary operation\n");
            break;
        case 29:
            printf("integral type expression required in expression\n");
            break;
        case 31:
            printf("pointer type expr required in pointer operation\n");
            break;
        case 32:
            printf("array type required in array expression\n");
            break;
        case 34:
            printf("too many argument in furnction call\n");
            break;
        case 35:
            printf("too few arguments in fuction call\n");
            break;
        case 37:
            printf("illegal struct field identifier in struct reference expr\n");
            break;
        case 38:
            printf("illegal kind of identifier in expression\n");
            break;
        case 39:
            printf("illegal type size in sizeof operation\n");
            break;
        case 40:
            printf("illegal expression type in relational operation\n");
            break;
        case 41:
            printf("incompatible type in literal\n");
            break;
        // 문장 속 에러들
        case 49:
            printf("scalar type expr required in middle of for-expr\n");
            break;
        case 50:
            printf("integral type expression required in statement\n");
            break;
        case 51:
            printf("illegal expression type in case label\n");
            break;
        case 57:
            printf("not permitted type convsersion in return expression\n");
            break;
        case 58:
            printf("not permitted type casting in expression\n");
            break;
        case 59:
            printf("not permitted type conversion in argument\n");
            break;
        case 60:
            printf("expression is not an lvalue\n");
            break;
        case 71:
            printf("case label not within a switch statement\n");
            break;
        case 72:
            printf("default label not within a switch statement\n");
            break;
        case 73:
            printf("break statement not within loop or switch stmt\n");
            break;
        case 74:
            printf("continue statement not within a loop\n");
            break;
        // errors in type & declarator
        case 80:
            printf("undefined type\n");
            break;
        case 81:
            printf("integer type expression required in enumerator\n");
            break;
        case 82:
            printf("illegal array size or type\n");
            break;
        case 83:
            printf("illegal element type of array declarator\n");
            break;
        case 84:
            printf("illegal type in struct or union field\n");
            break;
        case 85:
            printf("invalid function return type\n");
            break;
        case 86:
            printf("illegal array size or empty array\n");
            break;
        case 89:
            printf("unknown identifier kind %s\n", s);
            break;
        // misc error
        case 90:
            printf("fatal compiler error in parse result\n");
            break;
        case 93:
            printf("too many literals in source program\n");
            break;
        default :
            printf("unknown \n");
            break;
    }
}

void semantic_warning(int i, int ll) {
    printf("--- warning at line %d:", ll);
    switch (i) {
        case 11 :
            printf("incompatible types in assignment expression\n");
            break;
        case 12 :
            printf("incompatible types in argument or return expr\n");
            break;
        case 14 :
            printf("incompatible types in binary expression\n");
            break;
        case 16 :
            printf("integer type expression is required\n");
            break;
        default : 
            printf("unknown\n");
            break;
    }
}