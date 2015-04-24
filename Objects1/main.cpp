#include <QCoreApplication>
#include <QVariant>
#include <QTimer>

#include "MyClass.h"
#include "AnotherMyClass.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	MyClass mc;
	AnotherMyClass amc(&mc);

	QTimer::singleShot(1000, &amc, SLOT(onTimerFired()));

	return a.exec();
}
