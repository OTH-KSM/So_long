/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 02:12:22 by okassimi          #+#    #+#             */
/*   Updated: 2023/04/18 02:15:10 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_1(t_elem *elem, t_img *img)
{
	mlx_put_image_to_window(img->ptr, img->winptr, img->floor, elem->i_dim,
		elem->j_dim);
	mlx_put_image_to_window(img->ptr, img->winptr, img->wall, elem->i_dim,
		elem->j_dim);
}

void	ft_put_e(t_elem *elem, t_img *img)
{
	img->ex_position = elem->i_dim;
	img->ey_position = elem->j_dim;
	mlx_put_image_to_window(img->ptr, img->winptr, img->floor, elem->i_dim,
		elem->j_dim);
	mlx_put_image_to_window(img->ptr, img->winptr, img->cdoor, elem->i_dim,
		elem->j_dim);
}

void	ft_put_p(t_elem *elem, t_img *img)
{
	img->px_position = elem->i_dim;
	img->py_position = elem->j_dim;
	mlx_put_image_to_window(img->ptr, img->winptr, img->floor, elem->i_dim,
		elem->j_dim);
	mlx_put_image_to_window(img->ptr, img->winptr, img->front, elem->i_dim,
		elem->j_dim);
}

void	ft_put_c(t_elem *elem, t_img *img)
{
	mlx_put_image_to_window(img->ptr, img->winptr, img->floor, elem->i_dim,
		elem->j_dim);
	mlx_put_image_to_window(img->ptr, img->winptr, img->col, elem->i_dim,
		elem->j_dim);
}

void	ft_put_if(char **map, t_elem *elem, t_img *img)
{
	if (map[elem->j][elem->i] == '0')
		mlx_put_image_to_window(img->ptr, img->winptr, img->floor, elem->i_dim,
			elem->j_dim);
	else if (map[elem->j][elem->i] == '1')
		ft_put_1(elem, img);
	else if (map[elem->j][elem->i] == 'E')
		ft_put_e(elem, img);
	else if (map[elem->j][elem->i] == 'P')
		ft_put_p(elem, img);
	else if (map[elem->j][elem->i] == 'C')
		ft_put_c(elem, img);
	elem->i_dim += img->b;
	elem->i++;
}
