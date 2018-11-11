/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 22:19:34 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/11 14:19:45 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ssl.h"

void	def512(t_ssl *ssl, int *i)
{
	char	buff[1024];
	char	*input;
	int		readsize;
	char	*tmp;

	val512(ssl);
	i[1] = disable_s(i[1]);
	input = ft_strnew(0);
	while ((readsize = read(0, buff, 1024)))
	{
		buff[readsize] = '\0';
		tmp = ft_strjoin(input, buff);
		input = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	if (ISSAME(*ssl->pqrs, P))
		ft_printf("%s", input);
	ssl->block512 = padding512(input, ssl);
	ssl->word512 = words512(ssl);
	fix512(ssl);
	free64(ssl, input);
	ft_printf("%.16llx%.16llx%.16llx%.16llx%.16llx%.16llx%.16llx"
	"%.16llx\n", ssl->uv512[0], ssl->uv512[1], ssl->uv512[2], ssl->uv512[3],
	ssl->uv512[4], ssl->uv512[5], ssl->uv512[6], ssl->uv512[7]);
}

void	flag_p512(t_ssl *ssl, int *i)
{
	def512(ssl, i);
	*ssl->pqrs = *ssl->pqrs & 7;
}

void	def_with_arg512(char **argv, int *i, t_ssl *ssl)
{
	char	*file;

	val512(ssl);
	i[1] = disable_s(i[1]);
	if (is_file(argv[i[0]]))
	{
		file = save_line(argv, i[0]);
		ssl->block512 = padding512(file, ssl);
		ssl->word512 = words512(ssl);
		fix512(ssl);
		free64(ssl, file);
		printdefwitharg512(ssl, argv, i);
	}
	else if (is_directory(argv[i[0]]))
		ft_printf("sha512: %s: Is a directory\n", argv[i[0]]);
	else
		ft_printf("ft_ssl: sha512: %s: %s\n", argv[i[0]], strerror(errno));
}

void	flag_s512(char **argv, int *i, t_ssl *ssl)
{
	int			len;

	val512(ssl);
	if ((len = ft_strchr_i(argv[i[0]], 's')) > 0 && argv[i[0]][len + 1])
		ssl->block512 = padding512(argv[i[0]] + (len + 1), ssl);
	else
	{
		len = -1;
		if (argv[(i[0]++) + 1])
			ssl->block512 = padding512(argv[i[0]], ssl);
		else
		{
			ft_printf("sha512: option requires an argument -- s\n"
			"usage: sha512 [-pqrtx] [-s string] [files ...]\n");
			exit(1);
		}
	}
	ssl->word512 = words512(ssl);
	fix512(ssl);
	ft_fdu64intdel(&ssl->block512, ssl);
	ft_fdu64intdel(&ssl->word512, ssl);
	printflags512(ssl, argv, len, i);
	i[1] = 1;
}

void	sha512(int argc, char **argv)
{
	t_ssl	*ssl;
	int		i[2];

	ssl = inssl(i, argc, argv);
	while (argv[i[0]])
	{
		flags(argv, i, ssl);
		if (ISSAME(*ssl->pqrs, P))
		{
			flag_p512(ssl, i);
			continue ;
		}
		else if (argv[i[0]] == NULL)
		{
			def512(ssl, i);
			break ;
		}
		if (((!ISSAME(*ssl->pqrs, P) && !ISSAME(*ssl->pqrs, S)
		&& (argv[i[0]]))) || i[1] == 2)
			def_with_arg512(argv, i, ssl);
		if (ISSAME(*ssl->pqrs, S) && i[1] != 2)
			flag_s512(argv, i, ssl);
		i[0]++;
	}
	freethings(ssl);
}
