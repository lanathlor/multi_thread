#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include "libmy.h"
#include "multi_thread.h"
	
char **tab;

static int get_currentInt(t_multithread *threads)
{
	int *tmp;
	int ret;

	tmp = (int *)threads->args;
	ret = tmp[get_current(threads)];
	return (ret);
}

static void *my_set(void *addr)
{
	char *str;
	char *tmp;
	int fd;
	t_multithread *threads;

	threads = get_threadStruct(addr);
	fd  = get_currentInt(threads);
	str = NULL;
	tmp = NULL;
	while ((tmp = gnl(fd))) // read the whole file and stock it in a single string
	{
		str = my_strcat(str, tmp, SUCCESS); //near same as strcat's libc
		str = my_strcat(str, "\n", FAILURE);
	}
	pthread_mutex_lock(&mutex_aff); // define in src/mutli_thread.c
	my_putstr("set of ");
	my_putnbr(fd);
	my_putstr(" done\n");
	pthread_mutex_unlock(&mutex_aff);
	tab[fd - 3] = my_strcpy(tab[fd - 3], str, SUCCESS); // fd - 3 = current thread
	pthread_exit(NULL); /* stop the thread safly, 
											the parameter is return as if it was a simple return() call */
}

int main(int argc, char **argv)
{
	int NB_READ = my_getnbr(argv[2], FAILURE); // near same as atoi's libc
	int fd[NB_READ];
	int i;
	t_multithread threads;

	i = 0;
	if (argc < 3)
		exit(84);
	if ((tab = malloc(sizeof(char *) * (NB_READ + 1))) == NULL)
		my_perror(M_FAIL); // near same as perror's libc.
	while (i < NB_READ) // open the argv[2] nb of argv[1] files
	{
		if ((fd[i] = open(argv[1], O_RDONLY)) == -1)
		{
			perror("Error : ");
			exit(84);
		}
		i++;
	}

	set_up(&threads, NB_READ, &fd, my_set);
	split(&threads);

	i = 0;
	while (i < NB_READ) // close all the files
	{
		close(fd[i]);
		i++;
	}
	tab[NB_READ] = NULL;
	my_puttab((const char **)tab); // put all of the array
	free_tab(tab); // free all the string then the array in same place
	free(threads.thread); // malloc'ed in create_multithread
	return(1);
}