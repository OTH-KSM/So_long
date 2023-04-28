/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 03:40:47 by okassimi          #+#    #+#             */
/*   Updated: 2022/11/29 02:14:42 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>

int		ft_printf(const char *s, ...);

void	ft_putnbr(long long nb, size_t *a);

void	ft_unputnbr(unsigned int nb, size_t *a);

void	ft_putchar(char c, size_t *a);

void	ft_putstr(const char *s, size_t *a);

void	ft_address(unsigned long long nb, size_t *a);

void	ft_upphex(unsigned long long nb, size_t *a);

void	ft_lowhex(unsigned long long nb, size_t *a);

#endif