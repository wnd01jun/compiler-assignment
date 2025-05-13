#include <stdio.h>
#include <stdlib.h>
#include "type.h"
#include "y.tab.h"

extern char *yytext;
A_TYPE *int_type, *char_type, *void_type, *float_type, *string_type;
A_NODE *root;
A_ID *current_id = NIL;
int syntax_err = 0;
int line_no = 1;
int current_level = 0;

A_NODE *makeNode(NODE_NAME, A_NODE *, A_NODE *, A_NODE *);
A_NODE *makeNodeList(NODE_NAME, A_NODE *, A_NODE *);
A_ID *makeIdentifier(char *);
A_ID *makeDummyIdentifier();
A_TYPE *makeType(T_KIND);
A_SPECIFIER *makeSpecifier(A_TYPE *, S_KIND);
A_ID *searchIdentifier(char *, A_ID *);
A_ID *searchIdentifierAtCurrentLevel(char *, A_ID *);
A_SPECIFIER *updateSpecifier(A_SPECIFIER *, A_TYPE *, S_KIND);
void checkForwardReference();
void setDefaultSpecifier(A_SPECIFIER *, A_TYPE *, S_KIND);

A_ID *linkDeclaratorList(A_ID *,A_ID *);
A_ID *getIdentifierDeclared (char *);
A_TYPE *getTypeOfStructOrEnumRefidentifier(T_KIND,char *,ID_KIND);
A_ID *setDeclaratorInit(A_ID *,A_NODE *);
A_ID *setDeclaratorKind(A_ID *, ID_KIND);
A_ID *setDeclaratorType(A_ID *, A_TYPE *);
A_ID *setDeclaratorElementType(A_ID *,A_TYPE *);
A_ID *setDeclaratorTypeAndKind(A_ID *,A_TYPE *,ID_KIND);
A_ID *setDeclaratorListSpecifier(A_ID *,A_SPECIFIER *);
A_ID *setFunctionDeclaratorSpecifier(A_ID *, A_SPECIFIER *);
A_ID *setFunctionDeclaratorBody(A_ID *, A_NODE *);
A_ID *setParameterDeclaratorSpecifier(A_ID *, A_SPECIFIER *);
A_ID *setStructDeclaratorListSpecifier(A_ID *, A_TYPE *);
A_TYPE *setTypeNameSpecifier(A_TYPE *, A_SPECIFIER *);
A_TYPE *setTypeElementType(A_TYPE *, A_TYPE *);
A_TYPE *setTypeField(A_TYPE *,A_ID *);
A_TYPE *setTypeExpr(A_TYPE *, A_NODE *);
A_TYPE *setTypeAndKindOfDeclarator(A_TYPE *, ID_KIND, A_ID *);
A_TYPE *setTypeStructOrEnumIdentifier(T_KIND, char *, ID_KIND);
BOOLEAN isNotSameFormalParameters(A_ID *, A_ID *);
BOOLEAN isNotSameType(A_TYPE *, A_TYPE *);
BOOLEAN isPointerOrArrayType(A_TYPE *);
void syntax_error();
void initialize();

A_NODE *makeNode(NODE_NAME n, A_NODE *a, A_NODE *b, A_NODE *c) {
    A_NODE *m; // A_NODE는 자식 3개를 가질 수 있는 node 보통 가운데는 identifier
    // right, left는 expression이나 statement 연결
    m = (A_NODE*)malloc(sizeof(A_NODE)); // A_NODE 동적 할ㅏ
    m -> name = n; // 이름 설정
    m -> llink = a;
    m -> clink = b;
    m -> rlink = c;
    m -> type = NIL; // 정수형이나 그런거일 때 쓰나?
    m -> line = line_no;
    m -> value = 0;
    return (m);
}

A_NODE *makeNodeList(NODE_NAME n, A_NODE *a, A_NODE *b) {
    A_NODE *m, *k;
    k = a;
    while (k -> rlink) { // a의 rlink 끝으로 가서
        k = k -> rlink;
    }
    m = (A_NODE *)malloc(sizeof(A_NODE));
    m -> name = k -> name;
    m -> llink = NIL;
    m -> clink = NIL;
    m -> rlink = NIL;
    m -> type = NIL;
    m -> line = line_no;
    m -> value = 0;
    k -> name = n;
    k -> llink = b; // k의 llink는 b
    k -> rlink = m; // k의 rlink는 m (근데 k랑 이름 공유))
    // a의 오른쪽 끝 노드에 이름이 동일한 노드 m을 만들고, 왼쪽에 b, 오른쪽에 m을 연결
    return (a);
}

// 걍 기본적인 Identifier 하나 생성, current_id 변경시킴
A_ID *makeIdentifier(char *s) {
    A_ID *id;
    id = (A_ID *)malloc(sizeof(A_ID));
    id -> name = s;
    id -> kind = 0; 
    id -> specifier = 0;
    id -> level = current_level;
    id -> address = 0;
    id -> init = NIL;
    id -> type = NIL;
    id -> link = NIL;
    id -> line = line_no;
    id -> value = 0;
    id -> prev = current_id;
    current_id = id;
    return (id);
}

// 아마 이름 없는 얘 만들 때 사용하는듯 하다.
A_ID *makeDummyIdentifier() {
    A_ID *id;
    id = (A_ID *)malloc(sizeof(A_ID));
    id -> name = "";
    id -> kind = 0; 
    id -> specifier = 0;
    id -> level = current_level;
    id -> address = 0;
    id -> init = NIL;
    id -> type = NIL;
    id -> link = NIL;
    id -> line = line_no;
    id -> value = 0;
    id -> prev = 0;
    current_id = id;
    return (id);
}


// A_TYPE 생성, 배열, 포인터 이런 얘들도 들어와야 하므로 field가 다양한듯
A_TYPE *makeType(T_KIND k) {
    A_TYPE *t;
    t = (A_TYPE *)malloc(sizeof(A_TYPE));
    t -> kind = k;
    t -> size = 0;
    t -> local_var_size = 0;
    t -> element_type = NIL;
    t -> field = NIL;
    t -> expr = NIL;
    t -> check = FALSE;
    t -> prt = FALSE;
    t -> line = line_no;
    return (t);
}

// storage_class랑, type 가리키는 specifier 생성
A_SPECIFIER *makeSpecifier(A_TYPE *t, S_KIND s) {
    A_SPECIFIER *p;
    p = (A_SPECIFIER*)malloc(sizeof(A_SPECIFIER));
    p -> type = t;
    p -> stor = s;
    p -> line = line_no;
    return p;
}

// 이름 s로 search
A_ID *searchIdentifier(char *s, A_ID *id) {
    while(id) {
        if (strcmp(id -> name, s) == 0) {
            break;
        }
        id = id -> prev;
    }
    return id;
}

// current_level에 해당하는 얘들 중에서만 search
A_ID *searchIdentifierAtCurrentLevel(char *s, A_ID *id) {
    while(id) {
        if(id -> level < current_level) {
            return NIL;
        }
        if(strcmp(id -> name, s) == 0) {
            break;
        }
        id = id -> prev;
    }
    return id;
}

// current_id 부터 전방참조 검사
void checkForwardReference() {
    A_ID *id;
    A_TYPE *t;
    id = current_id;
    while(id) {
        if (id -> level < current_level) {
            break;
        }
        t = id -> type;
        if(id -> kind == ID_NULL) {
            syntax_error(31, id -> name);
        } else if ((id -> kind == ID_STRUCT || id -> kind == ID_ENUM)
                 && t -> field == NIL){
            syntax_error(32, id -> name);
        }
        id = id -> prev;
    }
}

// default 없고, type 있어야하는걸로 명시
void setDefaultSpecifier(A_SPECIFIER *p) {
    A_TYPE *t;
    if (p -> type == NIL) {
        syntax_error() // type_specifier는 반드시 있어야한다.
    }
    if (p -> stor == S_NULL) {
        p -> stor = S_AUTO // 없으면 자동으로 AUTO
    }
}

A_SPECIFIER *updateSpecifier(A_SPECIFIER *p, A_TYPE *t, S_KIND s) {
    if (t) {
        if (p -> type) {
            if (p -> type == t) {
                ;
            } else {
                syntax_error(24, ""); // type은 바꿀 수 없다.
            }
        } else {
            p -> type = t; // NIL일 때만 바꿀 수 있음
        }
    }
    if (s) {
        if (p -> stor) {
            if (s == p -> stor) {
                ;
            } else {
                syntax_error(24, ""); // 얘도 정해진게 있으면 못바꾸낟.
            }
        } else {
            p -> stor = s;
        }
    }
    return p;
}

A_ID *linkDeclaratorList(A_ID *id1, A_ID *id2) {
    A_ID * m = id1;
    if (id1 == NIL) {
        return id2;
    }
    while (m -> link) {
        m = m -> link;
    }
    m -> link = id2; // link 끝에 연결
    return id1;
}

// current_id 부터 얘가 declared 되었는지 검사
A_ID *getIdentifierDeclared(char *s) {
    A_ID *id;
    id = searchIdentifier(s, current_id);
    if (id == NIL) {
        syntax_error(13, s);
    }
    return id;
}

A_TYPE *getTypeOfStructOrEnumRefidentifier(T_KIND k, char *s, ID_KIND kk) {
    A_TYPE *t;
    A_ID *id;
    id = searchIdentifier(s, current_id); // 이름으로부터 Identifier 찾아서
    if (id) { // id가 있을 경우에
        if (id -> kind == kk && id -> type -> kind == k) {
            return id -> type; // 얘네 id_kind랑 type->kind가 kk, k가 맞는지 검사
        } else {
            syntax_error(11, s); // 다른 이름, type으로 이미 선언된 것이므로 syntax error
        }
    }
    t = makeType(k); // 없으면 직접 만든다
    id = makeIdentifier(s);
    id -> kind = kk;
    id -> type = t;
    return t;
}

// init에 node를 연결
A_ID *setDeclaratorInit(A_ID *id, A_NODE *n) {
    id -> init = n;
    return id;
}

A_ID *setDeclaratorKind(A_ID *id, ID_KIND k) {
    A_ID *a;
    a = searchIdentifierAtCurrentLevel(id -> name, id -> prev); // 중복검사
    if (a) {
        syntax_error(12, id -> name);
    }
    id -> kind = k;
    return id;
}

A_ID *setDeclaratorType(A_ID *id, A_TYPE *t) {
    id -> type = t;
    return id;
}

// 타입이 여러개로 막 pointer array 이루어진 얘들 끝의 type을 설정해주기 위해 하는듯
A_ID *setDeclaratorElementType(A_ID *id, A_TYPE *t) {
    A_TYPE *tt;
    if (id -> type == NIL) {
        id -> type = t;
    } else {
        tt = id -> type;
        while (tt -> element_type) {
            tt = tt -> element_type;
        }
        tt -> element_type = t;
    }
    return id;
}

// 2개 동시에 하게 해주는 추상화
A_ID *setDeclaratorTypeAndKind(A_ID *id, A_TYPE *t, ID_KIND k) {
    id = setDeclaratorElementType(id, t);
    id = setDeclaratorKind(id, k);
    return id;
}

A_ID *setFunctionDeclaratorSpecifier(A_ID *id, A_SPECIFIER *p) {
    A_ID *a;

    if (p -> stor) {
        syntax_error(25, ""); // 함수는 stroage class를 가지면 안된다.
    }
    setDefaultSpecifier(p); 

    if (id -> type -> kind != T_FUNC) { // 뭔가 여기서 에러뜰거같은데??
        syntax_error(21, "");
        return id;
    } else {
        id = setDeclaratorElementType(id, p -> type); // 끝에 연결
        id -> kind = ID_FUNC;
    }

    a = searchIdentifierAtCurrentLevel(id -> name, id -> prev);
    if (a) { // 전방검사
        if (a -> kind != ID_FUNC || a -> type -> expr) { // expr이 또 있으면 안된다.
            syntax_error(12, id -> name);
        } else {
            if (isNotSameFormalParameters(a -> type -> field, id -> type -> field)) {
                syntax_error(22, id -> name);
            }
            if (isNotSameType(a -> type -> element_type, id -> type -> element_type)) {
                syntax_error(26, a -> name);
            }
        }
    }
    a = id -> type -> field;
    while (a) { // 스코프가 벗어나 있으므로, 파라미터가 다시 들어갈 수 있도록 해야한다.
        if (strlen(a -> name)) {
            current_id = a;
        } else if (a -> type) { // type이 있는데, 이름이 없으면 에러
            syntax_error(23, ""); 
        }
        a = a -> link;
    }
    return id;
}

A_ID *setFunctionDeclaratorBody(A_ID *id, A_NODE *n) {
    id -> type -> expr = n; // statement 연결
    return id;
}

A_ID *setDeclaratorListSpecifier(A_ID *id, A_SPECIFIER *p) {
    A_ID *a;
    setDefaultSpecifier(p);
    a = id;
    while (a) {
        if (strlen(a -> name) && searchIdentifierAtCurrentLevel(a -> name, a -> prev)) {
            syntax_error(12, a -> name);
        }
        if (p -> stor == S_TYPEDEF) {
            a -> kind = ID_TYPE;
        } else if (a -> type -> kind == T_FUNC) {
            a -> kind = ID_FUNC;
        } else {
            a -> kind = ID_VAR;
        }
        a -> specifier = p -> stor;
        if (a -> specifier == S_NULL) {
            a -> specifier = S_AUTO;
        }
        a = a -> link;
    }
    return id;
}

A_ID *setParameterDeclaratorSpecifier(A_ID *id, A_SPECIFIER *p) {
    if (searchIdentifierAtCurrentLevel(id -> name, id -> prev)) {
        syntax_error(12, id -> name);
    }
    if (p -> stor || p -> type == void_type) { // void는 declarator가 있으면 안되므로...
        syntax_error(14, id -> name);
    }
    setDefaultSpecifier(p);
    id = setDeclaratorElementType(id, p -> type);
    id -> kind = ID_PARM;
    return id;
}

A_ID *setStructDeclaratorListSpecifier(A_ID *id, A_TYPE *t) {
    A_ID *a;
    a = id;
    while (a) {
        if (searchIdentifierAtCurrentLevel(a -> name, a -> prev)) {
            syntax_error(12, a -> name);
        }
        a = setDeclaratorElementType(a, t);
        a -> kind = ID_FIELD;
        a = a -> link;
    }
    return id;
}

// specifier에 type mapping
A_TYPE *setTypeNameSpecifier(A_TYPE *t, A_SPECIFIER *p) {
    if (p -> stor) {
        syntax_error(20, ""); // type name mapping하는데 storage class 비허용
    }
    setDefaultSpecifier(p);
    t = setTypeElementType(t, p -> type);
    return t;
}

A_TYPE *setTypeElementType(A_TYPE *t, A_TYPE *s) {
    A_TYPE *q;
    if (t == NIL) {
        return s;
    }
    q = t;
    while (q -> element_type) {
        q = q -> element_type;
    }
    q -> element_type = s;
    return t;
}

A_TYPE *setTypeField(A_TYPE *t, A_ID *n) {
    t -> field = n;
    return t;
}

A_TYPE *setTypeExpr(A_TYPE *t, A_NODE *n) {
    t -> expr = n;
    return t;
}

A_TYPE *setTypeStructOrEnumIdentifier(T_KIND k, char *s, ID_KIND kk) {
    A_TYPE *t;
    A_ID *id, *a;

    a = searchIdentifierAtCurrentLevel(s, current_id);
    if (a) {
        if (a -> kind == kk && a -> type -> kind == k) {
            if (a -> type -> field) { // field가 정의되어있으면 앞에 정의부가 이미 나온거 이므로 에러!
                syntax_error(12, s);
            } else { // 여기는 왜 리턴이지? 선언이 한번 더 나온걸로 치는듯? identifier는 있으니까
                return a -> type;
            }
        } else { // 같은 이름의 다른 용도로 사용 중 이므로
            syntax_error(12, s);
        }
    }
    id = makeIdentifier(s);
    t = makeType(k);
    id -> type = t;
    id -> kind = kk;
    return t;
}

A_TYPE *setTypeAndKindOfDeclarator(A_TYPE *t, ID_KIND k, A_ID *id) {
    if (searchIdentifierAtCurrentLevel(id -> name, id -> prev)) {
        syntax_error(12, id -> name);
    }
    id -> type = t;
    id -> kind = k;
    return t;
}

// 파라미터 다른지 같은지 비교
BOOLEAN isNotSameFormalParameters(A_ID *a, A_ID *b) {
    if (a == NIL) { // 프로토 타입에 파라미터가 없다!
        return FALSE;
    }
    while (a) {
        if (b == NIL || isNotSameType(a -> type, b -> type)) {
            return TRUE;
        }
        a = a -> link;
        b = b -> link;
    }
    if (b) {
        return TRUE;
    }
    return FALSE;
}

BOOLEAN isNotSameType(A_TYPE *t1, A_TYPE *t2) {
    if (isPointerOrArrayType(t1) || isPointerOrArrayType(t2)) {
        return isNotSameType(t1 -> element_type, t2 -> element_type); // 둘다 pointer면 재귀적으로 탐사
    } else {
        return t1 != t2;
    }
}

// 초기화 과정, 기본 type이랑, printf, scanf, malloc 기본 함수로 등록
void initialize() {
    int_type = setTypeAndKindOfDeclarator(
        makeType(T_ENUM), ID_TYPE, makeIdentifier("int")
    );
    float_type = setTypeAndKindOfDeclarator(
        makeType(T_ENUM), ID_TYPE, makeIdentifier("float")
    );
    char_type = setTypeAndKindOfDeclarator(
        makeType(T_ENUM), ID_TYPE, makeIdentifier("char")
    );
    void_type = setTypeAndKindOfDeclarator(
        makeType(T_ENUM), ID_TYPE, makeIdentifier("void")
    );
    string_type = setTypeElementType(makeType(T_POINTER), char_type);
    int_type -> size = 4; int_type -> check = TRUE;
    float_type -> size = 4; float_type -> check = TRUE;
    char_type -> size = 1; char_type -> check = TRUE;
    void_type -> size = 0; void_type -> check = TRUE;
    string_type -> size = 4; string_type -> check = TRUE;

    setDeclaratorTypeAndKind( // printf Identifier랑 type 만들고, kind 설정까지 한 번에
        makeIdentifier("printf"),
        setTypeField(
            setTypeElementType(makeType(T_FUNC), void_type),
            linkDeclaratorList(
                setDeclaratorTypeAndKind(makeDummyIdentifier(), string_type, ID_PARM),
                    setDeclaratorKind(makeDummyIdentifier(), ID_PARM)
            )
        ), ID_FUNC
    );

    setDeclaratorTypeAndKind( // printf Identifier랑 type 만들고, kind 설정까지 한 번에
        makeIdentifier("scanf"),
        setTypeField(
            setTypeElementType(makeType(T_FUNC), void_type),
            linkDeclaratorList(
                setDeclaratorTypeAndKind(makeDummyIdentifier(), string_type, ID_PARM),
                    setDeclaratorKind(makeDummyIdentifier(), ID_PARM)
            )
        ), ID_FUNC
    );

    setDeclaratorTypeAndKind( // printf Identifier랑 type 만들고, kind 설정까지 한 번에
        makeIdentifier("malloc"),
        setTypeField(
            setTypeElementType(makeType(T_FUNC), string_type),
            setDeclaratorTypeAndKind(makeDummyIdentifier(), int_type, ID_PARM)
        ), ID_FUNC
    );
}

void syntax_error(int i, char *s) {
    syntax_err++;
    printf("line %d: syntax error: ", line_no);

    switch (i) {
        case 11 : 
            printf("illegal referencing struct or union identifier %s", s);
            break;
        case 12 : 
            printf("redeclaration of identifier %s", s);
            break;
        case 13 : 
            printf("undefined identifier %s", s);
            break;
        case 14 : 
            printf("illegal type specifier in formal parameter %s", s);
            break;
        case 20 : 
            printf("illegal storage class in type specifiers %s", s);
            break;
        case 21 : 
            printf("illegal function declarator %s", s);
            break;
        case 22 : 
            printf("conflicting param type in prototype function %s", s);
            break;
        case 23 : 
            printf("empty parameter name %s", s);
            break;
        case 24 : 
            printf("illgal declaration specifiers %s", s);
            break;
        case 25 : 
            printf("illgal function specifiers %s", s);
            break;
        case 26 : 
            printf("illgal or conflicting return type in function %s", s);
            break;
        case 31 : 
            printf("undefined type for identifier %s", s);
            break;
        case 32 : 
            printf("incomplete forward reference for identifier %s", s);
            break;
        default : 
            printf("unknown %s", s);
            break;  
    }
    printf("\n");

    if (strlen(yytext) == 0) {
        printf(" at end\n");
    } else {
        printf(" near %s\n", yytext);
    }
}