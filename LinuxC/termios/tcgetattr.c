#include <termios.h>
#include <unistd.h>
#include <stdio.h>

struct termios term;

int main() {
    tcgetattr(STDIN_FILENO, &term);
    printf("%d, %d, %d, %d\n", term.c_iflag,
            term.c_oflag,
            term.c_cflag,
            term.c_lflag);

    tcgetattr(STDOUT_FILENO, &term);
    printf("%d, %d, %d, %d\n", term.c_iflag,
            term.c_oflag,
            term.c_cflag,
            term.c_lflag);
}
