#include "MyThread.h"

void MyThread::run()
{
	emit itsMyName(this->objectName());
}

