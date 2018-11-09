/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func512.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:27:32 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/08 18:20:50 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

u_int64_t   s0_512(u_int64_t *nay, int i)
{
    return ((RIGHTROTATE512(1, nay[i - 15])) ^ (RIGHTROTATE512(8, nay[i - 15])) ^ (nay[i - 15] >> 7));
}

u_int64_t   s1_512(u_int64_t *nay, int i)
{
    return ((RIGHTROTATE512(19, nay[i - 2])) ^ (RIGHTROTATE512(61, nay[i - 2])) ^ (nay[i - 2] >> 6));
}

u_int64_t   w512(u_int64_t *nay, int i)
{
    return (nay[i - 16] + s0_512(nay, i) + nay[i - 7] + s1_512(nay, i));
}