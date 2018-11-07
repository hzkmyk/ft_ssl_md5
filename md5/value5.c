/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 21:48:48 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/04 17:41:57 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	switch_iv(u_int32_t *iv)
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
