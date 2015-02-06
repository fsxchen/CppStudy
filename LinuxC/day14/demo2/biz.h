#ifndef BIZ_H
#define BIZ_H
#include <QObject>
class Biz : public QObject/*1*/
{
Q_OBJECT/*2*/
public:
	void biz();
public :
	signals:
	void siglog(int);	//信号
};
#endif
