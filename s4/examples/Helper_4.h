#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <iostream>

using namespace std;

class Helper_4 : public QThread
{
	Q_OBJECT
public:
	Helper_4() {};
	virtual ~Helper_4() {};
	void stop();

protected:
	void run();

private:
	QMutex mutex;
	QWaitCondition condition;
};

