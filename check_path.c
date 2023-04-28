/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:17:26 by okassimi          #+#    #+#             */
/*   Updated: 2023/04/28 18:46:21 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_write_this_error(char *string, char **map, char **copy_map)
{
	write(2, "ERROR\n", 6);
	write(2, string, ft_strlen(string));
	ft_free_2ptr(map, copy_map);
}

int	ft_seach_elem(char **map, int height, int width, int k)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
			if (k == 0 || map[j][i] == 'C')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

void	floodfill(char **map, int i, int j, int *a)
{
	if (map[j][i] == '1' || map[j][i] == 'H' || map[j][i] == 'E')
	{
		if (map[j][i] == 'E')
			*a = 1;
		return ;
	}
	map[j][i] = 'H';
	floodfill(map, i + 1, j, a);
	floodfill(map, i - 1, j, a);
	floodfill(map, i, j + 1, a);
	floodfill(map, i, j - 1, a);
}

void	ft_check_path(char **map, char **copy_map, int height, int width)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
			if (copy_map[j][i] == 'P')
			{
				floodfill(copy_map, i, j, &k);
				if (ft_seach_elem(copy_map, height, width, k) == 1)
					ft_write_this_error("Movement error: check accessibility.",
						map, copy_map);
				ft_free(copy_map);
				return ;
			}
			i++;
		}
		j++;
	}
}
