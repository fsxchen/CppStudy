#include "biz.h"
#include "log.h"
int main()
{
	Log log;
	Biz biz;
	QObject::connect(
		&biz,//�ź�Դ����
		SIGNAL(siglog(int)),//�źź���
		&log,//��Ŀ�����
		SLOT(log(int)));//�ۺ���
	biz.biz();
}
