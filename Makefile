##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## script to build lib
##

ARRAY_SRC	=	src/array_init.c		\
				src/array_destroy.c		\
				
TEST_SRC	=	tests/at.c				\
				tests/delete.c			\
				tests/clear.c			\
				tests/apply.c			\
				tests/insert.c			\
				tests/merge.c			\
				tests/occurrence.c		\
				tests/push_back.c		\
				tests/size.c			\
				tests/sort.c			\
				tests/to_string.c		\
				tests/whereis.c			\

NAME		=	array

TEST_NAME 	=	array_tests

OBJS		=	$(ARRAY_SRC:.c=.o)

TEST_OBJS 	= $(ARRAY_SRC:.c=.o) $(TEST_SRC:.c=.o)

CC	= gcc

RM	= rm -f

CFLAGS = -Wall -Wextra -g3 -I ./includes/

TEST_FLAGS = -I ./includes/ -lcriterion;

all:	$(NAME) $(TEST_NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

$(TEST_NAME):	$(TEST_OBJS)
	$(CC) -o $(TEST_NAME) $(TEST_OBJS) $(CFLAGS) $(TEST_FLAGS)

clean:
	rm -f $(OBJS) $(TEST_OBJS)

fclean:	clean
	$(RM) $(NAME) $(TEST_NAME)

re:		fclean all

.PHONY:	all clean fclean re