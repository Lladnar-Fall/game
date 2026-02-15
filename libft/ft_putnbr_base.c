/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutucir <rlutucir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:45:03 by rlutucir          #+#    #+#             */
/*   Updated: 2025/08/15 11:45:11 by rlutucir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	int				e_check;
	int				count;
	unsigned long	base_len;

	count = 0;
	base_len = ft_strlen(base);
	if (nbr >= base_len)
	{
		e_check = ft_putnbr_base((nbr / base_len), base);
		if (e_check == -1)
			return (-1);
		count += e_check;
	}
	if (ft_putchar(base[nbr % base_len]) == -1)
		return (-1);
	count += 1;
	return (count);
}
