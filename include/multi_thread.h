#ifndef MULTI_THREAD_H_
#define MULTI_THREAD_H_

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include "libmy.h"
	
typedef enum e_type
{
	_int,
	_char
}						t_type;

typedef enum e_sense
{
	_vector,
	_unarie
}						t_sense;

typedef struct s_multithread
{
	pthread_t *thread;
	size_t    size;
	size_t    current;
	void *(*function)(void *);
	void *args;
	t_type type;
	t_sense sense;
}							t_multithread;

void create_multithread(t_multithread *threads);
void join_multithread(t_multithread *threads);
void set_up(t_multithread *threads, 
						size_t size, void *args, void *(*function)(void *));
void split(t_multithread *threads);

int get_currentInt(t_multithread *threads);

extern char **tab;
extern pthread_mutex_t mutex_aff;
extern pthread_mutex_t mutex_param;

#endif