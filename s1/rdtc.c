#include <stdio.h>
#include <omp.h>
#include <time.h>
#if defined(__i386__)

static __inline__ unsigned long long rdtsc(void)
{
	unsigned long long int x;
	__asm__ volatile (".byte 0x0f, 0x31" : "=A" (x));
	return x;
}

#elif defined(__x86_64__)

static __inline__ unsigned long long rdtsc(void)
{
	unsigned hi, lo;
	printf("x86_x64\r\n");
	__asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
	return ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
}

#endif


int foo() 
{
	int i = 0;
	int j = 3, p = 4;
	for (; i < 10000000; i++)
		j = p * j % 8;
	return j;
}

int main() {
	long long rdtscStart;
	int i;
	for (i = 0; i < 20; i++)  {
		rdtscStart = rdtsc();
		foo();
		printf("%lld\r\n", rdtsc() - rdtscStart);
	}
}