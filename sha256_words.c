/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:17:36 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/01 23:23:15 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

u_int32_t	**sha256Words(int **yay, int *blocks)
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
		nay[k] = (u_int32_t *)malloc(sizeof(u_int32_t) * 64);
		k++;
	}
	k = 0;
	while (k < blocks[0])
	{
		i = 0;
		j = 0;
		while (i < 64)
		{
			nay[k][j] = yay[k][i] << 24;
			nay[k][j] = nay[k][j] + (yay[k][i + 1] << 16);
			nay[k][j] = nay[k][j] + (yay[k][i + 2] << 8);
			nay[k][j] = nay[k][j] + yay[k][i + 3];
			i += 4;
			j += 1;
		}
		k++;
	}
    k = 0;
    while (k < blocks[0])
    {
        i = 16;
        while (i < 64)
        {
            nay[k][i] = w(nay[k], i);
            i++;
        }
        k++;
    }
	return (nay);
}