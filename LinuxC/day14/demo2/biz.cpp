#include "biz.h"
#include <iostream>
#include <unistd.h>
using namespace std;
void Biz::biz()
{
	while(1)
	{
		sleep(1);
		cout<<"我是业务处理!\n";
		//发送信号
		emit siglog(99999);/*4*/
	}
}
