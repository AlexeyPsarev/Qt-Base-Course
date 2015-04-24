#include "MyClass.h"

MyClass::MyClass(QObject *parent) : QObject(parent), m_value(0)
{
}

MyClass::~MyClass()
{
}

void MyClass::setValue(int value)
{
	m_value = value;
	emit valueChanged(m_value);
}

int MyClass::value() const
{
	return m_value;
}
