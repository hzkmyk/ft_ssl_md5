/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_sha384.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:36:50 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/10 18:09:33 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_SHA384_H
# define FT_SSL_SHA384_H
# include "ft_ssl.h"

/*
** sha384.c
*/
void	def384(t_ssl *ssl, int *i);

/*
** print.c
*/
void	printflags384(t_ssl *ssl, char **argv, int len, int *i);

/*
** value512.c
*/
t_ssl	*val384(t_ssl *ssl);

#endif
