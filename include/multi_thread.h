#ifndef MULTI_THREAD_H_
#define MULTI_THREAD_H_

typedef struct s_multithread // this structure is needed you can pa
{
	pthread_t *thread; //array of thread
	size_t    size; //number of thread
	size_t    current; //the current thread. can be get with get_current
	void *(*function)(void *); // the function that will be call in thread
	void *args; //args that can be used in the called func, can be modified
}							t_multithread;

void create_multithread(t_multithread *threads); // init
void join_multithread(t_multithread *threads); // join the thread. wait for all the thread to be finish
void split(t_multithread *threads); /* init the thread 
																		and in the darkness join them all.
																		same as calling the creation and joining function in a row */
void set_up(t_multithread *threads, 
						size_t size, void *args, void *(*function)(void *)); 
/* set up the threads structure with 
				the number of thread to create
				the args to pass a parameters to the thread
				the function to call with the thread */

t_multithread *get_threadStruct(void *addr); // return the multithread meta struct

size_t get_current(t_multithread *threads); /* need to be call int the thread 
																						function for mutex.
																						return the current thread nb */

extern pthread_mutex_t mutex_aff; // define in multi_thread.c
extern pthread_mutex_t mutex_param; // define in multi_thread.c

#endif