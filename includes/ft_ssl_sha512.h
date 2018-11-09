/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_sha512.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:29:58 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/08 19:33:26 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_SHA512_H
# define FT_SSL_SHA512_H
# include "ft_ssl.h"

/* func512.c */
u_int64_t   w512(u_int64_t *nay, int i);

/* value512.c */
void        fix512(t_ssl *ssl);
t_ssl	            *val512(t_ssl *ssl);

/* words521.c */
u_int64_t   **words512(t_ssl *ssl);

/* ft_ssl_md5.c */
void	    def512(t_ssl *ssl, int *i);

/* func512_2.c */
u_int64_t         s2_512(t_ssl *ssl);
u_int64_t         s3_512(t_ssl *ssl);
u_int64_t         ch512(t_ssl *ssl);
u_int64_t         maj512(t_ssl *ssl);

#endif