/**************************************************************************
*  Copyright 2015 wonkymind86@gmail.com
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and 
* limitations under the License.
***************************************************************************/

/*
 ** This is an example program for sharing a accessing a global variable safely
 ** using semaphore within two threads in a process.
 ** Note that if the semaphore is to be shared between different processes,
 ** the semaphore name must be stored in a shared memory accessible to both
 ** the threads
 */

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

void *th_fn1();
void *th_fn2();

/*
 ** This is the semaphore name
 */
sem_t th_shd_sem;
/*
 ** This is the test global variable that the two threads will try to access
 */
static int glb_shared_obj = 0;

int main ()
{
		pthread_t th_id1, th_id2;

		/*
		 ** Here the main thread is initializing the semaphore
		 ** th_shd_sem - Semaphore name
		 ** 0 - Indicates semaphore is used within threads in a process
		 ** 1 - In what state the semaphore is initialized
		 */
		if (sem_init(&th_shd_sem, 0, 1))
		{
				printf ("Sem_init Error\n");
		}

		/*
		 * In this although both are created one after the another which ever thread runs first will 
		 * get the semaphore.  The order of creation does not ensure the order of execution
		 */
		pthread_create (&th_id1, NULL, (void *)&th_fn1, NULL);
		pthread_create (&th_id2, NULL, (void *)&th_fn2, NULL);

		sleep(1);
		/*
		 ** We may not need a sleep here because the main thread takes the 
		 ** semaphore last, so when only both the threads post the main will get
		 ** the resource
		 */
#if 0
		pthread_join (th_id1, NULL);
		pthread_join (th_id2, NULL);
#endif
		/*
		 ** This will try to acquire the semaphore, if not available it will 
		 ** wait indefinitely to acquire the semaphore
		 */
		sem_wait(&th_shd_sem);
		printf ("Main thread printing the value: %d\n", glb_shared_obj);
		/*
		 ** Signals that the semaphore is released.  It is always a good
		 ** practice to release any resource before exiting the process.
		 */
		sem_post(&th_shd_sem);
		return 0;
}

void *th_fn1()
{
		printf ("In thread 1\n");
		sem_wait(&th_shd_sem);
		printf ("Thd 1 incrementing value: %d\n", ++glb_shared_obj);
		sleep (1);
		sem_post(&th_shd_sem);
}

void *th_fn2()
{
		printf ("In thread 2\n");
		sem_wait(&th_shd_sem);
		printf ("Thd 2 incrementing value: %d\n", ++glb_shared_obj);
		sleep (3);
		sem_post(&th_shd_sem);
}
