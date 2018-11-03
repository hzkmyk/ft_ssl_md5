/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_md5.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 09:55:15 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/03 15:36:10 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_MD5_H
# define FT_SSL_MD5_H
# include "libft/libft.h"
# include "libft/ft_printf.h"
# include <stdio.h>
# include <sys/stat.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# define ISSAME(pqrs, flag) ((pqrs & flag) == flag)
# define P 8
# define Q 4
# define R 2
# define S 1
# define BUFFSIZE 20
# define LEFTROTATE(rot, x) ((x << rot | x >> (32 - rot)))
# define RIGHTROTATE(rot, x) ((x >> rot | x << (32 - rot)))

typedef struct	s_ssl
{
	u_int32_t		iv[8];
	u_int32_t		uv[8];
	int				**block;
	u_int32_t		**word;
	int				*pqrs;
	int				numBlock;
}				t_ssl;

typedef void	(hash)(int, char **);

typedef struct	s_dsptch
{
	char    *name;
	hash    *hash;
}				t_dsptch;

/* padding.c */
int			**padding(const char *argv, t_ssl *ssl);
int			**sha256Padding(const char *argv, t_ssl *ssl);
int			**malloc_blocks(const char *argv, t_ssl *ssl);

/* md5_words.c */
u_int32_t	**words(int **yay, int blocks);

void		fix_value(u_int32_t *iv);

/* round.c */
void		round_1(u_int32_t *in, const int *rot, const int *k, u_int32_t *nay);
void		round_2(u_int32_t *in, const int *rot, const int *k, u_int32_t *nay);
void		round_3(u_int32_t *in, const int *rot, const int *k, u_int32_t *nay);
void		round_4(u_int32_t *in, const int *rot, const int *k, u_int32_t *nay);

/* fghi.c */
u_int32_t	f(u_int32_t *iv);
u_int32_t	g(u_int32_t *iv);
u_int32_t	h(u_int32_t *iv);
u_int32_t	i(u_int32_t *iv);

/* output.c */
int			flags(char **argv, int i, t_ssl *ssl);
char		*save_line(char **argv, int i);
char		*flag_s(char **argv);

/* check.c */
int			is_directory(char *argv);
int			is_file(char *argv);

/* md5.c */
void		md5(int argc, char **argv);
void		flagP(t_ssl *ssl);

/* ssw.c */
u_int32_t w(u_int32_t *nay, int i);
u_int32_t         s2(t_ssl *ssl);
u_int32_t         s3(t_ssl *ssl);
u_int32_t         ch(t_ssl *ssl);
u_int32_t         maj(t_ssl *ssl);

u_int32_t	**sha256Words(t_ssl *ssl);

void    sha256(int argc, char **argv);

int				disableS(int *i);

#endif