/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:17:36 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/02 17:20:47 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

u_int32_t	**sha256Words(t_ssl *ssl)
{
	int			i;
	int			j;
	int			k;

	j = 0;
	k = 0;
	ssl->word = (u_int32_t **)malloc(sizeof(u_int32_t *) * ssl->numBlock);
	while (k < ssl->numBlock)
	{
		ssl->word[k] = (u_int32_t *)malloc(sizeof(u_int32_t) * 64);
		k++;
	}
	k = 0;
	while (k < ssl->numBlock)
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
		k++;
	}
    k = 0;
    while (k < ssl->numBlock)
    {
        i = 16;
        while (i < 64)
        {
            ssl->word[k][i] = w(ssl->word[k], i);
            i++;
        }
        k++;
    }
	return (ssl->word);
}