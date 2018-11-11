/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_md5.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 09:55:15 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/11 14:55:02 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_MD5_H
# define FT_SSL_MD5_H
# include "ft_ssl.h"

typedef struct		s_ssl
{
	u_int32_t		iv[8];
	u_int32_t		uv[8];
	u_int64_t		iv512[8];
	u_int64_t		uv512[8];
	int				**block;
	u_int64_t		**block512;
	u_int32_t		**word;
	u_int64_t		**word512;
	int				*pqrs;
	int				numblock;
}					t_ssl;

/*
** words5.c
*/
u_int32_t			**words(t_ssl *ssl);
/*
** rounds5.c
*/
void				rounds(u_int32_t *in, const int *rot,
const int *k, u_int32_t *nay);
/*
** func5.c
*/
u_int32_t			f(u_int32_t *iv);
u_int32_t			g(u_int32_t *iv);
u_int32_t			h(u_int32_t *iv);
u_int32_t			i(u_int32_t *iv);
/*
** flagPflagS.c
*/
void				flag_p(t_ssl *ssl, int *i);
void				flag_s(char **argv, int *i, t_ssl *ssl);
/*
** value5.c
*/
void				initialize_ivuv(t_ssl *ssl);
void				fix_value(u_int32_t *iv);
void				switch_iv(u_int32_t *iv);
/*
** hash5.c
*/
void				rounds_and_fix(t_ssl *ssl);
/*
** md5.h
*/
void				def(t_ssl *ssl, int *i);
/*
** printdef.c && printflags.c
*/
void				printflags5(t_ssl *ssl, char **argv, int len, int *i);
void				printdefwitharg(t_ssl *ssl, char **argv, int *i);

#endif
