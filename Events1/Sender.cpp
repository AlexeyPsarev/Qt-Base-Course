#include <QCoreApplication>
#include "Sender.h"
#include "UserEvent.h"

Sender::Sender(QObject *parent) : QObject(parent)
{
}

void Sender::send()
{
	QCoreApplication::sendEvent(parent(), new UserEvent);
}
