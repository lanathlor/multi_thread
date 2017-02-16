#include <pthread.h>
#include "multi_thread.h"

pthread_mutex_t mutex_param = PTHREAD_MUTEX_INITIALIZER;

void create_multithread(t_multithread *threads)
{
	size_t i;

	i = 0;
	while (i < threads->size)
	{
		if (threads->args == NULL)
			pthread_create(&threads->thread[i], NULL, threads->function, NULL);
		else
		{
			pthread_mutex_lock(&mutex_param);
			threads->current = i;
			pthread_create(&threads->thread[i], NULL, threads->function, 
				(void *)threads);	
		}
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
		my_perror(M_FAIL);
	threads->size = size;
	threads->args = args;
	threads->function = function;
}

void split(t_multithread *threads)
{
	create_multithread(threads);
	join_multithread(threads);
}