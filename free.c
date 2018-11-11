/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 13:57:08 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/11 14:23:18 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ssl.h"

void	freethings(t_ssl *ssl)
{
	free(ssl->pqrs);
	free(ssl);
}

void	free64(t_ssl *ssl, char *input)
{
	ft_strdel(&input);
	ft_fdu64intdel(&ssl->block512, ssl);
	ft_fdu64intdel(&ssl->word512, ssl);
}
