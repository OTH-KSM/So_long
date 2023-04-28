/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 01:16:40 by okassimi          #+#    #+#             */
/*   Updated: 2023/04/27 11:25:51 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(t_img *img, int *collecc, int *moves)
{
	if (*collecc == img->collec)
	{
		(*moves)++;
		ft_printf("Mouves : %d\n", (*moves));
		mlx_destroy_window(img->ptr, img->winptr);
		ft_free(img->mapp);
		exit(0);
	}
}

void	ft_key_up(t_img *img, int *moves, int *collecc)
{
	if (img->mapp[(img->py_position - img->b) / img->b][img->px_position
		/ img->a] == '1')
		return ;
	else if (img->mapp[(img->py_position - img->b) / img->b][img->px_position
		/ img->a] == 'C')
	{
		(*collecc)++;
		img->mapp[(img->py_position - img->b) / img->b][img->px_position
			/ img->a] = '0';
	}
	else if (img->mapp[(img->py_position - img->b) / img->b][img->px_position
		/ img->a] == 'E')
	{
		ft_exit(img, &(*collecc), &(*moves));
		return ;
	}
	mlx_put_image_to_window(img->ptr, img->winptr, img->back, img->px_position,
		(img->py_position - img->b));
	mlx_put_image_to_window(img->ptr, img->winptr, img->floor, img->px_position,
		img->py_position);
	img->px_position = img->px_position;
	img->py_position = img->py_position - img->b;
	(*moves)++;
	ft_printf("Mouves : %d\n", (*moves));
}

void	ft_key_down(t_img *img, int *moves, int *collecc)
{
	if (img->mapp[(img->py_position + img->b) / img->b][img->px_position
		/ img->a] == '1')
		return ;
	else if (img->mapp[(img->py_position + img->b) / img->b][img->px_position
		/ img->a] == 'C')
	{
		(*collecc)++;
		img->mapp[(img->py_position + img->b) / img->b][img->px_position
			/ img->a] = '0';
	}
	else if (img->mapp[(img->py_position + img->b) / img->b][img->px_position
		/ img->a] == 'E')
	{
		ft_exit(img, &(*collecc), &(*moves));
		return ;
	}
	mlx_put_image_to_window(img->ptr, img->winptr, img->front, img->px_position,
		(img->py_position + img->b));
	mlx_put_image_to_window(img->ptr, img->winptr, img->floor, img->px_position,
		img->py_position);
	img->px_position = img->px_position;
	img->py_position = img->py_position + img->b;
	(*moves)++;
	ft_printf("Mouves : %d\n", (*moves));
}

void	ft_key_left(t_img *img, int *moves, int *collecc)
{
	if (img->mapp[img->py_position / img->b][(img->px_position - img->a)
		/ img->a] == '1')
		return ;
	else if (img->mapp[img->py_position / img->b][(img->px_position - img->a)
		/ img->a] == 'C')
	{
		(*collecc)++;
		img->mapp[img->py_position / img->b][(img->px_position - img->a)
			/ img->a] = '0';
	}
	else if (img->mapp[img->py_position / img->b][(img->px_position - img->a)
		/ img->a] == 'E')
	{
		ft_exit(img, &(*collecc), &(*moves));
		return ;
	}
	mlx_put_image_to_window(img->ptr, img->winptr, img->left,
		(img->px_position - img->a), img->py_position);
	mlx_put_image_to_window(img->ptr, img->winptr, img->floor, img->px_position,
		img->py_position);
	img->px_position = img->px_position - img->a;
	img->py_position = img->py_position;
	(*moves)++;
	ft_printf("Mouves : %d\n", (*moves));
}

void	ft_key_right(t_img *img, int *moves, int *collecc)
{
	if (img->mapp[img->py_position / img->b][(img->px_position + img->a)
		/ img->a] == '1')
		return ;
	else if (img->mapp[img->py_position / img->b][(img->px_position + img->a)
		/ img->a] == 'C')
	{
		(*collecc)++;
		img->mapp[img->py_position / img->b][(img->px_position + img->a)
			/ img->a] = '0';
	}
	else if (img->mapp[img->py_position / img->b][(img->px_position + img->a)
		/ img->a] == 'E')
	{
		ft_exit(img, &(*collecc), &(*moves));
		return ;
	}
	mlx_put_image_to_window(img->ptr, img->winptr, img->right,
		(img->px_position + img->a), img->py_position);
	mlx_put_image_to_window(img->ptr, img->winptr, img->floor, img->px_position,
		img->py_position);
	img->px_position = img->px_position + img->a;
	img->py_position = img->py_position;
	(*moves)++;
	ft_printf("Mouves : %d\n", (*moves));
}
