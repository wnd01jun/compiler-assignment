#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define NUMBER 256
#define PLUS 257
#define STAR 258
#define RPAREN 260
#define END 261
#define LPAREN 259
#define EXPRESSION 0
#define TERM 1
#define FACTOR 2
#define ACC 999

// 과제 제출 화면 촬영시, terminal에서 진행할 것

struct TT {
    bool isint; // int = true, float = false;
    union a {
        int i;
        float f;
    } value;
} typedef TT;

int action[12][6] = {
    {5, 0, 0, 4, 0, 0}, {0, 6, 0, 0, 0 , ACC}, {0, -2, 7, 0, -2, -2},
    {0, -4, -4, 0, -4, -4}, {5, 0, 0, 4, 0, 0}, {0, -6, -6, 0, -6, -6},
    {5, 0, 0, 4, 0, 0}, {5, 0, 0, 4, 0, 0}, {0, 6, 0, 0, 11, 0},
    {0, -1, 7, 0, -1, -1}, {0, -3, -3, 0, -3, -3}, {0, -5, -5, 0, -5, -5}
};

int go_to[12][3] = {
    {1,2,3},{0,0,0}, {0,0,0},{0,0,0},{8,2,3},{0,0,0},{0,9,3},{0,0,10},{0,0,0},{0,0,0},{0,0,0},{0,0,0}
};

int prod_left[7] = {0, EXPRESSION, EXPRESSION, TERM, TERM, FACTOR, FACTOR};
int prod_length[7] = {0,3,1,3,1,3,1};

int sym;
TT yylval;
bool check_warn;

struct {
    int stk[1000];
    int top;
} typedef int_stk;

struct {
    TT stk[1000];
    int top;

} typedef TT_stk;

int_stk state_stk;
TT_stk val_stk;
void int_push(int a);
void int_pop(int count);
int int_top();
void TT_push(TT a);
void TT_pop();
TT TT_top();
TT TT_plus(TT a, TT b);
TT TT_star(TT a, TT b);
void init();
TT yyparse();
int yylex();
void shift(int i);
void reduce(int i);
void yyerror(char *s);
void print_TT(TT a);
TT yyparse();
void print_warn();

int main() {
    TT result = yyparse();
    print_TT(result);

    return 0;
}
void int_push(int a){
    state_stk.stk[++state_stk.top] = a;
}

void int_pop(int count){
    state_stk.top -= count;
}

int int_top(){
    return state_stk.stk[state_stk.top];
}

void TT_push(TT a){
    val_stk.stk[++val_stk.top] = a;
}

void TT_pop(){
    val_stk.top--;
}

TT TT_top(){
    return val_stk.stk[val_stk.top];
}

TT TT_plus(TT a, TT b){
    if(a.isint && b.isint){
        a.value.i += b.value.i;
        return a;
    }
    else if(a.isint && !b.isint){
        b.value.f += (float)a.value.i;
        print_warn();
        return b;
    }
    else if(!a.isint && b.isint){
        a.value.f += (float)b.value.i;
        print_warn();
        return a;
    }
    else{
        a.value.f += b.value.f;
        return a;
    }
}

TT TT_star(TT a, TT b){
    if(a.isint && b.isint){
        a.value.i *= b.value.i;
        return a;
    }
    else if(a.isint && !b.isint){
        b.value.f *= (float)a.value.i;
        print_warn();
        return b;
    }
    else if(!a.isint && b.isint){
        a.value.f *= (float)b.value.i;
        print_warn();
        return a;
    }
    else{
        a.value.f *= b.value.f;
        return a;
    }
}

void init(){
    state_stk.top = -1;
    val_stk.top = -1;
    check_warn = true;
}




TT yyparse() {
    int i;
    init();
    int_push(0);
    sym = yylex();
    do {
        i = action[int_top()][sym-256];
        if(i == ACC)
            printf("success \n");
            else if(i > 0) shift(i);
            else if(i < 0) reduce(-i);
            else yyerror("action table error");
    } while(i != ACC);
    return TT_top();
}

void shift(int i){
    int_push(i);
    sym = yylex();
}

void reduce(int i){ // 규칙 번호에 따라 다른 일을 수행해야함 연산이 필요한 부분이 있을 수 있음
    int old_top;
    int rule_length = prod_length[i];
    int_pop(rule_length);
    old_top = int_top();
    int_push(go_to[int_top()][prod_left[i]]);

    if(i == 1){
        TT tmp1, tmp2;
        tmp1 = TT_top();
        TT_pop();
        tmp2 = TT_top();
        TT_pop();
        TT_push(TT_plus(tmp1, tmp2));
    }
    else if(i == 2){
        ;
    }
    else if(i == 3){
        TT tmp1, tmp2;
        tmp1 = TT_top();
        TT_pop();
        tmp2 = TT_top();
        TT_pop();
        TT_push(TT_star(tmp1, tmp2));
    }
    else if(i == 4){
        ;
    }
    else if(i == 5){
        ;
    }
    else if(i == 6){
        ;
    }
    else{
        yyerror("parsing table error");
    }
    return;
}

void yyerror(char *s){
    printf("%s\n", s);
    exit(1);
}

int yylex() {
    static char ch = ' ';
    int i = 0;
    while(ch == ' ' || ch == '\t' || ch == '\n') ch = getchar();
    if(isdigit(ch)){
        char arr[1001];
        int top = -1;
        do {
            arr[++top] = ch;
            ch = getchar();
        } while(isdigit(ch));
        TT tmp;
        if(ch == '.'){
            do {
                arr[++top] = ch;
                ch = getchar();
            } while(isdigit(ch));
            if(ch == '.') yyerror("wrong token"); // 실수 판정 중에는 . 이 2개 이상 등장해선 안된다.
            arr[++top] = '\0';
            tmp.isint = false;
            tmp.value.f = atof(arr);
        }
        else{
            arr[++top] ='\0';
            tmp.isint = true;
            tmp.value.i = atoi(arr);
        }
        yylval = tmp;
        TT_push(yylval);
        return NUMBER;
    }
    else if(ch == '+'){
        ch = getchar();
        return PLUS;
    }
    else if(ch == '*'){
        ch = getchar();
        return STAR;
    }
    else if(ch == '('){
        ch = getchar();
        return LPAREN;
    }
    else if(ch == ')'){
        ch = getchar();
        return RPAREN;
    }
    else if(ch == EOF){
        return END;
    }
    else{
        yyerror("Undefined token");
    }
}


void print_TT(TT a){
    if(a.isint){
        printf("answer : %d\n",a.value.i);
    }
    else{
        printf("answer : %f\n",a.value.f);
    }
    return;
}

void print_warn(){
    if(check_warn){
        check_warn = false;
        printf("Waring !! this expression is hybride expression of int and float!\n");
    }
}
