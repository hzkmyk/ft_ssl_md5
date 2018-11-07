/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdintdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:58:40 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/06 21:58:44 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_fdintdel(int ***ap)
{
    int i;
    int **tmp;

    i = 0;
    tmp = *ap;
    if (tmp && *tmp)
    {
        while(tmp[i])
            ft_intdel(&tmp[i]);
        free(tmp);
        tmp = NULL;
    }
}