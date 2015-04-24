#ifndef TORCHHOLDER_H
#define TORCHHOLDER_H

#include <QObject>

class TorchHolder : public QObject
{
	Q_OBJECT
public:
	TorchHolder(QObject *parent = 0);

signals:
	void pass();

public slots:
	void onPass();
};

#endif // TORCHHOLDER_H
