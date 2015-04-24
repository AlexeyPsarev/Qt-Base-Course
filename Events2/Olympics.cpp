#include <QCoreApplication>
#include <QThread>
#include "TorchHolder.h"
#include "Olympics.h"

Olympics::Olympics(int holders, QObject *parent) : QObject(parent)
{
	TorchHolder* prevth = 0;
	for (int i = 1; i <= holders; ++i)
	{
		QThread* thr = new QThread(this);
		TorchHolder* th = new TorchHolder;
		thr->setObjectName(QString("Holder%1").arg(i));
		th->moveToThread(thr);

		connect(thr, SIGNAL(finished()), thr, SLOT(deleteLater()));
		connect(th, SIGNAL(pass()), thr, SLOT(quit()));

		if (prevth)
			connect(prevth, SIGNAL(pass()), th, SLOT(onPass()));
		if (i == 1)
			connect(this, SIGNAL(pass()), th, SLOT(onPass()));
		if (i == holders)
			connect(th, SIGNAL(pass()), this, SLOT(onPass()));

		prevth = th;
		thr->start();
	}
}

void Olympics::start()
{
	qWarning("Start passing torch to holders");
	emit pass();
}

void Olympics::onPass()
{
	qWarning("Let the Olympic flame light!");
	qApp->exit();
}
