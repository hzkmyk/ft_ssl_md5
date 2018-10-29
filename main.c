/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:10:15 by hmiyake           #+#    #+#             */
/*   Updated: 2018/10/29 12:37:09 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

t_dsptch	dsptch_table[2] = {
	{"md5", &md5},
	// {"sha256", &sha256},
};

void dsptch(int argc, char **argv)
{
    int i;

    i = 0;
    while (i < 1)
    {
        if (ft_strequ(argv[1], dsptch_table[i].name))
        {
            dsptch_table[i].hash(argc, argv);
            break ;
        }
    }
    return (0);
}

int main(int argc, char **argv)
{
    dsptch(argc, argv);
    return (0);
}