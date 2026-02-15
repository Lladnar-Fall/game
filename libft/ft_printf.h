/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutucir <rlutucir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:43:45 by rlutucir          #+#    #+#             */
/*   Updated: 2026/02/09 16:51:23 by rlutucir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

int				ft_printf(const char *str, ...);
int				ft_ptr(void *p);
int				ft_putchar(char c);
int				ft_putnbr_base(unsigned long nbr, char *base);
int				ft_putnbr(int n);
int				ft_putstr(char *s);

#endif