#include <QTextStream>
#include "AnotherMyClass.h"

AnotherMyClass::AnotherMyClass(QObject *parent) : QObject(parent)
{
	connect(parent, SIGNAL(valueChanged(int)), SLOT(onMyClassValueChanged(int)));
}

void AnotherMyClass::onMyClassValueChanged(int value)
{
	QTextStream str(stdout);
	str << value << "\n";
	str.flush();
}

void AnotherMyClass::onTimerFired()
{
	parent()->setProperty("value", QVariant(1));
}
