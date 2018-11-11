/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:15:33 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/11 14:44:47 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

u_int32_t	**words(t_ssl *ssl)
{
	int			i;
	int			j;
	int			k;

	j = 0;
	k = -1;
	ssl->word = (u_int32_t **)malloc(sizeof(u_int32_t *) * ssl->numblock);
	while (++k < ssl->numblock)
		ssl->word[k] = (u_int32_t *)malloc(sizeof(u_int32_t) * 16);
	k = -1;
	while (++k < ssl->numblock)
	{
		i = 0;
		j = 0;
		while (i < 64)
		{
			ssl->word[k][j] = ssl->block[k][i + 3] << 24;
			ssl->word[k][j] = ssl->word[k][j] + (ssl->block[k][i + 2] << 16);
			ssl->word[k][j] = ssl->word[k][j] + (ssl->block[k][i + 1] << 8);
			ssl->word[k][j] = ssl->word[k][j] + ssl->block[k][i];
			i += 4;
			j += 1;
		}
	}
	return (ssl->word);
}
