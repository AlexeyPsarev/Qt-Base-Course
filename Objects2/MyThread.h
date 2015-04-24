#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QTextStream>

class MyThread : public QThread
{
	Q_OBJECT
signals:
	void itsMyName(QString name);

public:
	virtual void run();
};

#endif // MYTHREAD_H
