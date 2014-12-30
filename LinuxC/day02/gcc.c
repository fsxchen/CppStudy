int printf(const char*, ...);
int add(int * restrict a, int * restrict b) {   //严格限制，提高速度，类似与一般变量的register
    return (*a) + (*b);
}
main() {
    // printf("%d\n", NUM);
    // //gcc gcc.c -omain -DNUM=56
    for(int i=0; i < 100; i++){
        printf("%d\n", i);
    }


}
