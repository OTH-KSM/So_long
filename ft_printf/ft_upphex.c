/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upphex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 03:40:08 by okassimi          #+#    #+#             */
/*   Updated: 2022/11/27 18:01:14 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_upphex(unsigned long long nb, size_t *a)
{
	if (nb < 10)
	{
		ft_putchar(nb + 48, a);
	}
	else if (nb >= 10 && nb < 16)
	{
		ft_putchar(nb + 55, a);
	}
	else
	{
		ft_upphex(nb / 16, a);
		ft_upphex(nb % 16, a);
	}
}
