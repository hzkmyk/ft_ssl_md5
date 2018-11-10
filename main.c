/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:10:15 by hmiyake           #+#    #+#             */
/*   Updated: 2018/11/09 15:33:25 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ssl.h"

t_dsptch	dsptch_table[4] = {
	{"md5", &md5},
	{"sha256", &sha256},
    {"sha512", &sha512},
    {"sha384", &sha384},
};

void dsptch(int argc, char **argv)
{
    int i;

    i = 0;
    while (i < 4)
    {
        if (ft_strequ(argv[1], dsptch_table[i].name))
        {
            dsptch_table[i].hash(argc, argv);
            return ;
        }
        i++;
    }
    ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n", argv[1]);
    ft_printf("Standard commands:\n\n");
    ft_printf("Message Digest commands:\nmd5\nsha256\n\n");
    ft_printf("Cipher commands:\n");
    exit (1);
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        ft_printf("usage: ft_ssl command [command opts] [command args]\n");
        exit(1);
    }
    dsptch(argc, argv);
    return (0);
}