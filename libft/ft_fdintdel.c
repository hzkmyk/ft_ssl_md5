/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdintdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:58:40 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/11 14:43:43 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/ft_ssl.h"

void	ft_fdintdel(int ***ap, t_ssl *ssl)
{
	int	i;
	int	**tmp;

	i = 0;
	tmp = *ap;
	if (tmp && *tmp)
	{
		while (i < ssl->numblock)
		{
			ft_intdel(&tmp[i]);
			i++;
		}
		free(tmp);
		tmp = NULL;
	}
}
