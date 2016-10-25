#include <QMutexLocker>
#include "Helper_4.h"

void Helper_4::run()
{
	mutex.lock();
	cout << "QThread is waiting" << endl;
	condition.wait(&mutex);
	cout << "QThread has waited and exit" << endl;
}

void Helper_4::stop()
{
	condition.wakeAll();
}

