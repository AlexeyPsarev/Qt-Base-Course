#ifndef OLYMPICS_H
#define OLYMPICS_H

#include <QObject>

class Olympics : public QObject
{
	Q_OBJECT
public:
	Olympics(int holders, QObject *parent = 0);
	void start();

signals:
	void pass();

public slots:
	void onPass();
};

#endif // OLYMPICS_H
