# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 00:51:07 by ommadhi           #+#    #+#              #
#    Updated: 2019/11/16 11:41:06 by ommadhi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  src/minishell.c\
		src/ft_cd.c\
		src/ft_envp.c\
		src/ft_check_path.c\
		src/ft_setenv.c\
		src/ft_echo.c\
		src/ft_free_exit.c\
		src/ft_error.c\
		src/ft_git.c\
		src/ft_func.c\
		src/helpecho.c\
		src/ft_dol_fun.c\

OBJS    = $(SRCS:.c=.o)
	NAME    = minishell
	CFLAG   = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C libft
	gcc $(CFLAGS) $(SRCS) libft/libft.a -o $(NAME)

clean :
	rm -rf $(OBJS)
	@make -C libft clean

fclean : clean
	rm -rf $(NAME)
	@make -C libft fclean

re : fclean all
