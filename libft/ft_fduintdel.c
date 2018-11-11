/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fduintdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:59:06 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/10 18:47:25 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/ft_ssl.h"

void	ft_fduintdel(u_int32_t ***ap, t_ssl *ssl)
{
	int			i;
	u_int32_t	**tmp;

	i = 0;
	tmp = *ap;
	if (tmp && *tmp)
	{
		while (i < ssl->numBlock)
		{
			ft_uintdel(&tmp[i]);
			i++;
		}
		free(tmp);
		tmp = NULL;
	}
}
