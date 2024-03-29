/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tdstrdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 18:10:53 by syamada           #+#    #+#             */
/*   Updated: 2018/11/10 17:40:47 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tdstrdel(char ***tdstr)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = *tdstr;
	if (tmp && *tmp)
	{
		while (tmp[i])
			ft_strdel(&tmp[i++]);
		free(tmp);
		tmp = NULL;
	}
}
