#include "Helper_2.h"

Helper_2::Helper_2()
{
	stopped = false;
}

void Helper_2::run()
{
	mutex.lock();
	while (1) {
		if (stopped) {
			stopped = false;
			mutex.unlock();
			break;
		}
		mutex.unlock();
		cout << "QThread is working" << endl;
	}
}

void Helper_2::stop()
{
	mutex.lock();
	stopped = true;
	mutex.unlock();
}

