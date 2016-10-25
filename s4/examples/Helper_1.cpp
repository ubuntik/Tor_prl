#include "Helper_1.h"

Helper_1::Helper_1()
{
	stopped = false;
}

void Helper_1::run()
{
	while (!stopped)
		cout << "QThread is working" << endl;
	stopped = false;
}

void Helper_1::stop()
{
	stopped = true;
}

