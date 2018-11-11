/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func512_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:30:54 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/10 19:14:01 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

u_int64_t	s2_512(t_ssl *ssl)
{
	return ((RIGHTROTATE512(14, ssl->iv512[4])) ^
	(RIGHTROTATE512(18, ssl->iv512[4])) ^ (RIGHTROTATE512(41, ssl->iv512[4])));
}

u_int64_t	s3_512(t_ssl *ssl)
{
	return ((RIGHTROTATE512(28, ssl->iv512[0])) ^
	(RIGHTROTATE512(34, ssl->iv512[0])) ^ (RIGHTROTATE512(39, ssl->iv512[0])));
}

u_int64_t	ch512(t_ssl *ssl)
{
	return ((ssl->iv512[4] & ssl->iv512[5]) ^
	(~(ssl->iv512[4]) & ssl->iv512[6]));
}

u_int64_t	maj512(t_ssl *ssl)
{
	return ((ssl->iv512[0] & ssl->iv512[1]) ^
	(ssl->iv512[0] & ssl->iv512[2]) ^ (ssl->iv512[1] & ssl->iv512[2]));
}
