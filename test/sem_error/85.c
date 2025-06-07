int hello_world(){
    return 1;
}

hello_world hello_two_world(){
    return hello_world;
}

int main(void){
    hello_two_world();
}