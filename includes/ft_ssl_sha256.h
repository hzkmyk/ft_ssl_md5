/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_sha256.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 13:09:46 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/06 21:58:13 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_SHA256_H
# define FT_SSL_SHA256_H
# include "ft_ssl.h"

/* func256.c */
u_int32_t   w(u_int32_t *nay, int i);
u_int32_t	s2(t_ssl *ssl);
u_int32_t	s3(t_ssl *ssl);
u_int32_t 	ch(t_ssl *ssl);
u_int32_t	maj(t_ssl *ssl);

/* words256.c */
u_int32_t	**words256(t_ssl *ssl);

/* sha256.c */
void	    def256(t_ssl *ssl, int *i);
void		flagP256(t_ssl *ssl, int *i);

/* value256.c */
t_ssl   	*val256(t_ssl *ssl);
void	    fix256(t_ssl *ssl);

#endif