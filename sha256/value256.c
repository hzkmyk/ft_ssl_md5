/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value256.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:08:26 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/08 17:56:47 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

const u_int32_t	sha256K[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
	0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
	0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
	0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
	0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

t_ssl	*val256(t_ssl *ssl)
{
	ssl->iv[0] = 0x6a09e667;
	ssl->iv[1] = 0xbb67ae85;
	ssl->iv[2] = 0x3c6ef372;
	ssl->iv[3] = 0xa54ff53a;
	ssl->iv[4] = 0x510e527f;
	ssl->iv[5] = 0x9b05688c;
	ssl->iv[6] = 0x1f83d9ab;
	ssl->iv[7] = 0x5be0cd19;
	ssl->uv[0] = 0x6a09e667;
	ssl->uv[1] = 0xbb67ae85;
	ssl->uv[2] = 0x3c6ef372;
	ssl->uv[3] = 0xa54ff53a;
	ssl->uv[4] = 0x510e527f;
	ssl->uv[5] = 0x9b05688c;
	ssl->uv[6] = 0x1f83d9ab;
	ssl->uv[7] = 0x5be0cd19;
	return (ssl);
}

void    fix256_2(t_ssl *ssl)
{
    ssl->iv[0] += ssl->uv[0];
    ssl->iv[1] += ssl->uv[1];
    ssl->iv[2] += ssl->uv[2];
    ssl->iv[3] += ssl->uv[3];
    ssl->iv[4] += ssl->uv[4];
    ssl->iv[5] += ssl->uv[5];
    ssl->iv[6] += ssl->uv[6];
    ssl->iv[7] += ssl->uv[7];
    ssl->uv[0] = ssl->iv[0];
    ssl->uv[1] = ssl->iv[1];
    ssl->uv[2] = ssl->iv[2];
    ssl->uv[3] = ssl->iv[3];
    ssl->uv[4] = ssl->iv[4];
    ssl->uv[5] = ssl->iv[5];
    ssl->uv[6] = ssl->iv[6];
    ssl->uv[7] = ssl->iv[7];
}

void	fix256(t_ssl *ssl)
{
    int i;
	int j;
	int	tmp[2];

	i = 0;
	while (i < ssl->numBlock)
	{
		j = 0;
		while (j < 64)
		{
			tmp[0] = ssl->iv[7] + s2(ssl) + ch(ssl) + sha256K[j] + ssl->word[i][j];
			tmp[1] = s3(ssl) + maj(ssl);
			ssl->iv[7] = ssl->iv[6];
			ssl->iv[6] = ssl->iv[5];
			ssl->iv[5] = ssl->iv[4];
			ssl->iv[4] = tmp[0] + ssl->iv[3];
			ssl->iv[3] = ssl->iv[2];
			ssl->iv[2] = ssl->iv[1];
			ssl->iv[1] = ssl->iv[0];
			ssl->iv[0] = tmp[0] + tmp[1];
			j++;
		}
		i++;
		fix256_2(ssl);
	}
}