/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:09:23 by okassimi          #+#    #+#             */
/*   Updated: 2023/04/28 17:09:57 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_images
{
	int		a;
	int		b;
	int		px_position;
	int		py_position;
	int		ex_position;
	int		ey_position;
	void	*winptr;
	void	*ptr;
	void	*floor;
	void	*wall;
	void	*cdoor;
	void	*back;
	void	*col;
	void	*odoor;
	void	*front;
	void	*left;
	void	*right;
	char	**mapp;
	int		collec;
	int		player;
	int		exit;
}			t_img;

typedef struct s_elements
{
	size_t	j;
	size_t	i;
	int		collec;
	int		player;
	int		exit;
	size_t	index;
	size_t	len;
	int		i_dim;
	int		j_dim;
}			t_elem;

void		ft_search_error(int argc, char **argv, t_elem *elem);
void		ft_write_error(char *string);
int			ft_check_map(char *arg, t_elem *elem);
void		ft_count_lines(char *arg, size_t *index);
char		**ft_fill_map(int fd, t_elem *elem);
int			ft_check_walls(char **arr, t_elem *elem);
int			ft_check_elem(char **arr, t_elem *elem);
char		**ft_copy_map(char **map, t_elem *elem);
void		ft_check_path(char **map, char **copy_map, int height, int width);
void		ft_write_this_error(char *string, char **map, char **copy_map);
void		ft_make_window(char **map, t_elem *elem);
void		ft_fill_window(char **map, t_elem *elem, t_img *img);
void		ft_file_to_map(t_img *img);

void		ft_put_if(char **map, t_elem *elem, t_img *img);
void		ft_put_1(t_elem *elem, t_img *img);
void		ft_put_e(t_elem *elem, t_img *img);
void		ft_put_p(t_elem *elem, t_img *img);
void		ft_put_c(t_elem *elem, t_img *img);

int			ft_actions(int keycode, t_img *img);
int			ft_actions_for_exit(t_img *img);
void		ft_key_right(t_img *img, int *moves, int *collecc);
void		ft_key_left(t_img *img, int *moves, int *collecc);
void		ft_key_up(t_img *img, int *moves, int *collecc);
void		ft_key_down(t_img *img, int *moves, int *collecc);
void		ft_key_esc(t_img *img);

void		ft_free_2ptr(char **map1, char **map2);
void		ft_exit(t_img *img, int *collecc, int *moves);
void		ft_free(char **map);

#endif