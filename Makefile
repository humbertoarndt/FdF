# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 23:10:48 by harndt            #+#    #+#              #
#    Updated: 2022/08/05 02:20:10 by harndt           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	fdf
CC			:=	cc
LINKS		:=	-lmlx -lm -lz -Llibft -lXext -lX11
CFLAGS		:=	-O3 -g -Wall -Werror -Wextra
HEADERS		:=	includes
LIBFT		:=	./libft/libft.a
SRCS		:=	fdf.c	./srcs/initialize.c	./srcs/free.c	./srcs/read.c	\
				./srcs/legend.c	./srcs/key_hooks.c	./srcs/color.c	./srcs/draw.c	\
				./srcs/projection.c	./srcs/rotate.c ./srcs/mouse_hooks.c	\
				./srcs/image.c

OBJS		:=	$(SRCS:.c=.o)

GREEN		:= \033[1;32m
RED			:= \033[1;31m
WHT			:= \033[1;37m
EOC			:= \033[1;0m

all:		$(NAME)

%.o:		%.c
			@$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

$(NAME):	$(OBJS) $(LIBFT)
			@echo "$(WHT)Compiling FDF...$(EOC)"
			@$(CC) $(OBJS) $(LINKS) $(LIBFT) -o $@
			@echo "$(GREEN)FDF build completed.$(EOC)"

$(LIBFT):
			@echo "$(WHT)Compiling lbft...$(EOC)"
			@make -C libft
			@echo "$(GREEN)Libft done.$(EOC)"

clean:
			@echo "$(WHT)Removing .o files...$(EOC)"
			@rm -f $(OBJS)
			@make -C libft clean
			@echo "$(GREEN)Clean done.$(EOC)"

fclean:		clean
			@echo "$(WHT)Removing object- and binary -files...$(EOC)"
			@rm -f $(NAME)
			@make -C libft fclean
			@echo "$(GREEN)Fclean done.$(EOC)"

re:			fclean all

leak:
			@echo "$(WHT)Removing old log.$(EOC)"
			@rm -f valgrind-out.txt
			@echo "$(WHT)Old log removed.$(EOC)"
			@echo "$(WHT)Executing Valgrind.$(EOC)"
			@valgrind --leak-check=full --show-leak-kinds=reachable --track-origins=yes --main-stacksize=8388608000 \
			--log-file=valgrind-out.txt \
			./$(NAME) 42.fdf
			@echo "$(GREEN)Valgrind-log created.$(EOC)"

.PHONY:		all clean fclean re