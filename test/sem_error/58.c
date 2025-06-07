struct s {
    int a;
    int b;
};

struct e {
    int c;
    int d;
};

int main(void){
    struct s a;
    int b;
    int c;
    c = b * (struct e)a;
}