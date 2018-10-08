/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:46:08 by hmiyake           #+#    #+#             */
/*   Updated: 2018/09/29 23:08:58 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

int		**malloc_blocks(const char *argv, int *blocks)
{
	size_t	i;
	int		j;
	int		**yay;

	i = ft_strlen(argv);
	j = 0;
	blocks[0] = i / 64;
	if (i % 64 > 55)
		blocks[0] += 2;
	else if (i % 64 < 56)
		blocks[0] += 1;
	yay = (int **)malloc(sizeof(int *) * blocks[0]);
	while (j < blocks[0])
	{
		yay[j] = (int *)malloc(sizeof(int) * 64);
		j++;
	}
	return (yay);
}

int		**padding(const char *argv, int *blocks)
{
	int	i;
	int	j;
	int	k;
	int	**yay;

	i = 0;
	k = 0;
	yay = malloc_blocks(argv, blocks);
	while (i < blocks[0])
	{
		j = 0;
		while (j < 64 && argv[k])
		{
			yay[i][j] = argv[k];
			j++;
			k++;
		}
		i++;
	}
	i -= 1;
	yay[i][j] = 128;
	j++;
	while (j < 56)
	{
		yay[i][j] = 0;
		j++;
	}
	yay[i][j] = (int)ft_strlen(argv) * 8;
	j++;
	while (j < 64)
	{
		yay[i][j] = 0;
		j++;
	}
	return (yay);
}

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
