CC		= gcc

RM		= rm -f

NAME		= libmulti_thread.so

test    = dummy

SRCS		=	src/geter.c \
		  		src/multi_thread.c

MAIN    = test_file/main.c

CFLAGS		+= -W -Wall -Werror -Wextra

CPPFLAGS	+= -Iinclude -pthread

DUMMYFLAG += -Ilib -L./lib/ -lmylib

all		: $(NAME)

$(NAME)		: 
		  $(CC) $(CFLAGS) $(CPPFLAGS) -shared -o $(NAME) $(SRCS) -fPIC

test     : $(OBJS)
			$(CC) $(CFLAGS) $(CPPFLAGS) $(DUMMYFLAG) $(SRCS) $(MAIN) -o $(test) 

clean		:
		  $(RM) $(OBJS)

fclean		: clean
		  $(RM) $(NAME)
		  $(RM) $(test)

re		: fclean all

.PHONY		: all clean fclean re
