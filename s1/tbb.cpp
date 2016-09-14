#include <iostream>
#include <tbb/tbb.h>
#include <tbb/parallel_for.h>

using namespace std;
using namespace tbb;

long len = 5000;
float *set1 = new float[len], *set2 = new float[len], *set3 = new float[len];

class GrainTest {

	public:
		void operator()( const blocked_range<size_t>& r ) const {
			for (long i = r.begin(); i!=r.end(); ++i) {
				set3[i] = (set1[i] * set2[i]) / 2.0 + set2[i];
			}
		}
};

int main() {
	parallel_for(blocked_range<size_t>(0, len, 100), GrainTest() );
}
