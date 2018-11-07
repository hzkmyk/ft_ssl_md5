/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 11:25:26 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/06 20:35:43 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ssl.h"

char	invalid(char *argv, int len)
{
	int i;
	
	i = 1;
	while (i < len)
	{
		if (argv[i] != 'p' && argv[i] != 'q' && argv[i] != 'r' && argv[i] != 's')
			return (argv[i]);
		i++;
	}
	return (0);
}

void	exitInvalid(int test, char **argv, int i, t_ssl *ssl)
{
	char c;
	
	if (((test = ft_strchr_i(argv[i], 'p')) > 0))
	{
		if ((c = invalid(argv[i], test)))
		{
			ft_printf("md5: illegal option -- %c\nusage: md5 [-pqr] [-s string] [files ...]\n", c);
			exit (1);
		}
	}
	if (*ssl->pqrs < 8 && (c = invalid(argv[i], ft_strlen(argv[i]))))
	{
		ft_printf("md5: illegal option -- %c\nusage: md5 [-pqr] [-s string] [files ...]\n", c);
		exit (1);
	}
	else if (*ssl->pqrs >= 8 && (c = invalid(argv[i], ft_strlen(argv[i]))))
	{
		if (ft_strcmp(argv[1], "md5"))
			flagP(ssl, &i);
		else
			flagP256(ssl, &i);
		ft_printf("md5: illegal option -- %c\nusage: md5 [-pqr] [-s string] [files ...]\n", c);
		exit (1);
	}
}

void		flags(char **argv, int *i, t_ssl *ssl)
{
	int len;
	int test;

	*ssl->pqrs = *ssl->pqrs & 6;
	len = 0;
	test = 0;
	while (argv[i[0]])
	{
		if (argv[i[0]][0] == '-' && argv[i[0]][1])
		{
			if ((len = ft_strchr_i(argv[i[0]], 's')) > 0)
				*ssl->pqrs += S;
			len = len ? len : ft_strlen(argv[i[0]]);
			*ssl->pqrs |= ft_strnstr(argv[i[0]], "p", len) ? P : 0;
			*ssl->pqrs |= ft_strnstr(argv[i[0]], "q", len) ? Q : 0;
			*ssl->pqrs |= ft_strnstr(argv[i[0]], "r", len) ? R : 0;
			if (ISSAME(*ssl->pqrs, S))
				break;
			exitInvalid(test, argv, i[0], ssl);
		}
		else
			break;
		i[0]++;
	}
}
