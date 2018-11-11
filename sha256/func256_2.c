/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func256_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 22:03:22 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/10 18:56:05 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

u_int32_t	s2(t_ssl *ssl)
{
	return ((RIGHTROTATE(6, ssl->iv[4])) ^
	(RIGHTROTATE(11, ssl->iv[4])) ^ (RIGHTROTATE(25, ssl->iv[4])));
}

u_int32_t	s3(t_ssl *ssl)
{
	return ((RIGHTROTATE(2, ssl->iv[0]))
	^ (RIGHTROTATE(13, ssl->iv[0])) ^ (RIGHTROTATE(22, ssl->iv[0])));
}

u_int32_t	ch(t_ssl *ssl)
{
	return ((ssl->iv[4] & ssl->iv[5]) ^ (~(ssl->iv[4]) & ssl->iv[6]));
}

u_int32_t	maj(t_ssl *ssl)
{
	return ((ssl->iv[0] & ssl->iv[1]) ^ (ssl->iv[0] & ssl->iv[2])
	^ (ssl->iv[1] & ssl->iv[2]));
}
