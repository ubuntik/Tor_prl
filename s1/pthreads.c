#include <pthread.h>
#include <stdio.h>

//REM via syscall
#include <sys/syscall.h>


void *inc_x(void *x_void_ptr) {
	pthread_t val = pthread_self();
	pid_t uval = (pid_t)syscall(SYS_gettid);
	printf("val = %d, %lu\n", uval, val);
	int *x_ptr = (int*)x_void_ptr;
	(*x_ptr)+= val;
	return NULL;
}

int main() {
	int sum = 0, y = 0, i;
	pthread_t inc_x_thread[3];
	for (i = 0; i < 3; i++) {
		if (0 != pthread_create(inc_x_thread + i, NULL, inc_x, &sum)) {
			printf("Error\n");
			return 1;
		}
	}

	//master thread
	inc_x(&sum);

	for (i = 0; i < 3; i++)
		if (pthread_join(inc_x_thread[i], NULL)) {
			printf("Error joining\n");
			return 2;
		}

	printf("sum = %d\n", sum);
	return 0;
}


