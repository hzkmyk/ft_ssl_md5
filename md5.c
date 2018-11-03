/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 12:46:30 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/03 15:36:09 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"
#include <unistd.h>
const int	rot[64] = {
	 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
	 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
	 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
	 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
};

const int	k[64] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

void	initializeIvUv(t_ssl *ssl)
{
	ssl->iv[0] = 0x67452301;
	ssl->iv[1] = 0xefcdab89;
	ssl->iv[2] = 0x98badcfe;
	ssl->iv[3] = 0x10325476;
	ssl->uv[0] = 0x67452301;
	ssl->uv[1] = 0xefcdab89;
	ssl->uv[2] = 0x98badcfe;
	ssl->uv[3] = 0x10325476;
}

void		rounds_and_fix(t_ssl *ssl)
{
	int	i;

	i = 0;
	while (i < (ssl->numBlock))
	{
		round_1(ssl->iv, rot, k, ssl->word[i]);
		round_2(ssl->iv, rot, k, ssl->word[i]);
		round_3(ssl->iv, rot, k, ssl->word[i]);
		round_4(ssl->iv, rot, k, ssl->word[i]);
		ssl->iv[0] += ssl->uv[0];
		ssl->iv[1] += ssl->uv[1];
		ssl->iv[2] += ssl->uv[2];
		ssl->iv[3] += ssl->uv[3];
		ssl->uv[0] = ssl->iv[0];
		ssl->uv[1] = ssl->iv[1];
		ssl->uv[2] = ssl->iv[2];
		ssl->uv[3] = ssl->iv[3];
		i++;
	}
	fix_value(ssl->iv);
}

void	def(t_ssl *ssl, int *i)
{
	char		buff[1024];
	char		*input;
	int			readsize;
	char		*tmp;

	initializeIvUv(ssl);
	i[1] = disableS(i);
	input = ft_strnew(0);
	while ((readsize = read(0, buff, 1024)))
	{
		buff[readsize] = '\0';
		tmp = ft_strjoin(input, buff);
		ft_strdel(&input);
		input = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	if (ISSAME(*ssl->pqrs, P))
		ft_printf("%s", input);
	ssl->block = padding(input, ssl);
	ssl->word = words(ssl->block, ssl->numBlock);
	rounds_and_fix(ssl);
	ft_strdel(&input);
	ft_fdintdel(&ssl->block);
	ft_fduintdel(&ssl->word);
	ft_printf("%.8x%.8x%.8x%.8x\n", ssl->iv[0], ssl->iv[1], ssl->iv[2], ssl->iv[3]);
}

void	flagP(t_ssl *ssl, int *i)
{
	def(ssl, i);
	*ssl->pqrs = *ssl->pqrs & 7;
}

void	def_with_arg(char **argv, int *i, t_ssl *ssl)
{
	char		*file;

	initializeIvUv(ssl);
	i[1] = disableS(i);
	if (is_file(argv[i[0]]))
	{
		file = save_line(argv, i[0]);
		ssl->block = padding(file, ssl);
		ssl->word = words(ssl->block, ssl->numBlock);
		rounds_and_fix(ssl);
		ft_strdel(&file);
		ft_fdintdel(&ssl->block);
		ft_fduintdel(&ssl->word);
		if (ISSAME(*ssl->pqrs, Q))
			ft_printf("%.8x%.8x%.8x%.8x\n", ssl->iv[0], ssl->iv[1], ssl->iv[2], ssl->iv[3]);
		else if (ISSAME(*ssl->pqrs, R))
			ft_printf("%.8x%.8x%.8x%.8x %s\n", ssl->iv[0], ssl->iv[1], ssl->iv[2], ssl->iv[3], argv[i[0]]);
		else
			ft_printf("MD5 (%s) = %.8x%.8x%.8x%.8x\n", argv[i[0]], ssl->iv[0], ssl->iv[1], ssl->iv[2], ssl->iv[3]);
	}
	else if (is_directory(argv[i[0]]))
		ft_printf("md5: %s: Is a directory\n", argv[i[0]]);
	else
		ft_printf("ft_ssl: md5: %s: %s\n", argv[i[0]], strerror(errno));
}

void		flagS(char **argv, int *i, t_ssl *ssl)
{
	int			len;

	initializeIvUv(ssl);
	if ((len = ft_strchr_i(argv[i[0]], 's')) > 0 && argv[i[0]][len + 1])
		ssl->block = padding(argv[i[0]] + (len + 1), ssl);
	else
	{
		len = -1;
		if (argv[i[0] + 1])
		{
			i++;
			ssl->block = padding(argv[i[0]], ssl);
		}
		else
		{
			ft_printf("md5: option requires an argument -- s\nusage: md5 [-pqrtx] [-s string] [files ...]\n");
			exit (1);
		}
	}
	ssl->word = words(ssl->block, ssl->numBlock);
	rounds_and_fix(ssl);
	if (ISSAME(*ssl->pqrs, Q))
		ft_printf("%.8x%.8x%.8x%.8x\n", ssl->iv[0], ssl->iv[1], ssl->iv[2], ssl->iv[3]);
	else if (ISSAME(*ssl->pqrs, R))
		ft_printf("%.8x%.8x%.8x%.8x \"%s\"\n", ssl->iv[0], ssl->iv[1], ssl->iv[2], ssl->iv[3], argv[i[0]] + (len + 1));
	else
		ft_printf("MD5 (\"%s\") = %.8x%.8x%.8x%.8x\n", argv[i[0]] + (len + 1), ssl->iv[0], ssl->iv[1], ssl->iv[2], ssl->iv[3]);
	i[1] = 1;
}

int				disableS(int i[1])
{
	if (i[1] == 1)
		i[1] = 2;
	return (i[1]);
}

void			md5(int argc, char **argv)
{
	t_ssl		*ssl;
	int			i[2];

	ssl = (t_ssl *)malloc(sizeof(t_ssl));
	ssl->block = NULL;
	ssl->word = NULL;
	ssl->pqrs = (int *)malloc(sizeof(int));
	*ssl->pqrs = 0;
	ssl->numBlock = 0;
	i[1] = 0;
	i[0] = 2;
	if (argc == 2)
	{
		def(ssl, i);
		exit (0);
	}
	do 
	{	
		i[0] = flags(argv, i[0], ssl);
		if (ISSAME(*ssl->pqrs, P))
		{
			flagP(ssl, i);
			continue ;
		}
		else if (argv[i[0]] == NULL)
		{
			def(ssl, i);
			break;
		}
		if (((!ISSAME(*ssl->pqrs, P) && !ISSAME(*ssl->pqrs, S) && (argv[i[0]]))) || i[1] == 2)
			def_with_arg(argv, i, ssl);
		if (ISSAME(*ssl->pqrs, S) && i[1] != 2)
			flagS(argv, i, ssl);
		i[0]++;
	} while (argv[i[0]]);
	free (ssl->pqrs);
}
