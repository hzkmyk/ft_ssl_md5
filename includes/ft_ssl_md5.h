/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_md5.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 09:55:15 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/06 21:58:10 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_MD5_H
# define FT_SSL_MD5_H
# include "ft_ssl.h"

/* words5.c */
u_int32_t	**words(t_ssl *ssl);

void		fix_value(u_int32_t *iv);

/* rounds5.c */
void		rounds(u_int32_t *in, const int *rot, const int *k, u_int32_t *nay);

/* func5.c */
u_int32_t	f(u_int32_t *iv);
u_int32_t   g(u_int32_t *iv);
u_int32_t	h(u_int32_t *iv);
u_int32_t	i(u_int32_t *iv);

/* flagPflagS.c */
void		flagP(t_ssl *ssl, int *i);
void        flagS(char **argv, int *i, t_ssl *ssl);

/* value5.c */
void	    initializeIvUv(t_ssl *ssl);

/* hash5.c */
void		rounds_and_fix(t_ssl *ssl);

void	    def(t_ssl *ssl, int *i);
void	    switch_iv(u_int32_t *iv);

#endif