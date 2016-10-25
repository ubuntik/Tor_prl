#include <QThread>
#include <QMutex>
#include <iostream>

using namespace std;

class Helper_2 : public QThread
{
	Q_OBJECT
public:
	Helper_2();
	virtual ~Helper_2() {};
	void stop();

protected:
	void run();

private:
	volatile bool stopped;
	QMutex mutex;
};

