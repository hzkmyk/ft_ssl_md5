/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 12:46:30 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/01 22:52:21 by hmiyake          ###   ########.fr       */
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

t_initial	*initializeIvUv(t_initial *in)
{
	in->iv[0] = 0x67452301;
	in->iv[1] = 0xefcdab89;
	in->iv[2] = 0x98badcfe;
	in->iv[3] = 0x10325476;
	in->uv[0] = 0x67452301;
	in->uv[1] = 0xefcdab89;
	in->uv[2] = 0x98badcfe;
	in->uv[3] = 0x10325476;
	return (in);
}

void		rounds_and_fix(int *blocks, u_int32_t **nay, t_initial *in)
{
	int	i;

	i = 0;
	while (i < blocks[0])
	{
		round_1(in->iv, rot, k, nay[i]);
		round_2(in->iv, rot, k, nay[i]);
		round_3(in->iv, rot, k, nay[i]);
		round_4(in->iv, rot, k, nay[i]);
		in->iv[0] += in->uv[0];
		in->iv[1] += in->uv[1];
		in->iv[2] += in->uv[2];
		in->iv[3] += in->uv[3];
		in->uv[0] = in->iv[0];
		in->uv[1] = in->iv[1];
		in->uv[2] = in->iv[2];
		in->uv[3] = in->iv[3];
		i++;
	}
	fix_value(in->iv);
}

void	def(int *pqrs, int **yay, u_int32_t **nay, t_initial *in)
{
	char		buff[1024];
	char		*input;
	int			readsize;
	char		*tmp;
	int			blocks[1];

	blocks[0] = 0;
	input = ft_strnew(0);
	while ((readsize = read(0, buff, 1024)))
	{
		buff[readsize] = '\0';
		tmp = ft_strjoin(input, buff);
		ft_strdel(&input);
		input = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	if (ISSAME(*pqrs, P))
		ft_printf("%s", input);
	yay = padding(input, blocks);
	nay = words(yay, blocks);
	rounds_and_fix(blocks, nay, in);
	ft_strdel(&input);
	ft_fdintdel(&yay);
	ft_fduintdel(&nay);
	ft_printf("%.8x%.8x%.8x%.8x\n", in->iv[0], in->iv[1], in->iv[2], in->iv[3]);
}


void	flagP(int *pqrs, int **yay, u_int32_t **nay, t_initial *in)
{
	def(pqrs, yay, nay, in);
	*pqrs = *pqrs & 7;
}

void	def_with_arg(char **argv, int i, int *pqrs, t_initial *in)
{
	int			**yay;
	u_int32_t	**nay;
	char		*file;
	int			blocks[1];
	
	blocks[0] = 0;
	if (is_file(argv[i]))
	{
		file = save_line(argv, i);
		yay = padding(file, blocks);
		nay = words(yay, blocks);
		rounds_and_fix(blocks, nay, in);
		ft_strdel(&file);
		ft_fdintdel(&yay);
		ft_fduintdel(&nay);
		if (ISSAME(*pqrs, Q))
			ft_printf("%.8x%.8x%.8x%.8x\n", in->iv[0], in->iv[1], in->iv[2], in->iv[3]);
		else if (ISSAME(*pqrs, R))
			ft_printf("%.8x%.8x%.8x%.8x %s\n", in->iv[0], in->iv[1], in->iv[2], in->iv[3], argv[i]);
		else
			ft_printf("MD5 (%s) = %.8x%.8x%.8x%.8x\n", argv[i], in->iv[0], in->iv[1], in->iv[2], in->iv[3]);
	}
	else if (is_directory(argv[i]))
		ft_printf("md5: %s: Is a directory\n", argv[i]);
	else
		ft_printf("ft_ssl: md5: %s: %s\n", argv[i], strerror(errno));
}

int		flagS(char **argv, int i, int *pqrs, t_initial *in)
{
	int			len;
	int			**yay;
	u_int32_t	**nay;
	int			blocks[1];
	
	blocks[0] = 0;
	if ((len = ft_strchr_i(argv[i], 's')) > 0 && argv[i][len + 1])
		yay = padding(argv[i] + (len + 1), blocks);
	else
	{
		len = -1;
		if (argv[i + 1])
		{
			i++;
			yay = padding(argv[i], blocks);
		}
		else
		{
			ft_printf("md5: option requires an argument -- s\nusage: md5 [-pqrtx] [-s string] [files ...]\n");
			exit (1);
		}
	}
	nay = words(yay, blocks);
	rounds_and_fix(blocks, nay, in);
	if (ISSAME(*pqrs, Q))
		ft_printf("%.8x%.8x%.8x%.8x\n", in->iv[0], in->iv[1], in->iv[2], in->iv[3]);
	else if (ISSAME(*pqrs, R))
		ft_printf("%.8x%.8x%.8x%.8x \"%s\"\n", in->iv[0], in->iv[1], in->iv[2], in->iv[3], argv[i] + (len + 1));
	else
		ft_printf("MD5 (\"%s\") = %.8x%.8x%.8x%.8x\n", argv[i] + (len + 1), in->iv[0], in->iv[1], in->iv[2], in->iv[3]);
	return (i);
}

void			md5(int argc, char **argv)
{
	int			**yay;
	u_int32_t	**nay;
	int			i;
	int			*pqrs;
	t_initial	*in;
	int			aaa;

	in = (t_initial *)malloc(sizeof(t_initial));
	initializeIvUv(in);
	yay = NULL;
	nay = NULL;
	pqrs = (int *)malloc(sizeof(int));
	*pqrs = 0;
	aaa = 0;
	i = 2;
	if (argc == 2)
	{
		def(pqrs, yay, nay, in);
		exit (0);
	}
	do 
	{	
		i = flags(argv, pqrs, i, in);
		if (ISSAME(*pqrs, P))
		{
			if (aaa == 1)
				aaa = 2;
			initializeIvUv(in);
			flagP(pqrs, yay, nay, in);
			continue ;
		}
		else if (argv[i] == NULL)
		{
			if (aaa == 1)
				aaa = 2;
			def(pqrs, yay, nay, in);
			break;
		}
		if (((!ISSAME(*pqrs, P) && !ISSAME(*pqrs, S) && (argv[i]))) || aaa == 2)
		{
			if (aaa == 1)
				aaa = 2;
			initializeIvUv(in);
			def_with_arg(argv, i, pqrs, in);
		}
		if (ISSAME(*pqrs, S) && aaa != 2)
		{
			initializeIvUv(in);
			i = flagS(argv, i, pqrs, in);
			aaa = 1;
		}
		i++;
	} while (argv[i]);
	free (pqrs);
}
