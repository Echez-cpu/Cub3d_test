/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:52:35 by junhhong          #+#    #+#             */
/*   Updated: 2024/12/30 13:51:29 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"



bool	is_non_numeric(char *str)
{
	int		i;
	bool	not_found;

	i = 0;
	not_found = 1;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			not_found = 0;
		i++;
	}
	return (not_found);
}

int	*populate_rgb_array(char **rgb_tokens, int *rgb)
{
	int		i;

	i = -1;
	while (rgb_tokens[++i])
	{
		rgb[i] = ft_atoi(rgb_tokens[i]);
		if (rgb[i] == -1 || is_non_numeric(rgb_tokens[i]) == 1)
		{
			free_things((void **)rgb_tokens);
			free(rgb);
			return (0);
		}
	}
	free_things((void **)rgb_tokens);
	return (rgb);
}




int	set_floor_ceiling_colors(t_texinfo *textures, char *line, int j)
{
	if (line[j + 1] && ft_isprint(line[j + 1]))
		return(is_faulty("invalid floor or celing colours"));
	if (!textures->ceiling && line[j] == 'C')
	{
		textures->ceiling = convert_string_to_rgb(line + j + 1);
		if (textures->ceiling == 0)
			return (is_faulty_3("invalid rgb ceiling colour")); // still here
	}
	else if (!textures->floor && line[j] == 'F')
	{
		textures->floor = convert_string_to_rgb(line + j + 1);
		if (textures->floor == 0)
			return (is_faulty_3("invalid rgb floor colour"));
	}
	else
		return (is_faulty_3("invalid rgb floor and ceiling colour"));
	return (SUCCESS);
}



 int	*convert_string_to_rgb(char *line)
{
	char	**rgb_tokens;
	int		*rgb;
	int		count;

	rgb_tokens = ft_split(line, ',');
	count = 0;
	while (rgb_tokens[count])
		count++;
	if (count != 3)
	{
		free_things((void **)rgb_tokens);
		return (0);
	}
	rgb = malloc(sizeof(int) * 3);
	if (!rgb)
	{
		is_faulty_2("could not allocate memory");
		return(0);
	}
	return (populate_rgb_array(rgb_tokens, rgb));
}

