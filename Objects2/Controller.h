#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Controller : public QObject
{
	Q_OBJECT
	int m_threadCounter;
public:
	Controller(QObject *parent = 0);
	void start(const QStringList& args);

public slots:
	void onMyThreadName(QString name);
	void onMyThreadDestroyed(QObject*);
};

#endif // CONTROLLER_H
