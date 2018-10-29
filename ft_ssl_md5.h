/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_md5.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 09:55:15 by hmiyake           #+#    #+#             */
/*   Updated: 2018/10/29 15:19:40 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_MD5_H
# define FT_SSL_MD5_H
# include "libft/libft.h"
# include "libft/ft_printf.h"
# include <stdio.h>
# include <sys/stat.h>
# include <errno.h>
# include <fcntl.h>
# define ISSAME(pqrs, flag) ((pqrs & flag) == flag)
# define P 8
# define Q 4
# define R 2
# define S 1

typedef void	(hash)(int, char **);

typedef struct		s_dsptch
{
	char    *name;
	hash    *hash;
}					t_dsptch;

/* padding.c */
int			**padding(const char *argv, int *blocks);
u_int32_t	**words(int **yay, int *blocks);
int			**malloc_blocks(const char *argv, int *blocks);

u_int32_t	rotate(const int rot, u_int32_t x);
void		fix_value(int *iv);

/* round.c */
void		round_1(int *iv, const int *rot, const int *k, u_int32_t *nay);
void		round_2(int *iv, const int *rot, const int *k, u_int32_t *nay);
void		round_3(int *iv, const int *rot, const int *k, u_int32_t *nay);
void		round_4(int *iv, const int *rot, const int *k, u_int32_t *nay);

/* fghi.c */
int			f(int *iv);
int			g(int *iv);
int			h(int *iv);
int			i(int *iv);

/* output.c */
int			flags(char **argv, int *pqrs);
char		*save_line(char **argv, int i);
char		*flag_s(char **argv);

/* check.c */
int			is_directory(char *argv);
int			is_file(char *argv);

/* md5.c */
void		md5(int argc, char **argv);

#endif