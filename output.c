/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 11:25:26 by hmiyake           #+#    #+#             */
/*   Updated: 2018/10/29 18:30:45 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

int		flags(char **argv, int *pqrs)
{
	int	i;
	int len;

	i = 2;
	*pqrs = 0;
	len = 0;
	while (argv[i])
	{
		if (argv[i][0] == '-' && argv[i][1])
		{
			if ((len = ft_strchr_i(argv[i], 's')) > 0)
				*pqrs = S;
			len = len ? len : ft_strlen(argv[i]);
			*pqrs |= ft_strnstr(argv[i], "p", len) ? P : 0;
			*pqrs |= ft_strnstr(argv[i], "q", len) ? Q : 0;
			*pqrs |= ft_strnstr(argv[i], "r", len) ? R : 0;
			if (ISSAME(*pqrs, S))
				break;
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
	int		buffsize;
	char	buf[21];
	int		x;

	fd = open(argv[i], O_RDONLY);
	buffsize = 20;
	file = "";
	while ((x = read(fd, buf, buffsize)))
	{
		buf[x] = '\0';
		tmp = ft_strdup(buf);
		file = ft_strjoin(file, tmp);
		free(tmp);
	}
	close(fd);
	return (file);
}

char	*flag_s(char **argv)
{
	size_t	i;
	size_t	len;
	char	*str;
	
	i = 2;
	len = ft_strlen(argv[1]);
	if (argv[1][0] == '-' && argv[1][1] == 's')
	{
		if (len > 2)
		{
			str = (char *)malloc(sizeof(char) * (len - 2));
			while (i < len)
			{
				str[i - 2] = argv[1][i];
				i++;
			}
		}
		else
		{
			len = ft_strlen(argv[1 + 1]);
			str = (char *)malloc(sizeof(char) * len);
			i = 0;
			while (i < len)
			{
				str[i] = argv[1 + 1][i];
				i++;
			}
		}
	}
	else
		str = NULL;
	// printf("%s\n", str);
	return (str);
}