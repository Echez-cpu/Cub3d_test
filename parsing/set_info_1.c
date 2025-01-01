/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:48:42 by junhhong          #+#    #+#             */
/*   Updated: 2025/01/01 16:49:55 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

// static int	ft_strcmp(const char *s1, const char *s2)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s1[i] != '\0' && s2[i] != '\0')
// 	{
// 		if ((unsigned char)s1[i] != (unsigned char)s2[i])
// 			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
// 		i ++ ;
// 	}
// 	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
// }

static bool	is_folder(char *str)
{
	int		fd;
	bool	result;

	result = false;
	fd = open(str, O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		result = true;
	}
	return (result);
}

static int	extension_check(char *path)
{
	char	*tmp;

	tmp = ft_strrchr(path, '.');
	if (!tmp || strcmp(tmp, ".cub") != 0)
	{
		ft_putstr_fd("Invalid file extension\n", 2);
		return (0);
	}
	return (1);
}

static int	check_xpm(char *path)
{
	char	*tmp;

	tmp = ft_strrchr(path, '.');
	if (!tmp || strcmp(tmp, ".xpm") != 0)
	{
		ft_putstr_fd("Invalid file extension\n", 2);
		return (0);
	}
	return (1);
}

int	set_fd(char *str, bool cub)
{
	int	fd;

	if (is_folder(str))
		is_faulty("this is a directory\n");
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (is_faulty("Cannot read file. fd is -1\n"));
	close(fd);
	if (cub && !extension_check(str))
		return (is_faulty("Not a .cub file\n"));
	if (!cub && !check_xpm(str))
		return (is_faulty("Not an .xpm file\n"));
	return (0);
}
