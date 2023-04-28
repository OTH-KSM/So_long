/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 03:32:03 by okassimi          #+#    #+#             */
/*   Updated: 2022/11/26 03:32:20 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_address(unsigned long long nb, size_t *a)
{	
	ft_putstr("0x", a);
	ft_lowhex(nb, a);
}
