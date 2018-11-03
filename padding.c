/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:46:08 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/02 17:17:38 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

int		**malloc_blocks(const char *argv, t_ssl *ssl)
{
	size_t	i;
	int		j;

	i = ft_strlen(argv);
	j = 0;
	ssl->numBlock = i / 64;
	if (i % 64 > 55)
		ssl->numBlock += 2;
	else if (i % 64 < 56)
		ssl->numBlock += 1;
	ssl->block = (int **)malloc(sizeof(int *) * ssl->numBlock);
	while (j < (ssl->numBlock))
	{
		ssl->block[j] = (int *)malloc(sizeof(int) * 64);
		ft_bzero(ssl->block[j], 64);
		j++;
	}
	return (ssl->block);
}

int		**padding(const char *argv, t_ssl *ssl)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	ssl->block = malloc_blocks(argv, ssl);
	while (i < (ssl->numBlock))
	{
		j = 0;
		while (j < 64 && argv[k])
		{
			ssl->block[i][j] = argv[k];
			j++;
			k++;
		}
		i++;
		if (!argv[k])
			break;
	}
	i -= 1;
	ssl->block[i][j] = 128;
	j++;
	if (j > 55)
		i++;
	j = 56;
	ssl->block[i][j] = (int)ft_strlen(argv) * 8;
	i = 0;
	return (ssl->block);
}

int		**sha256Padding(const char *argv, t_ssl *ssl)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	ssl->block = malloc_blocks(argv, ssl);
	while (i < (ssl->numBlock))
	{
		j = 0;
		while (j < 64 && argv[k])
		{
			ssl->block[i][j] = argv[k];
			j++;
			k++;
		}
		i++;
		if (!argv[k])
			break;
	}
	i -= 1;
	ssl->block[i][j] = 128;
	j = 63;
	ssl->block[i][j] = (int)ft_strlen(argv) * 8;
	return (ssl->block);
}
