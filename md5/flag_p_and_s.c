/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p_and_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 17:57:59 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/10 17:39:49 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

int		disable_s(int i)
{
	if (i == 1)
		i = 2;
	return (i);
}

void	flag_s(char **argv, int *i, t_ssl *ssl)
{
	int	len;

	initialize_ivuv(ssl);
	if ((len = ft_strchr_i(argv[i[0]], 's')) > 0 && argv[i[0]][len + 1])
		ssl->block = padding5(argv[i[0]] + (len + 1), ssl);
	else
	{
		len = -1;
		if (argv[(i[0]++) + 1])
			ssl->block = padding5(argv[i[0]], ssl);
		else
		{
			ft_printf("md5: option requires an argument -- s\n"
			"usage: md5 [-pqrtx] [-s string] [files ...]\n");
			exit(1);
		}
	}
	ssl->word = words(ssl);
	rounds_and_fix(ssl);
	ft_fdintdel(&ssl->block, ssl);
	ft_fduintdel(&ssl->word, ssl);
	printflags5(ssl, argv, len, i);
	i[1] = 1;
}

void	flag_p(t_ssl *ssl, int *i)
{
	def(ssl, i);
	*ssl->pqrs = *ssl->pqrs & 7;
}
