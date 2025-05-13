void fibo(int num) {
    int a = 1, b = 1, c, i;
    for (i = 1; i < num; i++) {
        c = (a + b) % 15746;
        a = b;
        b = c;
    }
    printf("%d", b);
}

int main(void) {
    int num;
    scanf("%d", &num);
    fibo(num);
    return 0;
}