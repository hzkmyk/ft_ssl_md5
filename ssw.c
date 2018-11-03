/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssw.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 16:16:21 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/02 16:23:46 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

u_int32_t   s0(u_int32_t *nay, int i)
{
    return ((RIGHTROTATE(7, nay[i - 15])) ^ (RIGHTROTATE(18, nay[i - 15])) ^ (nay[i - 15] >> 3));
}

u_int32_t   s1(u_int32_t *nay, int i)
{
    return ((RIGHTROTATE(17, nay[i - 2])) ^ (RIGHTROTATE(19, nay[i - 2])) ^ (nay[i - 2] >> 10));
}

u_int32_t   w(u_int32_t *nay, int i)
{
    return (nay[i - 16] + s0(nay, i) + nay[i - 7] + s1(nay, i));
}

u_int32_t         s2(t_ssl *ssl)
{
    return ((RIGHTROTATE(6, ssl->iv[4])) ^ (RIGHTROTATE(11, ssl->iv[4])) ^ (RIGHTROTATE(25, ssl->iv[4])));
}

u_int32_t         s3(t_ssl *ssl)
{
    return ((RIGHTROTATE(2, ssl->iv[0])) ^ (RIGHTROTATE(13, ssl->iv[0])) ^ (RIGHTROTATE(22, ssl->iv[0])));
}

u_int32_t         ch(t_ssl *ssl)
{
    return ((ssl->iv[4] & ssl->iv[5]) ^ (~(ssl->iv[4]) & ssl->iv[6]));
}

u_int32_t         maj(t_ssl *ssl)
{
    return ((ssl->iv[0] & ssl->iv[1]) ^ (ssl->iv[0] & ssl->iv[2]) ^ (ssl->iv[1] & ssl->iv[2]));
}
