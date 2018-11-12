/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 14:27:52 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/11 15:39:33 by hmiyake          ###   ########.fr       */
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
# define FUNCNUM 4
# define P 8
# define Q 4
# define R 2
# define S 1
# define BUFFSIZE 20
# define LEFTROTATE(rot, x) ((x << rot | x >> (32 - rot)))
# define RIGHTROTATE(rot, x) ((x >> rot | x << (32 - rot)))
# define RIGHTROTATE512(rot, x) ((x >> rot | x << (64 - rot)))
# include "ft_ssl_md5.h"
# include "ft_ssl_sha256.h"
# include "ft_ssl_sha512.h"
# include "ft_ssl_sha384.h"

typedef void		(t_hash)(int, char **);

typedef struct		s_dsptch
{
	char			*name;
	t_hash			*hash;
}					t_dsptch;

/*
** md5.c
*/
void				md5(int argc, char **argv);
t_ssl				*inssl(int *i, int argc, char **argv);
/*
** sha256.c
*/
void				sha256(int argc, char **argv);
/*
** sha512.c
*/
void				sha512(int argc, char **argv);
/*
** sha384.c
*/
void				sha384(int argc, char **argv);
/*
** flagPflagS.c
*/
int					disable_s(int i);
/*
** padding.c
*/
int					**padding5(const char *argv, t_ssl *ssl);
int					**padding256(const char *argv, t_ssl *ssl);
u_int64_t			**padding512(const char *argv, t_ssl *ssl);
int					**malloc_blocks(const char *argv, t_ssl *ssl);
/*
** flag.c
*/
void				flags(char **argv, int *i, t_ssl *ssl);
char				*save_line(char **argv, int i);
/*
** check.c
*/
int					is_directory(char *argv);
int					is_file(char *argv);
/*
** libft func
*/
void				ft_fdintdel(int ***ap, t_ssl *ssl);
void				ft_fduintdel(u_int32_t ***ap, t_ssl *ssl);
void				ft_fdu64intdel(u_int64_t ***ap, t_ssl *ssl);
/*
** free.c
*/
void				freethings(t_ssl *ssl);
void				free64(t_ssl *ssl, char *input);

#endif
