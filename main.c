/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 12:46:30 by hmiyake           #+#    #+#             */
/*   Updated: 2018/09/30 22:36:30 by hmiyake          ###   ########.fr       */
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

int			iv[4] = {
	0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476
};

int			uv[4] = {
	0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476
};

void		rounds_and_fix(int *blocks, u_int32_t **nay)
{
	int	i;

	i = 0;
	while (i < blocks[0])
	{
		round_1(iv, rot, k, nay[i]);
		round_2(iv, rot, k, nay[i]);
		round_3(iv, rot, k, nay[i]);
		round_4(iv, rot, k, nay[i]);
		iv[0] += uv[0];
		iv[1] += uv[1];
		iv[2] += uv[2];
		iv[3] += uv[3];
		uv[0] = iv[0];
		uv[1] = iv[1];
		uv[2] = iv[2];
		uv[3] = iv[3];
		i++;
	}
	fix_value(iv);
}

int			main(int argc, char **argv)
{
	int			blocks[1];
	int			**yay;
	u_int32_t	**nay;
	int			i;
	int			pqrs[4];
	// char		*file;
	// char		**line;
	char		*str;

	blocks[0] = 0;
	if (argc < 2)
		;
	if (argv)
		;
	i = flags(argv, pqrs);
	while (argv[i])
	{
		printf("%d\n", pqrs[3]);
		if (pqrs[3])
		{
			printf("here?\n");
			str = flag_s(argv);
			yay = padding(str, blocks);
			nay = words(yay, blocks);
			rounds_and_fix(blocks, nay);
			ft_printf("MD5 (%s) = %.8x%.8x%.8x%.8x\n", argv[i], iv[0], iv[1], iv[2], iv[3]);
		}
		// if (!pqrs[3])
		// {
		// 	if (is_file(argv[i]))
		// 	{
		// 		line = (char **)malloc(sizeof(char *));
		// 		file = save_line(argv);
		// 		yay = padding(file, blocks);
		// 		nay = words(yay, blocks);
		// 		rounds_and_fix(blocks, nay);
		// 		ft_printf("MD5 (%s) = %.8x%.8x%.8x%.8x\n", argv[i], iv[0], iv[1], iv[2], iv[3]);
		// 	}
		// 	else if (is_directory(argv[i]))
		// 		ft_printf("md5: %s: Is a directory\n", argv[i]);
		// 	else
		// 		perror("EROOR");
		// 	i++;
		// 	continue ;
		// }
		// yay = padding(argv[i], blocks);
		// nay = words(yay, blocks);
		// rounds_and_fix(blocks, nay);
		// ft_printf("MD5 (\"%s\") = %.8x%.8x%.8x%.8x\n", argv[i], iv[0], iv[1], iv[2], iv[3]);
		i++;
	}
	return (0);
}