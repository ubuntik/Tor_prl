#include <stdio.h>
#include <omp.h>

int main() {
	int sum = 0, val = 0;

#pragma omp parallel shared (sum), private (val)
	{
		val = omp_get_thread_num();
		printf("val = %d\n", val);
		sum += val;
	}
	printf("sum = %d\n", sum);
}
