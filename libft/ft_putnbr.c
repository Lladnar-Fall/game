/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutucir <rlutucir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:45:20 by rlutucir          #+#    #+#             */
/*   Updated: 2025/08/15 11:45:31 by rlutucir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		count;
	long	num;
	int		e_check;

	count = 0;
	num = (long)n;
	if (num < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		count++;
		num = -num;
	}
	if (num > 9)
	{
		e_check = ft_putnbr(num / 10);
		if (e_check == -1)
			return (-1);
		count += e_check;
	}
	if (ft_putchar((num % 10) + '0') == -1)
		return (-1);
	count++;
	return (count);
}
