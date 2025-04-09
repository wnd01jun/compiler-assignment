#include <stdio.h>

int num = 0;
enum {NUL,NUM,PLUS,STAR,LP,RP,END} token;
char tmp = ' '; // NUM 탐색 시, 숫자가 아닌 다른 연산자를 만났을 때 해당 값을 임시로 저장한다.

int expression();
int term();
int factor();
void get_token();
void error(int i);

int main(){
    int result;
    get_token();
    result = expression();
    if (token!=END)
        error(3);
    else
        printf("%d\n", result);
    
    return 0;

}

int expression(){
    int result;
    result = term();
    while (token==PLUS){
        get_token();
        result+=term();
    }
    return result;
}

int term(){
    int result;
    result = factor();
    while (token==STAR){
        get_token();
        result=result*factor();
    }
    
    return result;
}

int factor(){
    int result;
    if(token==NUM){
        result=num;
        get_token();
    }
    else if(token == LP){
        get_token();
        result = expression();
        if(token==RP)
            get_token();
        else
            error(2);
    }
    else{
        error(1);
    }
    return result;
}

void get_token(){
    char ch;
    /*
        tmp에는 임시로 연산자를 저장하는데, 임시로 저장한 연산자가 없다면 getchar()를 통해 다음 문자를 읽어오고, 저장된 문자가
        있다면 tmp로부터 꺼내서 ch에 할당한다.
    */
    if(tmp == ' ')
        ch = getchar();
    else{
        ch = tmp;
        tmp = ' ';
    }
    
    /*
        공백을 제거하기 위해 공백을 만나면 while문을 공백이 끝날 때 까지 반복한다.
    */
    while(ch == ' '){
        ch = getchar();
    }

    if(ch == '+'){
        token = PLUS;
    }
    else if(ch == '*'){
        token = STAR;
    }
    else if(ch == '('){
        token = LP;
    }
    else if(ch == ')'){
        token = RP;
    }
    else if(ch == EOF || ch == '\n'){
        token = END;
    }
    else if(ch >= '0' && ch <= '9'){
        token = NUM;
        num = 0;
        /*
            문자열 '0' 이상, '9'이하일 경우에는 숫자로 판단한다.
            숫자가 끝나고 다른 연산자가 나올 떄 까지 반복하고, 다른 연산자는 tmp에 저장한다.
            num에 10배를 곱하고 ch에 '0'을 빼고 더하는 방식으로 num을 구한다.
        */
        while(ch >= '0' && ch <= '9'){
            num *= 10;
            num += (ch - '0');
            ch = getchar();
        }
        tmp = ch;
    }
    return;
}

void error(int i){
    switch(i) {
        case 1:
            printf("[Error] Factor에서 NUM외에 다른 token이 입력되었습니다.");
            break;
        case 2:
            printf("[Error] ( (LP) 등장 이후, )(RP)가 등장하지 않았습니다.");
            break;
        case 3:
            printf("[Error] Expression 종료 후, EOF(END)가 반환되지 않았습니다.");
            break;
    }
    return;
}