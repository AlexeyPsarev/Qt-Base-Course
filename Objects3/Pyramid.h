#ifndef PYRAMID_H
#define PYRAMID_H

#include <QObject>
#include <QVector>
#include <QTextStream>

class Pyramid : public QObject
{
	//Q_OBJECT
	QObject* top;
public:
	void create(int depth, int topVal);
	void printMe(QTextStream& testr);
private:
	void setLeftChild(QObject* parent, QObject* child);
	void setRightChild(QObject* parent, QObject* child);
	QObject* createChild(QObject* left, QObject* right);
	QVector<QObject*> createChildRow(QVector<QObject*> row);
	void printRow(QTextStream& testr, QObject* left);
	QObject* objectAt(int depth, int order);
};

#endif // PYRAMID_H
