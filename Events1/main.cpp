#include <QCoreApplication>
#include <QTimer>
#include "Sender.h"
#include "UserEvent.h"

class Receiver: public QObject
{
};

class Filter: public QObject
{
public:
	virtual bool eventFilter(QObject* obj, QEvent* ev)
	{
		Q_UNUSED(obj)
		if (ev->type() == UserEvent::UserEventType)
		{
			qApp->exit();
			return true;
		}
		return false;
	}
};

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	Receiver r;
	Filter f;
	r.installEventFilter(&f);
	Sender s(&r);
	QTimer::singleShot(1000, &s, SLOT(send()));

	return a.exec();
}
