#include <QCoreApplication>
#include <QStringList>

#include"Controller.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	Controller c;
	c.start(a.arguments());

	return a.exec();
}
