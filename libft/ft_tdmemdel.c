/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tdmemdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:59:45 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/06 21:59:46 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_tdmemdel(void ***ap)
{
    int i;
    void **tmp;

    i = 0;
    tmp = *ap;
    if (tmp && *tmp)
    {
        while(tmp[i])
            ft_memdel(&tmp[i]);
        free(tmp);
        tmp = NULL;
    }
}