/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:02:26 by okassimi          #+#    #+#             */
/*   Updated: 2023/04/10 17:07:32 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_pouss
{
	char		*temp;
	char		*buffer;
	char		*line;
	int			rdd;
	int			jeton;
	int			j;
	int			check;
}t_pos;

char	*get_next_line(int fd);
char	*ft_gnlstrdup(const char *s1);
char	*ft_gnlstrjoin(char *s1, char *s2);
size_t	ft_gnlstrlen(const char *str);
char	*ft_gnlstrchr(char *s, int c);
char	*ft_gnlsubstr(char *s, unsigned int start, size_t len);

#endif