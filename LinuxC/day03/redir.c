#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int fd;
    printf("Hello\n");
    write(1,"World\n",6);
    fd=open("/dev/tty",O_WRONLY);
    if(isatty(1)){
        write(1,"notredir\n",9);
    }else{
        write(1,"redir\n",6);
    }
    write(fd,"Killer\n",7);
}
