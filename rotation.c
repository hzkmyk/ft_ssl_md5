/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 21:22:27 by hmiyake           #+#    #+#             */
/*   Updated: 2018/09/30 14:29:22 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

u_int32_t	rotate(const int rot, u_int32_t x)
{
	// return (x << rot | x >> (32 - rot));
	u_int32_t tmp;

	tmp = x;
	tmp = tmp << rot;
	x = x >> (32 - rot);
	x = x + tmp;
	return (x);
}

int			little_endian(int iv)
{
	int	tmp[4];

	tmp[0] = (iv & 0xFF000000) >> 24;
	tmp[1] = (iv & 0x00FF0000) >> 8;
	tmp[2] = (iv & 0x0000FF00) << 8;
	tmp[3] = (iv & 0x000000FF) << 24;
	tmp[0] = tmp[0] + tmp[1] + tmp[2] + tmp[3];
	return (tmp[0]); 
}

void		fix_value(int *iv)
{
	int i;

	i = 0;
	while (i < 4)
	{
		iv[i] = little_endian(iv[i]);
		i++;
	}
}