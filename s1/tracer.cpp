#include <iostream>
#include <string>

static __inline__ unsigned long long rdtsc(void)
{
	unsigned hi, lo;
	__asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
	return ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
}

using namespace std;

static bool traceIsActive;

class Trace {
public:
	Trace (const string &name) : theFunctionName(name) { if (traceIsActive) cout << "Enter function" << name << endl; };
	~Trace () { if (traceIsActive) cout << "Exit function " << theFunctionName << endl; };
	void debug (const string &msg) { if (traceIsActive) cout << msg << endl; };
private:
	string theFunctionName;
};

class Trace2 {
public:
	Trace2 (const char *name);
	~Trace2 ();
	void debug (const string &msg);
private:
	string *theFunctionName;
};

inline Trace2::Trace2(const char *name) : theFunctionName(NULL)
{
	if (traceIsActive) {
		cout << "Enter function " << name << endl;
		theFunctionName = new string(name);
	}
}

inline Trace2::~Trace2()
{
	if (traceIsActive) {
		cout << "Exit function " << *theFunctionName << endl;
		delete theFunctionName;
	}
}

inline void debug (const string &msg)
{
	if (traceIsActive)
		cout << msg << endl;
}

int addOne(int x)
{
//	string name = "addOne";
//	Trace t(name);
	Trace2 t("addOne");
	return x + 1;
}

int main()
{
	long long rdtscStart;
	traceIsActive = false;
	rdtscStart = rdtsc();
	for (int i = 0; i < 100000000; i++)
		int y = addOne(i);
	cout << rdtsc() - rdtscStart << endl;

	return 0;
}

