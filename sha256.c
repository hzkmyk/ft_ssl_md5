/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:13:00 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/03 15:37:18 by hmiyake          ###   ########.fr       */
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

t_ssl	*sha256InVal(t_ssl *ssl)
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


void	sha256Fix(t_ssl *ssl)
{
    int i;
	int j;
	int	tmp1;
	int tmp2;

	i = 0;
	while (i < ssl->numBlock)
	{
		j = 0;
		while (j < 64)
		{
			tmp1 = ssl->iv[7] + s2(ssl) + ch(ssl) + sha256K[j] + ssl->word[i][j];
			tmp2 = s3(ssl) + maj(ssl);
			ssl->iv[7] = ssl->iv[6];
			ssl->iv[6] = ssl->iv[5];
			ssl->iv[5] = ssl->iv[4];
			ssl->iv[4] = tmp1 + ssl->iv[3];
			ssl->iv[3] = ssl->iv[2];
			ssl->iv[2] = ssl->iv[1];
			ssl->iv[1] = ssl->iv[0];
			ssl->iv[0] = tmp1 + tmp2;
			j++;
		}
		i++;
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
}

void	sha256Def(t_ssl *ssl, int *i)
{
	char		buff[1024];
	char		*input;
	int			readsize;
	char		*tmp;

	sha256InVal(ssl);
	i[1] = disableS(i[1]);
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
	ssl->block = sha256Padding(input, ssl);
	ssl->word = sha256Words(ssl);
	sha256Fix(ssl);
	ft_strdel(&input);
	ft_fdintdel(&ssl->block);
	ft_fduintdel(&ssl->word);
	ft_printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x\n", ssl->uv[0], ssl->uv[1], ssl->uv[2], ssl->uv[3], ssl->uv[4], ssl->uv[5], ssl->uv[6], ssl->uv[7]);
}

void	flagP256(t_ssl *ssl, int *i)
{
	sha256Def(ssl, i);
	*ssl->pqrs = *ssl->pqrs & 7;
}

void	def_with_arg256(char **argv, int *i, t_ssl *ssl)
{
	char		*file;

	sha256InVal(ssl);
	i[1] = disableS(i[1]);
	if (is_file(argv[i[0]]))
	{
		file = save_line(argv, i[0]);
		ssl->block = sha256Padding(file, ssl);
		ssl->word = sha256Words(ssl);
		sha256Fix(ssl);
		ft_strdel(&file);
		ft_fdintdel(&ssl->block);
		ft_fduintdel(&ssl->word);
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

void		flagS256(char **argv, int *i, t_ssl *ssl)
{
	int			len;

	sha256InVal(ssl);
	if ((len = ft_strchr_i(argv[i[0]], 's')) > 0 && argv[i[0]][len + 1])
		ssl->block = sha256Padding(argv[i[0]] + (len + 1), ssl);
	else
	{
		len = -1;
		if (argv[i[0] + 1])
		{
			i++;
			ssl->block = sha256Padding(argv[i[0]], ssl);;
		}
		else
		{
			ft_printf("sha256: option requires an argument -- s\nusage: sha256 [-pqrtx] [-s string] [files ...]\n");
			exit (1);
		}
	}
	ssl->word = sha256Words(ssl);
	sha256Fix(ssl);
	if (ISSAME(*ssl->pqrs, Q))
		ft_printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x\n", ssl->uv[0], ssl->uv[1], ssl->uv[2], ssl->uv[3], ssl->uv[4], ssl->uv[5], ssl->uv[6], ssl->uv[7]);
	else if (ISSAME(*ssl->pqrs, R))
		ft_printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x \"%s\"\n", ssl->uv[0], ssl->uv[1], ssl->uv[2], ssl->uv[3], ssl->uv[4], ssl->uv[5], ssl->uv[6], ssl->uv[7], argv[i[0]] + (len + 1));
	else
		ft_printf("sha256 (\"%s\") = %.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x\n", argv[i[0]] + (len + 1), ssl->uv[0], ssl->uv[1], ssl->uv[2], ssl->uv[3], ssl->uv[4], ssl->uv[5], ssl->uv[6], ssl->uv[7]);
	i[1] = 1;
}

void    	sha256(int argc, char **argv)
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
		sha256Def(ssl, i);
		exit (0);
	}
	do 
	{	
		i[0] = flags(argv, i[0], ssl);
		if (ISSAME(*ssl->pqrs, P))
		{
			flagP256(ssl, i);
			continue ;
		}
		else if (argv[i[0]] == NULL)
		{
			sha256Def(ssl, i);
			break;
		}
		if (((!ISSAME(*ssl->pqrs, P) && !ISSAME(*ssl->pqrs, S) && (argv[i[0]]))) || i[1] == 2)
			def_with_arg256(argv, i, ssl);
		if (ISSAME(*ssl->pqrs, S) && i[1] != 2)
			flagS256(argv, i, ssl);
		i[0]++;
	} while (argv[i[0]]);
	free (ssl->pqrs);
}