#include <QCoreApplication>
#include <QStringList>
#include "Olympics.h"

void usage(char* arg0)
{
	qWarning("usage: %s <number of holders>", arg0);
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	if (argc != 2)
	{
		qWarning("you must pass exactly one argument");
		usage(argv[0]);
		return -1;
	}

	bool ok;
	int holders = QString(argv[1]).toInt(&ok);
	if (!ok)
	{
		qWarning("you must pass an integer argument only");
		usage(argv[0]);
		return -1;
	}
	if (holders <= 0)
	{
		qWarning("number of holders should be positive");
		return -1;
	}

	Olympics o(holders);
	o.start();
	return a.exec();
}
