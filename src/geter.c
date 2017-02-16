#include <pthread.h>
#include "multi_thread.h"

int get_currentInt(t_multithread *threads)
{
	int *tmp;
	int ret;

	if (threads->sense == _vector)
	{
		tmp = (int *)threads->args;
		ret = tmp[threads->current];
	}
	else
	{
		tmp = (int *)threads->args;
		ret = *tmp;
	}
	pthread_mutex_unlock(&mutex_param);
	return (ret);
}