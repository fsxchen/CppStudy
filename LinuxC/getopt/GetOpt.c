#include <stdio.h>
#include <unistd.h>
int main(int argc,char **argv) {
    int ch;
    opterr = 0;
    while((ch = getopt(argc,argv,"a:bcdeh"))!= -1) {
        switch(ch){
            case 'a':
            printf("option a:%s\n",optarg);
            break;
            case 'b':
            printf("option b :b\n");
            break;
			case 'h':
				printf("Please use...\n");
				break;
            default:
            printf("other option :%c\n",ch);
            printf("optopt +%c\n",optopt);
        }
    }
}
