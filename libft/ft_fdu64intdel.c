/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdu64intdel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:42:43 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/10 18:47:05 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/ft_ssl.h"

void	ft_fdu64intdel(u_int64_t ***ap, t_ssl *ssl)
{
	int			i;
	u_int64_t	**tmp;

	i = 0;
	tmp = *ap;
	if (tmp && *tmp)
	{
		while (i < ssl->numBlock)
		{
			ft_u64intdel(&tmp[i]);
			i++;
		}
		free(tmp);
		tmp = NULL;
	}
}
