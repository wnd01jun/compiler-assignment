union fund {
    int won;
    float dollor;
};

struct bank_address {

    int id;
    char *user_name;
    char *bank_name;
    union fund money;
};

int main(void) {
    struct bank_address test;

    char *name = "lee";
    char *bank_name = "woori";
    union fund f;
    f.won = 100;
    
    test.user_name = name;
    test.bank_name = bank_name;
    test.money = f;
}