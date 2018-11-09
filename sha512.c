/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 22:19:34 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/08 23:34:12 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ssl.h"

void	def512(t_ssl *ssl, int *i)
{
	char		buff[1024];
	char		*input;
	int			readsize;
	char		*tmp;

	val512(ssl);
	i[1] = disableS(i[1]);
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
	ft_strdel(&input);
	ft_fdu64intdel(&ssl->block512, ssl);
	ft_fdu64intdel(&ssl->word512, ssl);
	ft_printf("%.16llx%.16llx%.16llx%.16llx%.16llx%.16llx%.16llx%.16llx\n", ssl->uv512[0], ssl->uv512[1], ssl->uv512[2], ssl->uv512[3], ssl->uv512[4], ssl->uv512[5], ssl->uv512[6], ssl->uv512[7]);
}

void	flagP512(t_ssl *ssl, int *i)
{
	def256(ssl, i);
	*ssl->pqrs = *ssl->pqrs & 7;
}

void    sha512(int argc, char **argv)
{
    t_ssl   *ssl;
    int     i[2];

    ssl = inSsl(i, argc, argv);
    // do
    // {
    //     flags(argv, i, ssl);
    //     if (ISSAME(*ssl->pqrs, P))
	// 	{
	// 		flagP512(ssl, i);
	// 		continue ;
	// 	}
	// 	else if (argv[i[0]] == NULL)
	// 	{
	// 		def256(ssl, i);
	// 		break;
	// 	}
	// 	if (((!ISSAME(*ssl->pqrs, P) && !ISSAME(*ssl->pqrs, S) && (argv[i[0]]))) || i[1] == 2)
	// 		def_with_arg256(argv, i, ssl);
	// 	if (ISSAME(*ssl->pqrs, S) && i[1] != 2)
	// 		flagS256(argv, i, ssl);
	// 	i[0]++;
    // } while (argv[i[0]]);
}