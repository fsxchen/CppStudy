#include <termios.h>
#include <stdio.h>
#include <stdlib.h>


/*通过设置终端的属性,~ECHO,来处理密码*/
int PASSWORD_LEN = 8;
int main() {
    struct termios initialrsettings, newrsetting;
    char password[PASSWORD_LEN];

    tcgetattr(fileno(stdin), &initialrsettings);
    newrsetting = initialrsettings;
    newrsetting.c_lflag &= ~ECHO;

    printf("Enter password: ");
    if(tcsetattr(fileno(stdin), TCSAFLUSH, &newrsetting) != 0) {
        fprintf(stderr, "Could not set attributes\n");
    } else {
        fgets(password, PASSWORD_LEN, stdin);
        tcsetattr(fileno(stdin), TCSANOW, &initialrsettings);
        fprintf(stdout, "\nYou entered %s\n", password);
    }
    exit(0);
}
