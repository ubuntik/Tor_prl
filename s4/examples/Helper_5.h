#include <QThreadPool>
#include <iostream>

using namespace std;

class Helper_5 : public QRunnable
{
public:
	Helper_5() {};
	virtual ~Helper_5() {};

protected:
	void run() { cout << "QThread is working" << endl; };
};

