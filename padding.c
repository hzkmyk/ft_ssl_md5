/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:46:08 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/01 17:17:31 by hmiyake          ###   ########.fr       */
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
		ft_bzero(yay[j], 64);
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
		if (!argv[k])
			break;
	}
	i -= 1;
	yay[i][j] = 128;
	j++;
	if (j > 55)
		i++;
	j = 56;
	yay[i][j] = (int)ft_strlen(argv) * 8;
	i = 0;
	return (yay);
}

int		**sha256Padding(const char *argv, int *blocks)
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
		if (!argv[k])
			break;
	}
	i -= 1;
	yay[i][j] = 128;
	j = 63;
	yay[i][j] = (int)ft_strlen(argv) * 8;
	return (yay);
}
