#include <stdlib.h>
#include <stdio.h>
main() {
    char *val=getenv("PATH");
    printf("%s\n", val);
}
