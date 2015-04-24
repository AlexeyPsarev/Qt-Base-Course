#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>

class MyClass : public QObject
{
	Q_OBJECT
	Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)
public:
	MyClass(QObject *parent = 0);
	~MyClass();
	void setValue(int value);
	int value() const;

signals:
	void valueChanged(int);

private:
	int m_value;
};

#endif // MYCLASS_H
