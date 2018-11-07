# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/25 09:47:12 by hmiyake           #+#    #+#              #
#    Updated: 2018/11/05 20:00:41 by hmiyake          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

MD5 = md5/
SHA256 = sha256/
SRCS = *.c
SRCS2 = *.c
SRCS3 = *.c

SRCO = $(SRCS:.c=.o)
SRCO2 = $(MD5)$(SRCS2:.c=.o)
SRCO3 = $(SHA256)$(SRCS3:.c=.o)

INCLUDES = "includes/ft_ssl.h"

LIBFT = libft -lft

FLG = -Wall -Werror -Wextra -c

all: $(NAME)

$(NAME):
	@make -C $(LIBFT)
	@cd md5; gcc $(FLG) $(SRCS) -I $(INCLUDES)
	@cd sha256; gcc $(FLG) $(SRCS2) -I $(INCLUDES)
	@gcc $(FLG) $(SRCS3) -I $(INCLUDES)
	@gcc $(SRCO) $(SRCO2) $(SRCO3) -L $(LIBFT) -o $(NAME)
clean:
	@make -C libft/ clean
	@rm -f $(SRCO) $(SRCO2) $(SRCO3)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all