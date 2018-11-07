/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fduintdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:59:06 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/06 21:59:08 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_fduintdel(u_int32_t ***ap)
{
    int i;
    u_int32_t **tmp;

    i = 0;
    tmp = *ap;
    if (tmp && *tmp)
    {
        while(tmp[i])
            ft_uintdel(&tmp[i]);
        free(tmp);
        tmp = NULL;
    }
}