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

char get_currentChar(t_multithread *threads)
{
	char *tmp;
	char ret;

	if (threads->sense == _vector)
	{
		tmp = (char *)threads->args;
		ret = tmp[threads->current];
	}
	else
	{
		tmp = (char *)threads->args;
		ret = *tmp;
	}
	pthread_mutex_unlock(&mutex_param);
	return (ret);
}

char *get_currentCharPtr(t_multithread *threads)
{
	char **tmp;
	char *ret;

	if (threads->sense == _vector)
	{
		tmp = (char **)threads->args;
		ret = tmp[threads->current];
	}
	else
	{
		tmp = (char **)threads->args;
		ret = *tmp;
	}
	pthread_mutex_unlock(&mutex_param);
	return (ret);
}