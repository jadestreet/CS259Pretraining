#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t tid[2];

void* threadFunc(void *arg)
{
	unsigned long i = 0;
	pthread_t id = pthread_self();
	
	if (pthread_equal(id, tid[0]))
	{
		printf("First thread processing\n");
	}
	else
	{
		printf("Second thread processing\n");
	}

	for(i = 0; i < 0xffffffff; i++);
}

int main(void)
{
	int i = 0;
	int err;

	while (i<2)
	{
		err = pthread_create(&(tid[i]), NULL, &threadFunc, NULL);
		if (err != 0)
			printf("cann't create thread : [%s]", strerror(err));
		else
			printf("thread created successfully\n");

		i++;
	}
	sleep(5);
	return 0;
}
