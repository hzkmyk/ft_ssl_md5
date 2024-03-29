/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_sha384.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:36:50 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/11 14:27:02 by hmiyake          ###   ########.fr       */
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
** printdef.c && printflags.c
*/
void	printdefwitharg384(t_ssl *ssl, char **argv, int *i);
void	printflags384(t_ssl *ssl, char **argv, int len, int *i);

/*
** value512.c
*/
t_ssl	*val384(t_ssl *ssl);

#endif
