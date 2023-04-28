/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:11:16 by okassimi          #+#    #+#             */
/*   Updated: 2023/04/28 18:36:03 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_search_error(int argc, char **argv, t_elem *elem)
{
	int	ret;

	if (argc != 2)
		ft_write_error("Syntax Error: ./exec_name map");
	if (ft_strlen(argv[1]) <= 4 || ft_memcmp((argv[1] + ft_strlen(argv[1]) - 4),
			".ber", ft_strlen(argv[1] + ft_strlen(argv[1]) - 4))
		|| !ft_memcmp(ft_strrchr(argv[1], '/'), "/.ber",
			ft_strlen(ft_strrchr(argv[1], '/'))))
	{
		ft_write_error("Invalid extention: *****.ber");
	}
	ret = ft_check_map(argv[1], elem);
	if (ret == 1)
		ft_write_error("Problem with Walls");
	else if (ret == 2)
		ft_write_error("Problem with characters");
}

int	ft_check_map(char *arg, t_elem *elem)
{
	int		fd;
	char	**line;
	char	**copy_map;

	ft_count_lines(arg, &elem->index);
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		exit(1);
	line = ft_fill_map(fd, elem);
	if (ft_check_walls(line, elem) == 1)
	{
		ft_free(line);
		return (1);
	}
	if (ft_check_elem(line, elem) == 1)
	{
		ft_free(line);
		return (2);
	}
	copy_map = ft_copy_map(line, elem);
	ft_check_path(line, copy_map, elem->index, elem->len);
	ft_make_window(line, elem);
	return (0);
}

void	ft_count_lines(char *arg, size_t *index)
{
	char	*t;
	int		fd;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		ft_write_error("File not found, check extention");
	t = get_next_line(fd);
	while (t)
	{
		free(t);
		t = get_next_line(fd);
		(*index)++;
		if (t && t[0] == '\n')
			ft_write_error("Extra Newlines");
	}
}

int	ft_check_walls(char **arr, t_elem *elem)
{
	elem->i = 0;
	elem->j = 0;
	if (arr[elem->index - 1][elem->len - 1] == '\n' || ft_strlen(arr[elem->index
			- 1]) >= elem->len)
		return (1);
	while (elem->i < elem->index)
	{
		if (ft_strlen(arr[elem->i]) != elem->len)
			if (arr[elem->i] != arr[elem->index - 1])
				return (1);
		elem->i++;
	}
	elem->i = 0;
	elem->j = 0;
	while (elem->j < elem->len - 1 || elem->i < elem->index)
	{
		if (((elem->j < elem->len - 1) && (arr[0][elem->j] != '1'
				|| arr[elem->index - 1][elem->j] != '1'))
				|| ((elem->i < elem->index) && (arr[elem->i][0] != '1'
					|| arr[elem->i][elem->len - 2] != '1')))
			return (1);
		elem->i++;
		elem->j++;
	}
	return (0);
}
//1 : /*check horizontal walls*/
//2 : /*check vertical walls*/

int	ft_check_elem(char **arr, t_elem *elem)
{
	elem->i = 0;
	elem->j = 0;
	while (elem->i < (elem->index - 1))
	{
		while (elem->j < (elem->len - 1))
		{
			if (arr[elem->i][elem->j] == 'C')
				elem->collec++;
			else if (arr[elem->i][elem->j] == 'P')
				elem->player++;
			else if (arr[elem->i][elem->j] == 'E')
				elem->exit++;
			else if (arr[elem->i][elem->j] != '1'
					&& arr[elem->i][elem->j] != '0')
				return (1);
			elem->j++;
		}
		elem->j = 0;
		elem->i++;
	}
	if (elem->collec < 1 || elem->exit != 1 || elem->player != 1)
		return (1);
	return (0);
}
