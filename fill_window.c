/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:53:06 by okassimi          #+#    #+#             */
/*   Updated: 2023/04/27 15:48:53 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_xpm_path(void *img)
{
	if (!img)
		ft_write_error("Invalid image");
	return ;
}

void	ft_file_to_map1(t_img *img)
{
	img->floor = mlx_xpm_file_to_image(img->ptr, "textures/floor.xpm", &img->a,
			&img->b);
	ft_check_xpm_path(img->floor);
	img->wall = mlx_xpm_file_to_image(img->ptr, "textures/wall.xpm", &img->a,
			&img->b);
	ft_check_xpm_path(img->wall);
	img->col = mlx_xpm_file_to_image(img->ptr, "textures/collect.xpm", &img->a,
			&img->b);
	ft_check_xpm_path(img->col);
	img->cdoor = mlx_xpm_file_to_image(img->ptr, "textures/Cdoor.xpm", &img->a,
			&img->b);
	ft_check_xpm_path(img->cdoor);
}

void	ft_file_to_map(t_img *img)
{
	ft_file_to_map1(img);
	img->odoor = mlx_xpm_file_to_image(img->ptr, "textures/Odoor.xpm", &img->a,
			&img->b);
	ft_check_xpm_path(img->odoor);
	img->front = mlx_xpm_file_to_image(img->ptr, "textures/front.xpm", &img->a,
			&img->b);
	ft_check_xpm_path(img->front);
	img->back = mlx_xpm_file_to_image(img->ptr, "textures/back.xpm", &img->a,
			&img->b);
	ft_check_xpm_path(img->back);
	img->left = mlx_xpm_file_to_image(img->ptr, "textures/left.xpm", &img->a,
			&img->b);
	ft_check_xpm_path(img->left);
	img->right = mlx_xpm_file_to_image(img->ptr, "textures/right.xpm", &img->a,
			&img->b);
	ft_check_xpm_path(img->right);
}

void	ft_make_window(char **map, t_elem *elem)
{
	t_img	img;

	ft_bzero(elem, 16);
	ft_bzero(&img, 132);
	elem->i_dim = elem->i;
	elem->j_dim = elem->j;
	img.ptr = mlx_init();
	if (!img.ptr)
	{
		ft_free(map);
		exit (1);
	}
	ft_file_to_map(&img);
	img.winptr = mlx_new_window(img.ptr, img.a * (elem->len - 1), img.b
			* (elem->index), "so_long");
	ft_fill_window(map, elem, &img);
	img.mapp = map;
	img.collec = elem->collec;
	img.exit = elem->exit;
	img.player = elem->player;
	mlx_hook(img.winptr, 2, 0, ft_actions, &img);
	mlx_hook(img.winptr, 17, 0, ft_actions_for_exit, &img);
	mlx_loop(img.ptr);
}

void	ft_fill_window(char **map, t_elem *elem, t_img *img)
{
	while (elem->j < elem->index)
	{
		elem->i = 0;
		elem->i_dim = 0;
		while (elem->i < elem->len - 1)
			ft_put_if(map, elem, img);
		elem->j_dim += img->a;
		elem->j++;
	}
}
