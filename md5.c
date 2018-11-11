/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 12:46:30 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/10 19:57:06 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ssl.h"

void	def(t_ssl *ssl, int *i)
{
	char		buff[1024];
	char		*input;
	int			readsize;
	char		*tmp;

	initialize_ivuv(ssl);
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
	ssl->block = padding5(input, ssl);
	ssl->word = words(ssl);
	rounds_and_fix(ssl);
	ft_strdel(&input);
	ft_fdintdel(&ssl->block, ssl);
	ft_fduintdel(&ssl->word, ssl);
	ft_printf("%.8x%.8x%.8x%.8x\n",
	ssl->iv[0], ssl->iv[1], ssl->iv[2], ssl->iv[3]);
}

void	def_with_arg(char **argv, int *i, t_ssl *ssl)
{
	char		*file;

	initialize_ivuv(ssl);
	i[1] = disable_s(i[1]);
	if (is_file(argv[i[0]]))
	{
		file = save_line(argv, i[0]);
		ssl->block = padding5(file, ssl);
		ssl->word = words(ssl);
		rounds_and_fix(ssl);
		ft_strdel(&file);
		ft_fdintdel(&ssl->block, ssl);
		ft_fduintdel(&ssl->word, ssl);
		printdefwitharg(ssl, argv, i);
	}
	else if (is_directory(argv[i[0]]))
		ft_printf("md5: %s: Is a directory\n", argv[i[0]]);
	else
		ft_printf("ft_ssl: md5: %s: %s\n", argv[i[0]], strerror(errno));
}

void	noarg(int argc, t_ssl *ssl, char **argv, int *i)
{
	if (argc == 2 && !ft_strcmp(argv[1], "md5"))
	{
		def(ssl, i);
		exit (0);
	}
	else if (argc == 2 && !ft_strcmp(argv[1], "sha256"))
	{
		def256(ssl, i);
		exit (0);
	}
	else if (argc == 2 && !ft_strcmp(argv[1], "sha512"))
	{
		def512(ssl, i);
		exit (0);
	}
	else if (argc == 2 && !ft_strcmp(argv[1], "sha384"))
	{
		def384(ssl, i);
		exit (0);
	}
}

t_ssl	*inssl(int *i, int argc, char **argv)
{
	t_ssl *ssl;

	ssl = (t_ssl *)malloc(sizeof(t_ssl));
	ssl->block = NULL;
	ssl->word = NULL;
	ssl->pqrs = (int *)malloc(sizeof(int));
	*ssl->pqrs = 0;
	ssl->numBlock = 0;
	i[1] = 0;
	i[0] = 2;
	noarg(argc, ssl, argv, i);
	return (ssl);
}

void	md5(int argc, char **argv)
{
	t_ssl		*ssl;
	int			i[2];

	ssl = inssl(i, argc, argv);
	while (argv[i[0]])
	{	
		flags(argv, i, ssl);
		if (ISSAME(*ssl->pqrs, P))
		{
			flag_p(ssl, i);
			continue;
		}
		else if (argv[i[0]] == NULL)
		{
			def(ssl, i);
			break;
		}
		if (((!ISSAME(*ssl->pqrs, P) && !ISSAME(*ssl->pqrs, S) && (argv[i[0]]))) || i[1] == 2)
			def_with_arg(argv, i, ssl);
		if (ISSAME(*ssl->pqrs, S) && i[1] != 2)
			flag_s(argv, i, ssl);
		i[0]++;
	}
	free (ssl->pqrs);
	free(ssl);
}
