/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutucir <rlutucir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:43:15 by rlutucir          #+#    #+#             */
/*   Updated: 2025/08/15 11:48:28 by rlutucir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_specifier(const char *s, va_list args)
{
	if (*s == 'd' || *s == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (*s == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*s == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*s == 'p')
		return (ft_ptr(va_arg(args, void *)));
	else if (*s == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789"));
	else if (*s == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (*s == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (*s == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		e_check;
	va_list	args;

	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			e_check = check_specifier(++str, args);
			if (e_check == -1)
				return (-1);
			count += e_check;
		}
		else
		{
			if (ft_putchar(*str) == -1)
				return (-1);
			count++;
		}
		str++;
	}
	va_end(args);
	return (count);
}
