#include <stdio.h>
#include <pthread.h>

pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;

void* thread1(void* arg)
{
	pthread_t t = pthread_self();
	pthread_rwlock_rdlock(&rwlock);
	printf("now thread %lu rd lock it\n",t);
	sleep(2);
	pthread_rwlock_unlock(&rwlock);
	printf("now thread %lu unlock it\n",t);
}

void* thread2(void* arg)
{
	pthread_t t = pthread_self();
	sleep(1);
	pthread_rwlock_wrlock(&rwlock);
	printf("now thread %lu wr lock it\n",t);
	pthread_rwlock_unlock(&rwlock);	
}

int main(int argc,char** argv)
{
	int i=0;
	for(i=0;i<5;i++)
	{
		pthread_t t1;
		pthread_create(&t1,NULL,thread1,NULL);
	}
	pthread_t t2;
	pthread_create(&t2,NULL,thread2,NULL);
	sleep(5);
	return 0;
}

