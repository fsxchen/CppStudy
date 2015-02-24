#include "chatException.h"
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
ChatException::ChatException() {
    bzero(msg, sizeof(msg));
    sprintf(msg, "聊天异常!");
}

ChatException::ChatException(const char* m) {
    bzero(msg, sizeof(msg));
    sprintf(msg, "聊天异常:%s!", m);
}

const char * ChatException::what() const throw(){
    return msg;
}
