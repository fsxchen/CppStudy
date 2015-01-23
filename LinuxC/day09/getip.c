#include <stdio.h>
#include <netdb.h>

main() {
    struct hostent *ent;
    ent = gethostbyname("bbs.com");
    // printf("%s", ent->h_aliases[0]);
    printf("%hhu.%hhu.%hhu.%hhu\n",
        // ent->h_addr_l,
        // ent->h_addr[1],
        // ent->h_addr[2],
        // ent->h_addr[3]
        ent->h_addr_list[0][0],
        ent->h_addr_list[0][1],
        ent->h_addr_list[0][2],
        ent->h_addr_list[0][3]
        );
}
