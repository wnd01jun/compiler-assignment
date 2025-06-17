int foo(void);
int (*test)(void);
int main(void){
    test = foo;
}