# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/25 09:47:12 by hmiyake           #+#    #+#              #
#    Updated: 2018/09/27 14:39:45 by hmiyake          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

SRCS = *.c

SRCO = $(SRCS:.c=.o)

INCLUDES = ft_ssl_md5.h

LIBFT = libft -lft

FLG = -Wall -Werror -Wextra -c

all: $(NAME)

$(NAME):
	@make -C $(LIBFT)
	@gcc $(FLG) $(SRCS) -I $(INCLUDES)
	@gcc $(SRCO) -L $(LIBFT) -o $(NAME)
clean:
	@make -C libft/ clean
	@rm -f $(SRCO)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all