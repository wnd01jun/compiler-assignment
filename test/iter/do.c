int main(void){
    int i;
    int k;
    int w;
    i = 0;
    k = 0;
    w = 0;
    do {
        k = k + i;
        w = w + k;
        i++;
    } while(i <= 10);

    printf("%d\n", w);

    return 0;
}