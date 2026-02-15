/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutucir <rlutucir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:44:13 by rlutucir          #+#    #+#             */
/*   Updated: 2025/08/15 11:44:23 by rlutucir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr(void *p)
{
	unsigned long	ptr;
	int				count;
	int				e_check;

	if (!p)
	{
		if (ft_putstr("0x0") == -1)
			return (-1);
		return (3);
	}
	if (ft_putstr("0x") == -1)
		return (-1);
	count = 2;
	ptr = (unsigned long)p;
	e_check = ft_putnbr_base(ptr, "0123456789abcdef");
	if (e_check == -1)
		return (-1);
	count += e_check;
	return (count);
}
