#include <QCoreApplication>
#include "Pyramid.h"

QTextStream& operator<< (QTextStream& testr, Pyramid& p)
{
	p.printMe(testr);
	return testr;
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	Pyramid p;
	p.create(5, 1);
	QTextStream testr(stdout);
	testr << p;

	//return a.exec();
}
