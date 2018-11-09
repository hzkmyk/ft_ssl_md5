/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:46:08 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/08 23:29:25 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ssl.h"

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

u_int64_t		**malloc_blocks512(const char *argv, t_ssl *ssl)
{
	size_t	i;
	int		j;

	i = ft_strlen(argv);
	j = 0;
	ssl->numBlock = i / 128;
	if (i % 128 > 111)
		ssl->numBlock += 2;
	else if (i % 128 < 112)
		ssl->numBlock += 1;
	ssl->block512 = (u_int64_t **)malloc(sizeof(u_int64_t *) * ssl->numBlock);
	while (j < (ssl->numBlock))
	{
		ssl->block512[j] = (u_int64_t *)malloc(sizeof(u_int64_t) * 128);
		ft_bzero(ssl->block512[j], 128);
		j++;
	}
	return (ssl->block512);
}

u_int64_t		**padding512(const char *argv, t_ssl *ssl)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	ssl->block512 = malloc_blocks512(argv, ssl);
	while (i < (ssl->numBlock))
	{
		j = 0;
		while (j < 128 && argv[k])
		{
			ssl->block512[i][j] = argv[k];
			j++;
			k++;
		}
		i++;
		if (!argv[k])
			break;
	}
	i -= 1;
	ssl->block512[i][j] = 128;
	j = 127;
	ssl->block512[i][j] = (int)ft_strlen(argv) * 8;
	return (ssl->block512);
}

int		**padding256(const char *argv, t_ssl *ssl)
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

int		**padding5(const char *argv, t_ssl *ssl)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = -1;
	ssl->block = malloc_blocks(argv, ssl);
	while (i < (ssl->numBlock))
	{
		j = -1;
		while (j++ < 64 && argv[++k])
			ssl->block[i][j] = argv[k];
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
	return (ssl->block);
}
