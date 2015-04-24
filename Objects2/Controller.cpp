#include <QTextStream>
#include <QCoreApplication>

#include "MyThread.h"
#include "Controller.h"

Controller::Controller(QObject *parent) : QObject(parent), m_threadCounter(0)
{
}

void Controller::start(const QStringList &args)
{
	foreach (QString arg, args)
	{
		MyThread* thr = new MyThread;
		thr->setObjectName(arg);
		connect(thr, SIGNAL(itsMyName(QString)),
				this, SLOT(onMyThreadName(QString)));
		connect(thr, SIGNAL(finished()), thr, SLOT(deleteLater()));
		connect(thr, SIGNAL(destroyed(QObject*)),
				this, SLOT(onMyThreadDestroyed(QObject*)));
		thr->start();
		++m_threadCounter;
	}
}

void Controller::onMyThreadName(QString name)
{
	QTextStream str(stdout);
	str << name << "\n";
	str.flush();
}

void Controller::onMyThreadDestroyed(QObject*)
{
	--m_threadCounter;
	if (m_threadCounter == 0)
		qApp->quit();
}
