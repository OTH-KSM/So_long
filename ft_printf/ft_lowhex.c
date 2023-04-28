/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowhex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 03:32:27 by okassimi          #+#    #+#             */
/*   Updated: 2022/11/27 18:01:25 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lowhex(unsigned long long nb, size_t *a)
{
	if (nb < 10)
	{
		ft_putchar(nb + 48, a);
	}
	else if (nb >= 10 && nb < 16)
	{
		ft_putchar(nb + 87, a);
	}
	else
	{
		ft_lowhex(nb / 16, a);
		ft_lowhex(nb % 16, a);
	}
}
