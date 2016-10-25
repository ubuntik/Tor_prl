#include <QThread>
#include <iostream>

using namespace std;

class Helper_1 : public QThread
{
	Q_OBJECT
public:
	Helper_1();
	virtual ~Helper_1() {};
	void stop();

protected:
	void run();

private:
	volatile bool stopped;
};

