#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS  3
#define TCOUNT 10
#define COUNT_THRES 12

int     condvar_was_hit = 0;
int     count = 0;
int     thread_ids[3] = {0,1,2};
pthread_mutex_t count_lock=PTHREAD_MUTEX_INITIALIZER; 
pthread_cond_t count_hit_threshold=PTHREAD_COND_INITIALIZER; 

void *inc_count(void *null)
{
  int i=0;

  for (i=0; i<TCOUNT; i++) {
    pthread_mutex_lock(&count_lock);
    count++;
    printf("inc_counter(): count = %d, unlocking mutex\n", count);
    if (count == COUNT_THRES) {
      printf("hit threshold!\n");
      pthread_cond_signal(&count_hit_threshold);
    }
    pthread_mutex_unlock(&count_lock);
  }
  
  return(NULL);
}

void *watch_count(void *null)
{
  pthread_mutex_lock(&count_lock);

  while (count < COUNT_THRES) {
    pthread_cond_wait(&count_hit_threshold, &count_lock);
    condvar_was_hit = 1;
  }

  pthread_mutex_unlock(&count_lock);
  
  return(NULL);
}

extern int
main(void)
{
  int       i;
  pthread_t threads[3];

  pthread_create(&threads[0], NULL, watch_count, NULL);
  sleep(1);
  pthread_create(&threads[1], NULL, inc_count,   NULL);
  pthread_create(&threads[2], NULL, inc_count,   NULL);

  for (i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  
  
  
  
  
  
  if (condvar_was_hit == 1)
    printf("condvar was hit!\n");
  else if (condvar_was_hit > 1)
    printf("condvar was multi-hit...\n");
  else
    printf("condvar was missed...\n");
  
  return 0;
}


