/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagPflagS.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 17:57:59 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/06 23:14:38 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

int		disableS(int i)
{
	if (i == 1)
		i = 2;
	return (i);
}

void	flagS(char **argv, int *i, t_ssl *ssl)
{
	int			len;

	initializeIvUv(ssl);
	if ((len = ft_strchr_i(argv[i[0]], 's')) > 0 && argv[i[0]][len + 1])
		ssl->block = padding5(argv[i[0]] + (len + 1), ssl);
	else
	{
		len = -1;
		if (argv[(i[0]++) + 1])
			ssl->block = padding5(argv[i[0]], ssl);
		else
		{
			ft_printf("md5: option requires an argument -- s\nusage: md5 [-pqrtx] [-s string] [files ...]\n");
			exit (1);
		}
	}
	ssl->word = words(ssl);
	rounds_and_fix(ssl);
	ft_fdintdel(&ssl->block);
	ft_fduintdel(&ssl->word);
	if (ISSAME(*ssl->pqrs, Q))
		ft_printf("%.8x%.8x%.8x%.8x\n", ssl->iv[0], ssl->iv[1], ssl->iv[2], ssl->iv[3]);
	else if (ISSAME(*ssl->pqrs, R))
		ft_printf("%.8x%.8x%.8x%.8x \"%s\"\n", ssl->iv[0], ssl->iv[1], ssl->iv[2], ssl->iv[3], argv[i[0]] + (len + 1));
	else
		ft_printf("MD5 (\"%s\") = %.8x%.8x%.8x%.8x\n", argv[i[0]] + (len + 1), ssl->iv[0], ssl->iv[1], ssl->iv[2], ssl->iv[3]);
	i[1] = 1;
}

void	flagP(t_ssl *ssl, int *i)
{
	def(ssl, i);
	*ssl->pqrs = *ssl->pqrs & 7;
}