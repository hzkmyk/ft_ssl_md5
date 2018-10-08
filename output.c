/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 11:25:26 by hmiyake           #+#    #+#             */
/*   Updated: 2018/09/30 22:38:29 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

int		flags(char **argv, int *pqrs)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '-')
		{
			pqrs[0] = ft_strchr(argv[i], 'p') ? 1 : 0;
			pqrs[1] = ft_strchr(argv[i], 'q') ? 1 : 0;
			pqrs[2] = ft_strchr(argv[i], 'r') ? 1 : 0;
			pqrs[3] = ft_strchr(argv[i], 's') ? 1 : 0;
		}
		else
			break;
		i++;
	}
	return (i);
}

char	*save_line(char **argv)
{
	int		fd;
	char	*tmp;
	char	*file;
	int		buffsize;
	char	buf[21];
	int		x;

	fd = open(argv[1], O_RDONLY);
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
		printf("here?\n");
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
	printf("%s\n", str);
	return (str);
}