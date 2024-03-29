/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:51:55 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/11 15:52:08 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

u_int32_t	f(u_int32_t *iv)
{
	return ((iv[1] & iv[2]) | (~iv[1] & iv[3]));
}

u_int32_t	g(u_int32_t *iv)
{
	return ((iv[1] & iv[3]) | (iv[2] & ~iv[3]));
}

u_int32_t	h(u_int32_t *iv)
{
	return (iv[1] ^ iv[2] ^ iv[3]);
}

u_int32_t	i(u_int32_t *iv)
{
	return (iv[2] ^ (iv[1] | ~iv[3]));
}
