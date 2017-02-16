/*
** libmy.h for libmy in /home/vivier_v/script
** 
** Made by valetin vivier
** Login   <vivier_v@epitech.net>
** 
** Started on  Sat Jun 25 14:35:28 2016 valetin vivier
** Last update Mon Jul 11 20:08:44 2016 valetin vivier
*/

#ifndef LIBMY_H_
# define LIBMY_H_

# define FAILURE (-1)
# define NEG_ONE (-1)
# define ERROR (-1)
# define SUCCESS (0)
# define ST_ENTRY (0)
# define ZERO (0)
# define ONE (1)
# define ST_OUT (1)
# define TWO (2)
# define ST_ERROR (2)
# define DECIMAL (10)
# define MAX_INT (2147483647)

# define O_FAIL ("ERROR: open failed\n")
# define M_FAIL ("ERROR: malloc failed.\n")
# define R_FAIL ("ERROR: read failed.\n")
# define W_FAIL ("ERROR: write failed.\n")
# define ZERO_ST ("0")

# define B_N ('\n')
# define ZERO_C ('0')
# define NINE_C ('9')
# define DASH ('-')
# define A_C ('a')
# define Z_C ('z')
# define UA_C ('A')
# define UZ_C ('Z')

typedef struct	s_ptr
{
  char		*str;
  int		indice;
  void		(*fctn)(void);
}		t_ptr;

/*
** my_strtowordtab.c
*/
char	**my_strtab(const char *str);

/*
** my_hashstr.c
*/
char	*my_hashstr(char *str, int i, int j, int free_ck);

/*
** my_strcat.c
*/
char	*my_strcat(char *dest, char *src, int free_ck);

/*
** tab_malloc.c
*/
char	**tab_malloc(int i);

/*
** my_putbase.c
*/
int	convert(int nb, int base, int base_org);
char	*my_getnbrbase(char *nb, int base, int base_org, int free_ck);
void	my_putbase(int nb, char *str);

/*
** my_getstr.c
*/
int	power(int nb, int power);
int	my_intlen(int nb);
char	*my_getstr(int nb);

/*
** my_revstr.c
*/
char	*my_revstr(char *str, int free_ck);

/*
** my_getnbr.c
*/
int	my_getnbr(char *str, int free_ck);

/*
** my_putnbr.c
*/
void	my_putnbr(int nb);

/*
** my_strcpy.c
*/
char	*my_strcpy(char *dest, char *src, int free_ck);

/*
** free_tab.c
*/
void	free_tab(char **tab);
  void	free_error(char *error, char *str, char *str2);

/*
** my_strcmp.c
*/
int	check_in_tab(char **tab, char *str);
int	my_strcmp(const char *str1, const char *str2);

/*
** my_perror.c
*/
int	my_puterror(const char *str);
void	my_perror(const char *str);

/*
** my_putstr.c
*/
void	my_putchar(char c);
int	my_putcharfd(int fd, char c);
void	my_putstr(const char *str);
int	my_putstrfd(const char *str, int fd);
int	my_puttab(const char **tab);

/*
** my_strlen.c
*/
int	my_strlen(const char *str);
int	my_tablen(const char **tab);

/*
** gnl.c
*/
char	*my_realloc(char *str, char buff);
char	*gnl(int fd);

#endif
