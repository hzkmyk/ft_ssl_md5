/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 13:05:40 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/07 12:32:20 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
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

typedef struct		s_ssl
{
	u_int32_t		iv[8];
	u_int32_t		uv[8];
	int				**block;
	u_int32_t		**word;
	int				*pqrs;
	int				numBlock;
}					t_ssl;

# include "ft_ssl_md5.h"
# include "ft_ssl_sha256.h"

typedef void	(hash)(int, char **);
typedef struct		s_dsptch
{
	char    		*name;
	hash    		*hash;
}					t_dsptch;

/* flagPflagS.c */
int					disableS(int i);

/* padding.c */
int					**padding5(const char *argv, t_ssl *ssl);
int					**padding256(const char *argv, t_ssl *ssl);
int					**malloc_blocks(const char *argv, t_ssl *ssl);

/* flag.c */
void				flags(char **argv, int *i, t_ssl *ssl);
char				*save_line(char **argv, int i);

/* check.c */
int					is_directory(char *argv);
int					is_file(char *argv);

/* md5.c */
void				md5(int argc, char **argv);
t_ssl				*inSsl(int *i, int argc, char **argv);

/* sha256.c */
void    			sha256(int argc, char **argv);

/* sha512.c */
void    			sha512(int argc, char **argv);

/* libft func */
void    			ft_fdintdel(int ***ap, t_ssl *ssl);
void    			ft_fduintdel(u_int32_t ***ap, t_ssl *ssl);
#endif