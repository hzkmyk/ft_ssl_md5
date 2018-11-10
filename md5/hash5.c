/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 17:31:16 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/09 17:38:01 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

const int	rot[64] = {
	7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
	5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
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

void		round_4(u_int32_t *iv, const int *rot, const int *k, u_int32_t *nay)
{
	int			j;
	u_int32_t	tmp;

	j = 48;
	while (j < 64)
	{
		tmp = iv[0] + i(iv) + nay[(j * 7) % 16] + k[j];
		tmp = LEFTROTATE(rot[j], tmp);
		iv[0] = (iv[1] + tmp);
		switch_iv(iv);
		j++;
	}
}

void		round_3(u_int32_t *iv, const int *rot, const int *k, u_int32_t *nay)
{
	int			i;
	u_int32_t	tmp;

	i = 32;
	while (i < 48)
	{
		tmp = iv[0] + h(iv) + nay[((i * 3) + 5) % 16] + k[i];
		tmp = LEFTROTATE(rot[i], tmp);
		iv[0] = (iv[1] + tmp);
		switch_iv(iv);
		i++;
	}
}

void		round_2(u_int32_t *iv, const int *rot, const int *k, u_int32_t *nay)
{
	int			i;
	u_int32_t	tmp;

	i = 16;
	while (i < 32)
	{
		tmp = iv[0] + g(iv) + nay[((i * 5) + 1) % 16] + k[i];
		tmp = LEFTROTATE(rot[i], tmp);
		iv[0] = (iv[1] + tmp);
		switch_iv(iv);
		i++;
	}
}

void		rounds(u_int32_t *iv, const int *rot, const int *k, u_int32_t *nay)
{
	int			i;
	u_int32_t	tmp;

	i = 0;
	while (i < 16)
	{
		tmp = iv[0] + f(iv) + nay[i] + k[i];
		tmp = LEFTROTATE(rot[i], tmp);
		iv[0] = (iv[1] + tmp);
		switch_iv(iv);
		i++;
	}
	round_2(iv, rot, k, nay);
	round_3(iv, rot, k, nay);
	round_4(iv, rot, k, nay);
}

void		rounds_and_fix(t_ssl *ssl)
{
	int	i;

	i = 0;
	while (i < (ssl->numBlock))
	{
		rounds(ssl->iv, rot, k, ssl->word[i]);
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
