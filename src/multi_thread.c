#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "multi_thread.h"

pthread_mutex_t mutex_param = PTHREAD_MUTEX_INITIALIZER;
/* lock in create_multithread.
use to passe the thread->current to the thread.
unlock in get_current */
pthread_mutex_t mutex_aff = PTHREAD_MUTEX_INITIALIZER;
/* use with pthread_mutex_lock() and pthread_mutex_unlock()
sleep the others thread will doing the intructions between the lock and the unlock
defined here as an exemple and a built in mutex for printing purpose but can be delete or move */

void create_multithread(t_multithread *threads)
{
	size_t i;

	i = 0;
	while (i < threads->size)
	{
		pthread_mutex_lock(&mutex_param);
		threads->current = i;
		pthread_create(&threads->thread[i], NULL, threads->function, 
									(void *)threads);	
		i++;
	}
}

void join_multithread(t_multithread *threads)
{
	size_t i;

	i = 0;
	while (i < threads->size)
	{
		pthread_join (threads->thread[i], NULL);
		i++;
	}	
}

void set_up(t_multithread *threads, 
						size_t size, void *args, void *(*function)(void *))
{
	if ((threads->thread = malloc(sizeof(pthread_t) * size)) == NULL)
		perror("crash for :");
	threads->size = size;
	threads->args = args;
	threads->function = function;
}

void split(t_multithread *threads)
{
	create_multithread(threads);
	join_multithread(threads);
}