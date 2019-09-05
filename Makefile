# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/25 09:47:12 by hmiyake           #+#    #+#              #
#    Updated: 2018/11/11 17:32:17 by hmiyake          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

MD5 = md5/

SHA256 = sha256/

SHA512 = sha512/

SRCS = check.c \
	   flag.c \
	   free.c \
	   main.c \
	   md5.c \
	   padding.c \
	   printdef.c \
	   printflags.c \
	   sha256.c \
	   sha384.c \
	   sha512.c \
	   sha224.c

SRCS2 = flag_p_and_s.c \
		func5.c \
		hash5.c \
		little_endian.c \
		value5.c \
		words5.c

SRCS3 = func256.c \
		func256_2.c \
		value256.c \
		words256.c

SRCS4 = func512.c \
		func512_2.c \
		value512.c \
		words512.c

SRCO = check.o \
	   flag.o \
	   free.o \
	   main.o \
	   md5.o \
	   padding.o \
	   printdef.o \
	   printflags.o \
	   sha256.o \
	   sha384.o \
	   sha512.o \
	   sha224.o

SRCO2 = $(MD5)flag_p_and_s.o \
		$(MD5)func5.o \
		$(MD5)hash5.o \
		$(MD5)little_endian.o \
		$(MD5)value5.o \
		$(MD5)words5.o

SRCO3 = $(SHA256)func256.o \
		$(SHA256)func256_2.o \
		$(SHA256)value256.o \
		$(SHA256)words256.o

SRCO4 = $(SHA512)func512.o \
		$(SHA512)func512_2.o \
		$(SHA512)value512.o \
		$(SHA512)words512.o

INCLUDES = "includes/ft_ssl.h"

LIBFT = libft -lft

FLG = -Wall -Werror -Wextra -c

all: $(NAME)

$(NAME):
	@make -C $(LIBFT)
	@cd md5; gcc $(FLG) $(SRCS2) -I $(INCLUDES)
	@cd sha256; gcc $(FLG) $(SRCS3) -I $(INCLUDES)
	@cd sha512; gcc $(FLG) $(SRCS4) -I $(INCLUDES)
	@gcc $(FLG) $(SRCS) -I $(INCLUDES)
	@gcc $(SRCO) $(SRCO2) $(SRCO3) $(SRCO4) -L $(LIBFT) -o $(NAME)
clean:
	@make -C libft/ clean
	@rm -f $(SRCO) $(SRCO2) $(SRCO3) $(SRCO4)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all