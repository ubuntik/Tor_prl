#include <unistd.h>
#include <QCoreApplication>
//#include "Helper_1.h"
//#include "Helper_2.h"
//#include "Helper_3.h"
//#include "Helper_4.h"
//#include "Helper_5.h"
#include "Helper_6.h"


int main(int argc, char **argv)
{
/////////////////////////////////////////////////
// Helper_1-4
//
//	Helper_1 *helper = new Helper_1();
//	Helper_2 *helper = new Helper_2();
//	Helper_3 *helper = new Helper_3();
//	Helper_4 *helper = new Helper_4();
/*
	helper->start();
	sleep(1);
	helper->stop();
	helper->quit();
	helper->wait();
	delete helper;
*/
/////////////////////////////////////////////////
// Helper_5
/*
	Helper_5 *h1 = new Helper_5();
	Helper_5 *h2 = new Helper_5();
//	QThreadPool::globalInstance()->setMaxThreadCount(1);
	QThreadPool::globalInstance()->start(h1);
	QThreadPool::globalInstance()->start(h2);
	QThreadPool::globalInstance()->waitForDone();
*/
/////////////////////////////////////////////////
// Helper_6

	QCoreApplication a(argc, argv);
	Thread1 th1;
	Thread2 th2;
	MyObject ob;
	QObject::connect(&th1, SIGNAL(MySignal()), &ob, SLOT(MySlot()));
	th2.start();
	ob.moveToThread(&th2);
	th1.start();
	th1.wait();
	th2.quit();
	th2.wait();

	return 0;
}
