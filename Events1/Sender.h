#ifndef SENDER_H
#define SENDER_H

#include <QObject>

class Sender : public QObject
{
	Q_OBJECT
public:
	explicit Sender(QObject *parent = 0);

public slots:
	void send();
};

#endif // SENDER_H
