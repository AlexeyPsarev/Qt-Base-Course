#include <QThread>
#include "TorchHolder.h"

TorchHolder::TorchHolder(QObject *parent) : QObject(parent)
{
}

void TorchHolder::onPass()
{
	int msec = 1000;
	qWarning("%s holding torch for %d msec",
			 thread()->objectName().toLatin1().data(), msec);
	QThread::msleep(msec);
	emit pass();
}
