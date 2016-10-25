#include <QThread>
#include <QMutex>
#include <iostream>

using namespace std;

class Helper_3 : public QThread
{
	Q_OBJECT
public:
	Helper_3();
	virtual ~Helper_3() {};
	void stop();

protected:
	void run();

private:
	volatile bool stopped;
	QMutex mutex;
	bool run_func();
};

