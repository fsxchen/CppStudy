#include <stdio.h>
#include <unistd.h>

class ILog{
public:
    virtual void log() = 0;
};

class Log:public ILog{
public:
    void log() {
        printf("日志输出ing!\n");
    }

};

class Log2:public ILog{
public:
    void log() {
        printf("日志输出-----V2!\n");
    }

};


class Biz{
public:
    void biz(ILog *log) {
        while(1) {
            sleep(1);
            printf("我在处理业务！\n");
            log->log();
        }
    }
};



int main() {
    Biz biz;
    Log2 log;
    biz.biz(&log);
}
