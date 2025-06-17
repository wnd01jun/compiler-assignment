int divnq(int s, int e) {
    int i;
    int sum;
    sum = 0;
    for(i = s; i <= e; i++){
        sum = sum + i;
    }

    return sum;
}

int main(void) {
    int sum;
    sum = 0;
    
    sum = sum + divnq(1, 25);
    sum = sum + divnq(26, 50);
    sum = sum + divnq(51, 75);
    sum = sum + divnq(76, 100);
    
    printf("sum : %d\n", sum);

    return 0;
}