/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 02:15:36 by okassimi          #+#    #+#             */
/*   Updated: 2023/04/28 18:47:00 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_write_error(char *string)
{
	write(2, "ERROR\n", 6);
	write(2, string, ft_strlen(string));
	exit (1);
}

void	ft_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_free_2ptr(char **map1, char **map2)
{
	ft_free(map1);
	ft_free(map2);
	exit (1);
}

char	**ft_copy_map(char **map, t_elem *elem)
{
	char	**copy_map;

	elem->i = 0;
	elem->j = 0;
	copy_map = ft_calloc(sizeof(char *), (elem->index + 1));
	if (!copy_map)
	{
		ft_free(map);
		exit (1);
	}
	while (elem->i < elem->index)
	{
		copy_map[elem->i] = ft_calloc(sizeof(char), (elem->len + 1));
		if (!copy_map)
			ft_free_2ptr(map, copy_map);
		elem->j = 0;
		while (elem->j < elem->len)
		{
			copy_map[elem->i][elem->j] = map[elem->i][elem->j];
			elem->j++;
		}
		elem->i++;
	}
	return (copy_map);
}

char	**ft_fill_map(int fd, t_elem *elem)
{
	char	**line;

	if (!elem->index)
		ft_write_error("Emty map");
	line = ft_calloc(sizeof(char *), (elem->index + 1));
	if (!line)
		exit(1);
	while (elem->i < elem->index)
	{
		line[elem->i] = get_next_line(fd);
		if (ft_strlen(line[elem->i]) == 0)
			break ;
		elem->i++;
	}
	elem->len = ft_strlen(line[0]);
	return (line);
}
