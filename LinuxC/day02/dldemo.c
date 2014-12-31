#include <dlfcn.h>
//我们自己去查找动态库
main() {
    void *handle=dlopen("./libdemo4.so", RTLD_LAZY);
    void (*func)(int)=dlsym(handle, "diamond");
    func(5);
    dlclose(handle);
}
