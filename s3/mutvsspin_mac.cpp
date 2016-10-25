#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>
#include <sys/time.h>

#include <list>

#define LOOPS 10000000

using namespace std;

list<int> the_list;

#ifdef USE_SPINLOCK
pthread_rwlock_t rwlock;
#else
pthread_mutex_t mutex;
#endif

pid_t gettid() { return getpid(); }

void *consumer(void *ptr)
{
	int i;
	printf("Consumer TID %lu\n", (unsigned long)gettid());

	while (1) {
#ifdef USE_SPINLOCK
		pthread_rwlock_wrlock(&rwlock);
#else
		pthread_mutex_lock(&mutex);
#endif

		if (the_list.empty()) {
#ifdef USE_SPINLOCK
			pthread_rwlock_unlock(&rwlock);
#else
			pthread_mutex_unlock(&mutex);
#endif
			break;
		}

		i = the_list.front();
		the_list.pop_front();

#ifdef USE_SPINLOCK
		pthread_rwlock_unlock(&rwlock);
#else
		pthread_mutex_unlock(&mutex);
#endif
	}

	return NULL;
}

int main()
{
	int i;
	pthread_t thr1, thr2;
	struct timeval tv1, tv2;

#ifdef USE_SPINLOCK
	pthread_rwlock_init(&rwlock, 0);
#else
	pthread_mutex_init(&mutex, NULL);
#endif

	// Creating the list content...
	for (i = 0; i < LOOPS; i++)
		the_list.push_back(i);

	// Measuring time before starting the threads...
	gettimeofday(&tv1, NULL);

	pthread_create(&thr1, NULL, consumer, NULL);
	pthread_create(&thr2, NULL, consumer, NULL);

	pthread_join(thr1, NULL);
	pthread_join(thr2, NULL);

	// Measuring time after threads finished...
	gettimeofday(&tv2, NULL);

	if (tv1.tv_usec > tv2.tv_usec) {
		tv2.tv_sec--;
		tv2.tv_usec += 1000000;
	}

	printf("Result - %ld.%d\n", tv2.tv_sec - tv1.tv_sec, tv2.tv_usec - tv1.tv_usec);

#ifdef USE_SPINLOCK
	pthread_rwlock_destroy(&rwlock);
#else
	pthread_mutex_destroy(&mutex);
#endif

	return 0;
}

