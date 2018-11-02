/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_words.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:15:33 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/01 15:17:03 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

u_int32_t	**words(int **yay, int *blocks)
{
	u_int32_t	**nay;
	int			i;
	int			j;
	int			k;

	j = 0;
	k = 0;
	nay = (u_int32_t **)malloc(sizeof(u_int32_t *) * blocks[0]);
	while (k < blocks[0])
	{
		nay[k] = (u_int32_t *)malloc(sizeof(u_int32_t) * 16);
		k++;
	}
	k = 0;
	while (k < blocks[0])
	{
		i = 0;
		j = 0;
		while (i < 64)
		{
			nay[k][j] = yay[k][i + 3] << 24;
			nay[k][j] = nay[k][j] + (yay[k][i + 2] << 16);
			nay[k][j] = nay[k][j] + (yay[k][i + 1] << 8);
			nay[k][j] = nay[k][j] + yay[k][i];
			i += 4;
			j += 1;
		}
		k++;
	}
	return (nay);
}