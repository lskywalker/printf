# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lsmit <lsmit@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/10 13:02:00 by lsmit          #+#    #+#                 #
#    Updated: 2020/01/17 11:11:43 by lsmit         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = src/*.c

O = *.o

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAG) $(SRC) -c
	ar rcs $(NAME) $(O) $?

%.o: %.c
	gcc -c $(FLAG) -o $<

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
