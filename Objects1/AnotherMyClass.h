#ifndef ANOTHERMYCLASS_H
#define ANOTHERMYCLASS_H

#include <QObject>

class AnotherMyClass : public QObject
{
	Q_OBJECT
public:
	explicit AnotherMyClass(QObject *parent = 0);

public slots:
	void onMyClassValueChanged(int value);
	void onTimerFired();
};

#endif // ANOTHERMYCLASS_H
