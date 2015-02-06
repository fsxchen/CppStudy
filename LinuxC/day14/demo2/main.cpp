#include "biz.h"
#include "log.h"
int main()
{
	Log log;
	Biz biz;
	QObject::connect(
		&biz,//信号源对象
		SIGNAL(siglog(int)),//信号函数
		&log,//槽目标对象
		SLOT(log(int)));//槽函数
	biz.biz();
}
