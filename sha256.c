/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:13:00 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/10 19:58:33 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ssl.h"

void	def256(t_ssl *ssl, int *i)
{
	char		buff[1024];
	char		*input;
	int			readsize;
	char		*tmp;

	val256(ssl);
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
	ssl->block = padding256(input, ssl);
	ssl->word = words256(ssl);
	fix256(ssl);
	ft_strdel(&input);
	ft_fdintdel(&ssl->block, ssl);
	ft_fduintdel(&ssl->word, ssl);
	ft_printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x\n", ssl->uv[0], ssl->uv[1], ssl->uv[2], ssl->uv[3], ssl->uv[4], ssl->uv[5], ssl->uv[6], ssl->uv[7]);
}

void	flag_p256(t_ssl *ssl, int *i)
{
	def256(ssl, i);
	*ssl->pqrs = *ssl->pqrs & 7;
}

void	def_with_arg256(char **argv, int *i, t_ssl *ssl)
{
	char		*file;

	val256(ssl);
	i[1] = disable_s(i[1]);
	if (is_file(argv[i[0]]))
	{
		file = save_line(argv, i[0]);
		ssl->block = padding256(file, ssl);
		ssl->word = words256(ssl);
		fix256(ssl);
		ft_strdel(&file);
		ft_fdintdel(&ssl->block, ssl);
		ft_fduintdel(&ssl->word, ssl);
		if (ISSAME(*ssl->pqrs, Q))
			ft_printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x\n", ssl->uv[0], ssl->uv[1], ssl->uv[2], ssl->uv[3], ssl->uv[4], ssl->uv[5], ssl->uv[6], ssl->uv[7]);
		else if (ISSAME(*ssl->pqrs, R))
			ft_printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x %s\n", ssl->uv[0], ssl->uv[1], ssl->uv[2], ssl->uv[3], ssl->uv[4], ssl->uv[5], ssl->uv[6], ssl->uv[7], argv[i[0]]);
		else
			ft_printf("sha256 (%s) = %.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x\n", argv[i[0]], ssl->uv[0], ssl->uv[1], ssl->uv[2], ssl->uv[3], ssl->uv[4], ssl->uv[5], ssl->uv[6], ssl->uv[7]);
	}
	else if (is_directory(argv[i[0]]))
		ft_printf("sha256: %s: Is a directory\n", argv[i[0]]);
	else
		ft_printf("ft_ssl: sha256: %s: %s\n", argv[i[0]], strerror(errno));
}

void	flag_s256(char **argv, int *i, t_ssl *ssl)
{
	int			len;

	val256(ssl);
	if ((len = ft_strchr_i(argv[i[0]], 's')) > 0 && argv[i[0]][len + 1])
		ssl->block = padding256(argv[i[0]] + (len + 1), ssl);
	else
	{
		len = -1;
		if (argv[(i[0]++) + 1])
			ssl->block = padding256(argv[i[0]], ssl);
		else
		{
			ft_printf("sha256: option requires an argument -- s\n"
			"usage: sha256 [-pqrtx] [-s string] [files ...]\n");
			exit (1);
		}
	}
	ssl->word = words256(ssl);
	fix256(ssl);
	ft_fdintdel(&ssl->block, ssl);
	ft_fduintdel(&ssl->word, ssl);
	printflags256(ssl, argv, len, i);
	i[1] = 1;
}

void	sha256(int argc, char **argv)
{
	t_ssl		*ssl;
	int			i[2];
	
	ssl = inssl(i, argc, argv);
	while (argv[i[0]])
	{	
		flags(argv, i, ssl);
		if (ISSAME(*ssl->pqrs, P))
		{
			flag_p256(ssl, i);
			continue ;
		}
		else if (argv[i[0]] == NULL)
		{
			def256(ssl, i);
			break;
		}
		if (((!ISSAME(*ssl->pqrs, P) && !ISSAME(*ssl->pqrs, S) && (argv[i[0]]))) || i[1] == 2)
			def_with_arg256(argv, i, ssl);
		if (ISSAME(*ssl->pqrs, S) && i[1] != 2)
			flag_s256(argv, i, ssl);
		i[0]++;
	}
	free (ssl->pqrs);
	free(ssl);
}
