#ifndef TH_YAO_H
#define TH_YAO_H
#include <QThread>
class ThYao:public QThread {
Q_OBJECT
private:
    bool isstop;
public:
    ThYao();
public: signals:
    void number(const QString &num);
protected:
    virtual void run();
public slots:
    void control(bool);
};

#endif
