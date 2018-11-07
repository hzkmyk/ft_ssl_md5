/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words256.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:17:36 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/06 22:14:02 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

u_int32_t	**words256_2(t_ssl *ssl)
{
	int i;
	int k;
	
	k = -1;
    while (++k < ssl->numBlock)
    {
        i = 16;
        while (i < 64)
        {
            ssl->word[k][i] = w(ssl->word[k], i);
            i++;
        }
    }
	return (ssl->word);
}

u_int32_t	**words256(t_ssl *ssl)
{
	int			i;
	int			j;
	int			k;

	j = 0;
	k = -1;
	ssl->word = (u_int32_t **)malloc(sizeof(u_int32_t *) * ssl->numBlock);
	while (++k < ssl->numBlock)
		ssl->word[k] = (u_int32_t *)malloc(sizeof(u_int32_t) * 64);
	k = -1;
	while (++k < ssl->numBlock)
	{
		i = 0;
		j = 0;
		while (i < 64)
		{
			ssl->word[k][j] = ssl->block[k][i] << 24;
			ssl->word[k][j] = ssl->word[k][j] + (ssl->block[k][i + 1] << 16);
			ssl->word[k][j] = ssl->word[k][j] + (ssl->block[k][i + 2] << 8);
			ssl->word[k][j] = ssl->word[k][j] + ssl->block[k][i + 3];
			i += 4;
			j += 1;
		}
	}
	return (words256_2(ssl));
}
