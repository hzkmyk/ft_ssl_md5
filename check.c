/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 12:44:04 by hmiyake           #+#    #+#             */
/*   Updated: 2018/09/30 14:15:28 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

int	is_directory(char *argv)
{
	struct stat	st;

	if (!lstat(argv, &st))
	{
		if (S_ISDIR(st.st_mode))
			return (1);
	}
	return (0);
}

int	is_file(char *argv)
{
	struct stat	st;

	if (!stat(argv, &st))
	{
		if (S_ISREG(st.st_mode))
			return (1);
	}
	return (0);
}

// int	is_symboliclink(char *argv)
// {
// 	struct stat	st;
// 	char		*name;

// 	name = NULL;
// 	if (!lstat(argv, &st))
// 	{
// 		if (S_ISLNK(st.st_mode))
// 		{
// 			name = strjoin_for_path(argv, "\0", name);
// 			if (is_file(name))
// 				return (free_name_and_return_one(name));
// 			else if (is_directory(name))
// 				return (free_name_and_return_one(name) + 1);
// 			else
// 				return (free_name_and_return_one(name) + 2);
// 		}
// 	}
// 	return (0);
// }