/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_sha224.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 17:34:41 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/11 17:45:26 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_SHA224_H
# define FT_SSL_SHA224_H
# include "ft_ssl.h"

/*
** sha224.c
*/
void	def224(t_ssl *ssl, int *i);
/*
** value256.c
*/
t_ssl	*val224(t_ssl *ssl);
/*
** printdef.c
*/
void	printfdefwitharg224(t_ssl *ssl, char **argv, int *i);
/*
** printflags.c
*/
void	printflags224(t_ssl *ssl, char **argv, int len, int *i);

#endif
