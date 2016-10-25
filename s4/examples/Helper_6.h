#include <QThread>
#include <iostream>

using namespace std;

class MyObject : public QObject
{
	Q_OBJECT
public slots:
	void MySlot()
	{
		cout << "slot called" << endl;
	}
};

class Thread1 : public QThread
{
	Q_OBJECT
public:
	void run()
	{
		cout << "thread 1 started" << endl;
		for (int i = 0; i < 5; i++) {
			sleep(1);
			emit MySignal();
		}
	}
signals:
	void MySignal();
};

class Thread2 : public QThread
{
	Q_OBJECT
public:
	void run()
	{
		cout << "thread 2 started" << endl;
		exec();
	}
};
