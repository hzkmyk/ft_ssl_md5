/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:13:00 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/01 23:25:21 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

const int	sha256K[64] = {
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

t_initial	*md5InVal(t_initial *in)
{
	in->iv[0] = 0x6a09e667;
	in->iv[1] = 0xbb67ae85;
	in->iv[2] = 0x3c6ef372;
	in->iv[3] = 0xa54ff53a;
	in->iv[4] = 0x510e527f;
	in->iv[5] = 0x9b05688c;
	in->iv[6] = 0x1f83d9ab;
	in->iv[7] = 0x5be0cd19;
	in->uv[0] = 0x6a09e667;
	in->uv[1] = 0xbb67ae85;
	in->uv[2] = 0x3c6ef372;
	in->uv[3] = 0xa54ff53a;
	in->uv[4] = 0x510e527f;
	in->uv[5] = 0x9b05688c;
	in->uv[6] = 0x1f83d9ab;
	in->uv[7] = 0x5be0cd19;
	return (in);
}


t_initial	*sha256Fix(t_initial *in, u_int32_t **nay, int *block)
{
    int i;
	int j;
	int	tmp1;
	int tmp2;

	i = 0;
	while (i < block[0])
	{
		j = 0;
		while (j < 64)
		{
			tmp1 = in->iv[7] + s2(in) + ch(in) + sha256K[j] + nay[i][j];
			tmp2 = s3(in) + maj(in);
			in->iv[7] = in->iv[6];
			in->iv[6] = in->iv[5];
			in->iv[5] = in->iv[4];
			in->iv[4] = tmp1 + in->iv[3];
			in->iv[3] = in->iv[2];
			in->iv[2] = in->iv[1];
			in->iv[1] = in->iv[0];
			in->iv[0] = tmp1 + tmp2;
			j++;
		}
		i++;
		in->iv[0] += in->uv[0];
		in->iv[1] += in->uv[1];
		in->iv[2] += in->uv[2];
		in->iv[3] += in->uv[3];
		in->iv[4] += in->uv[4];
		in->iv[5] += in->uv[5];
		in->iv[6] += in->uv[6];
		in->iv[7] += in->uv[7];
		in->uv[0] = in->iv[0];
		in->uv[1] = in->iv[1];
		in->uv[2] = in->iv[2];
		in->uv[3] = in->iv[3];
		in->uv[4] = in->iv[4];
		in->uv[5] = in->iv[5];
		in->uv[6] = in->iv[6];
		in->uv[7] = in->iv[7];
	}
	return (in);
}

void    	sha256(int argc, char **argv)
{
    int			**yay;
	u_int32_t	**nay;
	t_initial	*in;
	int			block[1];
    
    if (argc || argv)
	;
	block[0] = 0;
	in = (t_initial *)malloc(sizeof(t_initial));
	in = md5InVal(in);
	yay = sha256Padding("hello", block);
	nay = sha256Words(yay, block);
	sha256Fix(in, nay, block);
	ft_printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x\n", in->uv[0], in->uv[1], in->uv[2], in->uv[3], in->uv[4], in->uv[5], in->uv[6], in->uv[7]);
}