#include <QCoreApplication>
#include <QTextStream>

int main(int argc, char *argv[])
{
	//QCoreApplication a(argc, argv);

	QTextStream str(stdout);
	str << "Hello Qt!\n";
	str.flush();

	//return a.exec();
}
