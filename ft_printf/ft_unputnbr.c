/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unputnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 03:39:32 by okassimi          #+#    #+#             */
/*   Updated: 2022/11/27 18:00:55 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unputnbr(unsigned int nb, size_t *a)
{
	if (nb >= 10)
	{
		ft_unputnbr(nb / 10, a);
		ft_unputnbr(nb % 10, a);
	}
	if (nb >= 0 && nb < 10)
	{
		ft_putchar(nb + '0', a);
	}
}
