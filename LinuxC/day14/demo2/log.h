#ifndef LOG_H
#define LOG_H
#include <QObject>
class Log : public QObject/*1*/
{
Q_OBJECT/*2*/
public slots:/*3*/
	void log(int);
};/*4*/
#endif
