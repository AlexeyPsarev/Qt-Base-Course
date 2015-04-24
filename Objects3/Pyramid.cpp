#include <QVariant>
#include "Pyramid.h"

void Pyramid::create(int depth, int topVal)
{
	if (depth < 1)
		return;
	top = new QObject(this);
	top->setProperty("value", QVariant(topVal));
	QVector<QObject*> row;
	row.push_back(top);
	for (int i = 1; i < depth; ++i)
		row = createChildRow(row);
}

QObject* Pyramid::createChild(QObject* left, QObject* right)
{
	QObject* c = new QObject(this);
	setLeftChild(right, c);
	setRightChild(left, c);
	int leftVal = 0;
	if (left)
		leftVal = left->property("value").toInt();
	int rightVal = 0;
	if (right)
		rightVal = right->property("value").toInt();
	int val = leftVal + rightVal;
	c->setProperty("value", QVariant(val));
	return c;
}

void Pyramid::setLeftChild(QObject* parent, QObject* child)
{
	if (!child)
		return;

	if (parent)
	{
		QVariant chiVar;
		chiVar.setValue(child);
		parent->setProperty("LeftChild", chiVar);
	}

	QVariant parVar;
	parVar.setValue(parent);
	child->setProperty("RightParent", parVar);
}

void Pyramid::setRightChild(QObject* parent, QObject* child)
{
	if (!child)
		return;

	if (parent)
	{
		QVariant chiVar;
		chiVar.setValue(child);
		parent->setProperty("RightChild", chiVar);
	}

	QVariant parVar;
	parVar.setValue(parent);
	child->setProperty("LeftParent", parVar);
}

QVector<QObject*> Pyramid::createChildRow(QVector<QObject*> row)
{
	QVector<QObject*> childRow;
	if (row.empty())
		return childRow;
	QVariant var;
	QObject* child = 0;

	foreach (QObject* obj, row)
	{
		var = obj->property("LeftParent");
		QObject* left = 0;
		if (var.isValid() && var.value<QObject*>())
		{
			var = var.value<QObject*>()->property("LeftChild");
			left = var.value<QObject*>();
		}
		child = createChild(left, obj);
		childRow.push_back(child);
	}

	//QObject* right = 0;
	child = createChild(row.last(), 0);
	childRow.push_back(child);
	return childRow;
}

void Pyramid::printRow(QTextStream& testr, QObject* left)
{
	if (!left)
		return;
	QObject* obj = left;
	while (obj)
	{
		testr << obj->property("value").toInt() << " ";
		QVariant objVar = obj->property("RightParent");
		if (objVar.isValid() && (obj = objVar.value<QObject*>()))
		{
			objVar = obj->property("RightChild");
			obj = objVar.value<QObject*>();
		}
		else
			obj = 0;
	}
}

void Pyramid::printMe(QTextStream& testr)
{
	if (!top)
	{
		testr << "empty\n";
		return;
	}
	QObject* left = top;
	while (left)
	{
		printRow(testr, left);
		testr << "\n";
		QVariant var = left->property("LeftChild");
		if (var.isValid())
			left = var.value<QObject*>();
		else
			left = 0;
	}
}
