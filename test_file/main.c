#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include "libmy.h"
#include "multi_thread.h"
	
char **tab;
pthread_mutex_t mutex_aff = PTHREAD_MUTEX_INITIALIZER;

void *my_set(void *addr)
{
	char *str;
	char *tmp;
	int fd;
	t_multithread *threads;

	threads = (t_multithread *)addr;
	fd  = get_currentInt(threads);
	str = NULL;
	tmp = NULL;
	while ((tmp = gnl(fd)))
	{
		str = my_strcat(str, tmp, SUCCESS);
		str = my_strcat(str, "\n", FAILURE);
	}
	pthread_mutex_lock(&mutex_aff);
	my_putstr("set of ");
	my_putnbr(fd);
	my_putstr(" done\n");
	pthread_mutex_unlock(&mutex_aff);
	tab[fd - 3] = my_strcpy(tab[fd - 3], str, SUCCESS);
	pthread_exit(NULL);
}



int main(int argc, char **argv)
{
	int NB_READ = my_getnbr(argv[2], FAILURE);
	int fd[NB_READ];
	int i;
	t_multithread threads;

	i = 0;
	if (argc < 3)
		exit(84);
	if ((tab = malloc(sizeof(char *) * (NB_READ + 1))) == NULL)
		my_perror(M_FAIL);
	while (i < NB_READ)
	{
		if ((fd[i] = open(argv[1], O_RDONLY)) == -1)
		{
			perror("Error : ");
			exit(84);
		}
		i++;
	}

	set_up(&threads, NB_READ, &fd, my_set);
	threads.sense = _vector;
	split(&threads);
	i = 0;

	while (i < NB_READ)
	{
		close(fd[i]);
		i++;
	}
	tab[NB_READ] = NULL;
	my_puttab((const char **)tab);
	free_tab(tab);
	free(threads.thread);
	return(1);
}