/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 21:48:48 by hmiyake           #+#    #+#             */
/*   Updated: 2018/09/28 11:23:01 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

void	switch_iv(int *iv)
{
	int	tmp0;
	int	tmp1;
	int	tmp2;
	int	tmp3;

	tmp0 = iv[0];
	tmp1 = iv[1];
	tmp2 = iv[2];
	tmp3 = iv[3];
	
	iv[1] = tmp0;
	iv[2] = tmp1;
	iv[3] = tmp2;
	iv[0] = tmp3;
}

void	round_1(int *iv, const int *rot, const int *k, u_int32_t *nay)
{
	int			i;
	u_int32_t	tmp;

	i = 0;
	while (i < 16)
	{
		tmp = iv[0] + f(iv) + nay[i] + k[i];
		tmp = rotate(rot[i], tmp);
		iv[0] =(iv[1] + tmp);
		switch_iv(iv);
		i++;
	}
}

void	round_2(int *iv, const int *rot, const int *k, u_int32_t *nay)
{
	int			i;
	u_int32_t	tmp;

	i = 16;
	while (i < 32)
	{
		tmp = iv[0] + g(iv) + nay[((i * 5) + 1) % 16] + k[i];
		tmp = rotate(rot[i], tmp);
		iv[0] =(iv[1] + tmp);
		switch_iv(iv);
		i++;
	}
}

void	round_3(int *iv, const int *rot, const int *k, u_int32_t *nay)
{
	int			i;
	u_int32_t	tmp;

	i = 32;
	while (i < 48)
	{
		tmp = iv[0] + h(iv) + nay[((i * 3) + 5) % 16] + k[i];
		tmp = rotate(rot[i], tmp);
		iv[0] =(iv[1] + tmp);
		switch_iv(iv);
		i++;
	}
}

void	round_4(int *iv, const int *rot, const int *k, u_int32_t *nay)
{
	int			j;
	u_int32_t	tmp;

	j = 48;
	while (j < 64)
	{
		tmp = iv[0] + i(iv) + nay[(j * 7) % 16] + k[j];
		tmp = rotate(rot[j], tmp);
		iv[0] =(iv[1] + tmp);
		switch_iv(iv);
		j++;
	}
}