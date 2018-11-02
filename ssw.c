/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssw.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 16:16:21 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/01 22:38:40 by hmiyake          ###   ########.fr       */
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

u_int32_t         s2(t_initial *in)
{
    return ((RIGHTROTATE(6, in->iv[4])) ^ (RIGHTROTATE(11, in->iv[4])) ^ (RIGHTROTATE(25, in->iv[4])));
}

u_int32_t         s3(t_initial *in)
{
    return ((RIGHTROTATE(2, in->iv[0])) ^ (RIGHTROTATE(13, in->iv[0])) ^ (RIGHTROTATE(22, in->iv[0])));
}

u_int32_t         ch(t_initial *in)
{
    return ((in->iv[4] & in->iv[5]) ^ (~(in->iv[4]) & in->iv[6]));
}

u_int32_t         maj(t_initial *in)
{
    return ((in->iv[0] & in->iv[1]) ^ (in->iv[0] & in->iv[2]) ^ (in->iv[1] & in->iv[2]));
}
