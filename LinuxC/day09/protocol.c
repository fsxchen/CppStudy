#include <stdio.h>
#include <netdb.h>
#include <sys/utsname.h>
main() {
    struct protoent *ent;
    ent = getprotobyname("icmp");    //不区分大小写
    printf("%d\n", ent->p_proto);

    struct utsname name;
    uname(&name);
    printf("%s, %s, %s\n", name.sysname, name.nodename, name.machine);
}
