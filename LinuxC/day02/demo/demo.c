#include <stdio.h>
main() {
    int a = intputInt();
    int r = isPrimer(a);
    if(r) printf("%d是素数\n", a);
    else printf("%d是合数\n", a);
}
