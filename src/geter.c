#include <pthread.h>
#include "multi_thread.h"

t_multithread *get_threadStruct(void *addr)
{
	return ((t_multithread *)addr);
}

size_t get_current(t_multithread *thread)
{
	size_t ret;

	ret = thread->current;
	pthread_mutex_unlock(&mutex_param);
	return (ret);
}
