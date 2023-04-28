/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 01:24:44 by okassimi          #+#    #+#             */
/*   Updated: 2023/04/25 22:06:33 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_actions_for_exit(t_img *img)
{
	mlx_destroy_window(img->ptr, img->winptr);
	ft_free(img->mapp);
	exit(0);
}

void	ft_key_esc(t_img *img)
{
	mlx_destroy_window(img->ptr, img->winptr);
	ft_free(img->mapp);
	exit(0);
}

int	ft_actions(int keycode, t_img *img)
{
	static int	collecc;
	static int	moves;

	if (keycode == 13 || keycode == 126)
		ft_key_up(img, &moves, &collecc);
	if (keycode == 1 || keycode == 125)
		ft_key_down(img, &moves, &collecc);
	if (keycode == 2 || keycode == 124)
		ft_key_right(img, &moves, &collecc);
	if (keycode == 0 || keycode == 123)
		ft_key_left(img, &moves, &collecc);
	if (keycode == 53)
		ft_key_esc(img);
	if (collecc == img->collec)
		mlx_put_image_to_window(img->ptr, img->winptr, img->odoor,
			img->ex_position, img->ey_position);
	return (0);
}
//--->w== 13    up    = 126
//--->s== 1     down  = 125
//--->d== 2     right = 124
//--->a== 0     left  = 123