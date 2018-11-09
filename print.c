/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 21:53:27 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/07 22:00:33 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ssl.h"

void    printFlagSSha256(t_ssl *ssl, char **argv, int len, int *i)
{
    if (ISSAME(*ssl->pqrs, Q))
		ft_printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x\n",
        ssl->uv[0], ssl->uv[1], ssl->uv[2], ssl->uv[3],
        ssl->uv[4], ssl->uv[5], ssl->uv[6], ssl->uv[7]);
	else if (ISSAME(*ssl->pqrs, R))
		ft_printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x \"%s\"\n",
        ssl->uv[0], ssl->uv[1], ssl->uv[2], ssl->uv[3], ssl->uv[4],
        ssl->uv[5], ssl->uv[6], ssl->uv[7], argv[i[0]] + (len + 1));
	else
		ft_printf("sha256 (\"%s\") = %.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x\n",
        argv[i[0]] + (len + 1), ssl->uv[0], ssl->uv[1], ssl->uv[2],
        ssl->uv[3], ssl->uv[4], ssl->uv[5], ssl->uv[6], ssl->uv[7]);
}