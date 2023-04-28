/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 03:33:40 by okassimi          #+#    #+#             */
/*   Updated: 2022/11/29 02:14:09 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check(const char *s, int *i, size_t *count, va_list *ptr)
{
	if (s[(*i) + 1] == 'd' || s[(*i) + 1] == 'i')
		ft_putnbr(va_arg((*ptr), int), &(*(count)));
	else if (s[(*i) + 1] == 'u' )
		ft_unputnbr(va_arg((*ptr), int), &(*(count)));
	else if (s[(*i) + 1] == 'c')
		ft_putchar(va_arg((*ptr), int), &(*(count)));
	else if (s[(*i) + 1] == 's')
		ft_putstr(va_arg((*ptr), char *), &(*(count)));
	else if (s[(*i) + 1] == 'p')
		ft_address(va_arg((*ptr), unsigned long long),
			&(*(count)));
	else if (s[(*i) + 1] == 'x')
		ft_lowhex((unsigned int)va_arg((*ptr), unsigned long long),
			&(*(count)));
	else if (s[(*i) + 1] == 'X')
		ft_upphex((unsigned int)va_arg((*ptr), unsigned long long),
			&(*(count)));
	else
		ft_putchar('%', &(*(count)));
}

int	ft_printf(const char *s, ...)
{
	int		i;
	size_t	count;
	va_list	ptr;

	va_start(ptr, s);
	i = 0;
	count = 0 ;
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == 'd' || s[i + 1] == 'i' || s[i + 1] == 'u'
				|| s[i + 1] == 'c' || s[i + 1] == 's' || s[i + 1] == 'p'
				|| s[i + 1] == 'x' || s[i + 1] == 'X' || s[i + 1] == '%')
			{
				check(s, &i, &count, &ptr);
				i++;
			}
		}
		else
			ft_putchar(s[i], &count);
		i++ ;
	}
	return (count);
}
