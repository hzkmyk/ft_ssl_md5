/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 12:44:04 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/06 23:10:20 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ssl.h"

int	is_directory(char *argv)
{
	struct stat	st;

	if (!lstat(argv, &st))
	{
		if (S_ISDIR(st.st_mode))
			return (1);
	}
	return (0);
}

char	*save_line(char **argv, int i)
{
	int		fd;
	char	*tmp;
	char	*file;
	char	buf[21];
	int		x;

	fd = open(argv[i], O_RDONLY);
	file = ft_strnew(0);
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

int	is_file(char *argv)
{
	struct stat	st;

	if (!stat(argv, &st))
	{
		if (S_ISREG(st.st_mode))
			return (1);
	}
	return (0);
}