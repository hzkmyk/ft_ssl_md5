/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 11:25:26 by hmiyake           #+#    #+#             */
/*   Updated: 2018/10/31 22:36:45 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

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

int		flags(char **argv, int *pqrs, int i, t_initial *in)
{
	int len;
	char c;
	int **yay;
	u_int32_t **nay;
	int test;

	*pqrs = *pqrs & 6;
	len = 0;
	yay = NULL;
	nay = NULL;
	while (argv[i])
	{
		if (argv[i][0] == '-' && argv[i][1])
		{
			if ((len = ft_strchr_i(argv[i], 's')) > 0)
				*pqrs += S;
			len = len ? len : ft_strlen(argv[i]);
			*pqrs |= ft_strnstr(argv[i], "p", len) ? P : 0;
			*pqrs |= ft_strnstr(argv[i], "q", len) ? Q : 0;
			*pqrs |= ft_strnstr(argv[i], "r", len) ? R : 0;
			if (ISSAME(*pqrs, S))
				break;
			if (((test = ft_strchr_i(argv[i], 'p')) > 0))
			{
				if ((c = invalid(argv[i], test)))
				{
					ft_printf("md5: illegal option -- %c\nusage: md5 [-pqr] [-s string] [files ...]\n", c);
					exit (1);
				}
			}
			if (*pqrs < 8 && (c = invalid(argv[i], ft_strlen(argv[i]))))
			{
				ft_printf("md5: illegal option -- %c\nusage: md5 [-pqr] [-s string] [files ...]\n", c);
				exit (1);
			}
			else if (*pqrs >= 8 && (c = invalid(argv[i], ft_strlen(argv[i]))))
			{
				flagP(pqrs, yay, nay, in);
				ft_printf("md5: illegal option -- %c\nusage: md5 [-pqr] [-s string] [files ...]\n", c);
				exit (1);
			}
			
		}
		else
			break;
		i++;
	}
	return (i);
}

char	*save_line(char **argv, int i)
{
	int		fd;
	char	*tmp;
	char	*file;
	char	buf[21];
	int		x;

	fd = open(argv[i], O_RDONLY);
	file = "";
	while ((x = read(fd, buf, BUFFSIZE)))
	{
		buf[x] = '\0';
		tmp = ft_strdup(buf);
		file = ft_strjoin(file, tmp);
		free(tmp);
	}
	close(fd);
	return (file);
}