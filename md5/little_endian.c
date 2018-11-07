/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_endian.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 21:22:27 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/04 17:40:19 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

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

void		fix_value(u_int32_t *iv)
{
	int i;

	i = 0;
	while (i < 4)
	{
		iv[i] = little_endian(iv[i]);
		i++;
	}
}
