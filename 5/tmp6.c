#include "type.h"



void sem_arg_expr_list(A_NODE *node, A_ID *id) { // function call에 들어있는, arg list들
    A_TYPE *t; // 함수정의부 id랑 call에 쓰인 node랑 비교하는듯?
    A_ID *a;
    int arg_size = 0;
    switch(node -> name) {
        case N_ARG_LIST :
            if (id == 0) {
                semantic_error(34, node -> line);
            }
            else {
                if (id -> type) {
                    t = sem_expression(node -> llink) ;
                    node -> llink = convertUsualUnaryConversion(node -> llink);
                    if (isAllowableCastingConversion(id -> type, node -> llink -> type)) {
                        node -> llink = convertCastingConversion(node -> llink, id -> type);
                    }
                    else {
                        semantic_error(59, node -> line);
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
                semantic_error(35, node -> line);
            }
            break;
        default:
            semantic_error(90, node -> line);
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
                semantic_error(71, node -> line);
            }
            lit = getTypeAndValueOfExpression(node -> llink); // type 및 연산까지 가져오는듯?
            if (isIntegralType(lit.type)) {
                node -> llink = lit.value.i; // expression에 값 할당
            }
            else {
                semantic_error(51, node -> line);
            }
            local_size = sem_statement(node -> rlink, addr, ret, sw, brk, cnt); // 다음꺼 재귀적으로 호출
            break;
        case N_STMT_LABEL_DEFAULT:
            if (sw == FALSE) {
                semantic_error(72, node -> line);
            }
            local_size = sem_statement(node -> clink, addr, ret, sw, brk, cnt);
            break; // 딱히 볼게 없는듯? default는
        case N_STMT_COMPOUND: // 복합문
            if (node -> llink) {
                local_size = sem_declaration_list(node -> llink, addr); // llink는 declaration_list
                local_size += sem_statement_list(node -> rlink, local_size + addr, ret, sw, brk, cnt); // rlink는 statmement_list
                
            }
            break;
        case N_STMT_EMPTY:
            break;
        case N_STMT_EXPRESSION:
            t = sem_expression(node -> clink); // 수식 평가
            break;
        case N_STMT_IF:
            t = sem_expression(node -> llink); // llink 수식
            if (isSclarType(t)) { // 수식은 스칼라만 허용
                node -> llink = convertSclarToInteger(node -> llink);    
            }
            else {
                semantic_error(50, node -> line);
            }
            local_size = sem_statement(node -> rlink, addr, ret, FALSE, brk, cnt); // rlink는 statement
            break;
        case N_STMT_IF_ELSE:
            t = sem_expression(node -> llink);
            if (isSclarType(t)) { // 수식은 스칼라만 허용
                node -> llink = convertSclarToInteger(node -> llink);    
            }
            else {
                semantic_error(50, node -> line);
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
                semantic_error(50, node -> line);
            }
            local_size = sem_statement(node -> rlink, addr, ret, TRUE, TRUE, cnt);
            break;
        case N_STMT_WHILE:
            t = sem_expression(node -> llink);
            if (isScalarType(t)) {
                node -> llink = convertScalarToInteger(node -> llink);
            }
            else {
                semantic_error(50, node -> line);
            }
            local_size = sem_statement(node -> rlink, addr, ret, FALSE, TRUE, TRUE);
            break;
        case N_STMT_DO:
            local_size = sem_staement(node -> llink, addr, ret, FALSE, TRUE, TRUE);
            t = sem_expression(node -> rlink);
            if (isScalarType(t)) {
                node -> rlink = convertScalarToInteger(node -> rlink);
            }
            else {
                semantic_error(50, node -> line);
            }
            break;
        case N_STMT_FOR:
            sem_for_expression(node -> llink); // 얘는 3개가 묶여있음
            // for문도 우리가 평소 쓰는 for(int i) << 이거 안됌(expression만 되므로) 그래서 local_size 안가져옴
            local_size = sem_statement(node -> rlink, addr, ret, FALSE, TRUE, TRUE);
            break;
        case N_STMT_CONTINUE:
            if (cnt == FALSE) {
                semantic_error(74, node -> line);
            }
            break;
        case N_STMT_BREAK:
            if (brk == FALSE) {
                semantic_error(73, node -> line);
            }
            break;
        case N_STMT_RETURN:
            if (node -> clink) {
                t = sem_expression(node -> clink);
                if (isAllowableCastingConversion(ret, t)) {
                    node -> clink = convertCastingConversion(node -> clink, ret);
                }
                else {
                    semantic_error(57, node -> line);
                }
            }
            break;
        default:
            semantic_error(90, node -> line);
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
                    semantic_error(49, node -> line);
                }
            }
            if (node -> rlink) {
                t = sem_expression(node -> rlink);
            }
            break;
        default:
            semantic_error(90, node -> line);
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
            semantic_error(90, node -> line);
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
            semantic_error(80, t -> line);
            break;
        case T_ENUM:
            i = 0;
            id = t -> field;
            while (id) {
                if (id -> init) {
                    lit = getTypeAndValueOfExpression(id -> init);
                    if (!isIntType(lit.type)) {
                        semantic_error(81, id -> line);
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
                    semantic_error(82, t -> line);
                    t -> expr = 0;
                }
                else {
                    t -> expr = lit.value.i;
                }
                i = sem_A_TYPE(t -> element_type) * (int)t -> expr; // 원소타입의 크기 * expr의 크기
                if (isVoidType(t -> element_type) || isFunctionType(t -> element_type)) {
                    semantic_error(83, t -> line); // 순서 위로 올려도 될꺼 같음
                }
                else {
                    result = i;
                }
            }
            else { // 무조건 expr이 존재해야한다 우리 프로그램에서는
                semantic_error(83, t -> line);
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
                    result = 0;
                }
                id = id -> link; // 제일 큰 값 지정
            }
            break;
        case T_FUNC:
            tt = t -> element_type;
            i = sem_A_TYPE(tt);
            if (isArrayType(tt) || isFunctionType(tt)){ // return type check
                semantic_error(85, t -> line);
            }
            i = sem_declaraton_list(t -> field,12) + 12; // parameter check 12는 왜 더하지?
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
            semantic_error(90, t -> line);
            break;

    }
    t -> size = result;
    return result;
    
}