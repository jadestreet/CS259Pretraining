/**
 * Michael Palmer
 * CSCI 3232-A
 * April 1, 2015
 * Using Semaphores to Maintain Thread Execution Order
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MIN_THREAD 'A' // Minimum thread identifier
#define MAX_THREAD 'H' // Maximum thread identifier

/**
 * Structure for ordered threads
 */
struct Thread_Order {
	int threadID;
	int waitThread1;
	int waitThread2;
	int numToPost;
};

// Initialize variables
void *state( void *args );
pthread_t threads[ MAX_THREAD ];
sem_t sem[ MAX_THREAD ];
struct Thread_Order *orderedThreads[ MAX_THREAD ];

/**
 * Create an ordered thread
 *
 * @param int threadID		Identifier for the semaphore
 * @param int waitThread1	Semaphore to wait for before executing. Use -1 if thread
 * 							does not need to wait for another semaphore
 * @param int waitThread2	Semaphore to wait for before executing. Use -1 if thread
 * 							does not need to wait for a second semaphore
 * @param int numToPost		Number of times to post the semaphore
 * @return struct Thread_Order *thread
 */
struct Thread_Order *addOrder(int threadID, int waitThread1, int waitThread2, int numToPost) {
	struct Thread_Order *thread = malloc( sizeof( struct Thread_Order ) );
	thread->threadID = threadID;
	thread->waitThread1 = waitThread1;
	thread->waitThread2 = waitThread2;
	thread->numToPost = numToPost;
	return thread;
}

/**
 * State where semaphores will check if it needs to
 * wait for another semaphore before executing. This
 * method is called by pthread_create() in main()
 *
 * @param void *args Arguments passed by pthread_create()
 */
void *state( void *args ) {
	int i;
	
	// Convert passed argument to the Thread_Order structure
	struct Thread_Order *thread = (struct Thread_Order *) args;

	// Check if this thread needs to wait for another
	if(thread->waitThread1 >= MIN_THREAD) {
		printf("Thread %c: Waiting on Thread %c\n", thread->threadID, thread->waitThread1);
		sem_wait( &sem[ thread->waitThread1 ] );
	}

	// Check if this thread needs to wait for a second thread
	if(thread->waitThread2 >= MIN_THREAD) {
		printf("Thread %c: Waiting on Thread %c\n", thread->threadID, thread->waitThread2);
		sem_wait( &sem[ thread->waitThread2 ] );
	}

	/*** Start Critical Region ***/
	
	printf("Thread %c: Entered\n", thread->threadID);
	sleep(1);
	
	/*** End Critical Region ***/

	// Post the thread
	for(i = 0; i < thread->numToPost; i++) {
		sem_post( &sem[ thread->threadID ] );
	}
	printf("Thread %c: Finished\n", thread->threadID);
	return 0;
}

int main() {
	int i;
	
	// Set up the order of the threads
	orderedThreads[ 'A' ] = addOrder( 'A', -1, -1, 2 );
	orderedThreads[ 'B' ] = addOrder( 'B', 'A', -1, 2 );
	orderedThreads[ 'C' ] = addOrder( 'C', 'A', -1, 1 );
	orderedThreads[ 'D' ] = addOrder( 'D', 'B', -1, 1 );
	orderedThreads[ 'E' ] = addOrder( 'E', 'C', 'D', 1 );
	orderedThreads[ 'F' ] = addOrder( 'F', 'B', -1, 1 );
	orderedThreads[ 'G' ] = addOrder( 'G', 'E', -1, 1 );
	orderedThreads[ 'H' ] = addOrder( 'H', 'F', 'G', 1 );

	// Initialize semaphores and create threads
	for(i = MIN_THREAD; i <= MAX_THREAD; i++) {
		sem_init( &sem[ i ], 0, 0 );
		pthread_create( &threads[ i ], NULL, state, orderedThreads[ i ] );
	}

	// Join threads
	for(i = MIN_THREAD; i <= MAX_THREAD; i++) {
		pthread_join( threads[ i ], NULL );
	}

	// Close semaphores
	for(i = MIN_THREAD; i <= MAX_THREAD; i++) {
		sem_destroy( &sem[ i ] );
	}

	return 0;
}