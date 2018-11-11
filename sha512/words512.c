/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words512.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:38:42 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/11 14:46:10 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

u_int64_t	**words512_3(t_ssl *ssl)
{
	int	i;
	int	k;

	k = -1;
	while (++k < ssl->numblock)
	{
		i = 16;
		while (i < 80)
		{
			ssl->word512[k][i] = w512(ssl->word512[k], i);
			i++;
		}
	}
	return (ssl->word512);
}

void		words512_2(t_ssl *ssl, int i, int j, int k)
{
	ssl->word512[k][j] = ssl->block512[k][i] << 56;
	ssl->word512[k][j] = ssl->word512[k][j]
	+ (ssl->block512[k][i + 1] << 48);
	ssl->word512[k][j] = ssl->word512[k][j]
	+ (ssl->block512[k][i + 2] << 40);
	ssl->word512[k][j] = ssl->word512[k][j]
	+ (ssl->block512[k][i + 3] << 32);
	ssl->word512[k][j] = ssl->word512[k][j]
	+ (ssl->block512[k][i + 4] << 24);
	ssl->word512[k][j] = ssl->word512[k][j]
	+ (ssl->block512[k][i + 5] << 16);
	ssl->word512[k][j] = ssl->word512[k][j]
	+ (ssl->block512[k][i + 6] << 8);
	ssl->word512[k][j] = ssl->word512[k][j]
	+ ssl->block512[k][i + 7];
}

u_int64_t	**words512(t_ssl *ssl)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	k = -1;
	ssl->word512 = (u_int64_t **)malloc(sizeof(u_int64_t *) * ssl->numblock);
	while (++k < ssl->numblock)
		ssl->word512[k] = (u_int64_t *)malloc(sizeof(u_int64_t) * 80);
	k = -1;
	while (++k < ssl->numblock)
	{
		i = 0;
		j = 0;
		while (i < 128)
		{
			words512_2(ssl, i, j, k);
			i += 8;
			j += 1;
		}
	}
	return (words512_3(ssl));
}
