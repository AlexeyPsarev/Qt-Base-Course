#include <QCoreApplication>
#include <QThreadPool>
#include <QRunnable>
#include <QVector>
#include <QStringList>
#include <QTextStream>

QVector<QString> g_nameVector;

class MyRunnable: public QRunnable
{
	QString m_name;
public:
	MyRunnable(const QString& name): QRunnable(), m_name(name)
	{
	}

	virtual void run()
	{
		g_nameVector.push_back(m_name);
	}
};

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	QStringList args = a.arguments();
	foreach (QString arg, args)
	{
		MyRunnable* runnable = new MyRunnable(arg);
		QThreadPool::globalInstance()->start(runnable);
	}
	QThreadPool::globalInstance()->waitForDone();
	QTextStream str(stdout);
	foreach (QString name, g_nameVector)
		str << name << "\n";
	str.flush();
	//return a.exec();
}
