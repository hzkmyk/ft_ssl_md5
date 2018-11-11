/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func256.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 16:16:21 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/10 17:38:28 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

u_int32_t	s0(u_int32_t *nay, int i)
{
	return ((RIGHTROTATE(7, nay[i - 15])) ^ (RIGHTROTATE(18, nay[i - 15]))
	^ (nay[i - 15] >> 3));
}

u_int32_t	s1(u_int32_t *nay, int i)
{
	return ((RIGHTROTATE(17, nay[i - 2])) ^ (RIGHTROTATE(19, nay[i - 2]))
	^ (nay[i - 2] >> 10));
}

u_int32_t	w(u_int32_t *nay, int i)
{
	return (nay[i - 16] + s0(nay, i) + nay[i - 7] + s1(nay, i));
}
