/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 21:53:27 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/10 19:45:45 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ssl.h"

void	printflags5(t_ssl *ssl, char **argv, int len, int *i)
{
	if (ISSAME(*ssl->pqrs, Q))
		ft_printf("%.8x%.8x%.8x%.8x\n",
		ssl->iv[0], ssl->iv[1], ssl->iv[2], ssl->iv[3]);
	else if (ISSAME(*ssl->pqrs, R))
		ft_printf("%.8x%.8x%.8x%.8x \"%s\"\n",
		ssl->iv[0], ssl->iv[1], ssl->iv[2], ssl->iv[3], argv[i[0]] + (len + 1));
	else
		ft_printf("MD5 (\"%s\") = %.8x%.8x%.8x%.8x\n",
		argv[i[0]] + (len + 1), ssl->iv[0], ssl->iv[1], ssl->iv[2], ssl->iv[3]);
}

void	printflags256(t_ssl *ssl, char **argv, int len, int *i)
{
	if (ISSAME(*ssl->pqrs, Q))
		ft_printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x\n",
		ssl->uv[0], ssl->uv[1], ssl->uv[2], ssl->uv[3],
		ssl->uv[4], ssl->uv[5], ssl->uv[6], ssl->uv[7]);
	else if (ISSAME(*ssl->pqrs, R))
		ft_printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x \"%s\"\n",
		ssl->uv[0], ssl->uv[1], ssl->uv[2], ssl->uv[3], ssl->uv[4],
		ssl->uv[5], ssl->uv[6], ssl->uv[7], argv[i[0]] + (len + 1));
	else
		ft_printf("sha256 (\"%s\") = %.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x\n",
		argv[i[0]] + (len + 1), ssl->uv[0], ssl->uv[1], ssl->uv[2],
		ssl->uv[3], ssl->uv[4], ssl->uv[5], ssl->uv[6], ssl->uv[7]);
}

void	printflags512(t_ssl *ssl, char **argv, int len, int *i)
{
	if (ISSAME(*ssl->pqrs, Q))
		ft_printf("%.16llx%.16llx%.16llx%.16llx%.16llx%.16llx%.16llx%.16llx\n",
		ssl->uv512[0], ssl->uv512[1], ssl->uv512[2], ssl->uv512[3],
		ssl->uv512[4], ssl->uv512[5], ssl->uv512[6], ssl->uv512[7]);
	else if (ISSAME(*ssl->pqrs, R))
		ft_printf("%.16llx%.16llx%.16llx%.16llx%.16llx%.16llx%.16llx%.16llx \"%s\"\n",
		ssl->uv512[0], ssl->uv512[1], ssl->uv512[2], ssl->uv512[3], ssl->uv512[4],
		ssl->uv512[5], ssl->uv512[6], ssl->uv512[7], argv[i[0]] + (len + 1));
	else
		ft_printf("sha512 (\"%s\") = %.16llx%.16llx%.16llx%.16llx%.16llx%.16llx%.16llx%.16llx\n",
		argv[i[0]] + (len + 1), ssl->uv512[0], ssl->uv512[1], ssl->uv512[2],
		ssl->uv512[3], ssl->uv512[4], ssl->uv512[5], ssl->uv512[6], ssl->uv512[7]);
}

void	printflags384(t_ssl *ssl, char **argv, int len, int *i)
{
	if (ISSAME(*ssl->pqrs, Q))
		ft_printf("%.16llx%.16llx%.16llx%.16llx%.16llx%.16llx\n",
		ssl->uv512[0], ssl->uv512[1], ssl->uv512[2], ssl->uv512[3],
		ssl->uv512[4], ssl->uv512[5]);
	else if (ISSAME(*ssl->pqrs, R))
		ft_printf("%.16llx%.16llx%.16llx%.16llx%.16llx%.16llx \"%s\"\n",
		ssl->uv512[0], ssl->uv512[1], ssl->uv512[2], ssl->uv512[3], ssl->uv512[4],
		ssl->uv512[5], argv[i[0]] + (len + 1));
	else
		ft_printf("sha512 (\"%s\") = %.16llx%.16llx%.16llx%.16llx%.16llx%.16llx\n",
		argv[i[0]] + (len + 1), ssl->uv512[0], ssl->uv512[1], ssl->uv512[2],
		ssl->uv512[3], ssl->uv512[4], ssl->uv512[5]);
}

void	printdefwitharg(t_ssl *ssl, char **argv, int *i)
{
	if (ISSAME(*ssl->pqrs, Q))
		ft_printf("%.8x%.8x%.8x%.8x\n",
		ssl->iv[0], ssl->iv[1], ssl->iv[2], ssl->iv[3]);
	else if (ISSAME(*ssl->pqrs, R))
		ft_printf("%.8x%.8x%.8x%.8x %s\n",
		ssl->iv[0], ssl->iv[1], ssl->iv[2], ssl->iv[3], argv[i[0]]);
	else
		ft_printf("MD5 (%s) = %.8x%.8x%.8x%.8x\n",
		argv[i[0]], ssl->iv[0], ssl->iv[1], ssl->iv[2], ssl->iv[3]);
}