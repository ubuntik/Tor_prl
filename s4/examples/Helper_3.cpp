#include <QMutexLocker>
#include "Helper_3.h"

Helper_3::Helper_3()
{
	stopped = false;
}

void Helper_3::run()
{
	while (run_func()) {};
}

bool Helper_3::run_func()
{
	QMutexLocker lock(&mutex);
	if (stopped) {
		stopped = false;
		return false;
	}
	cout << "QThread is working" << endl;
	return true;
}

void Helper_3::stop()
{
	QMutexLocker lock(&mutex);
	stopped = true;
}

