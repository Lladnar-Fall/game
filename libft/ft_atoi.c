/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutucir <rlutucir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:33:09 by rlutucir          #+#    #+#             */
/*   Updated: 2025/08/06 09:38:21 by rlutucir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int			num;
	int			sign;
	long long	result;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\v')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = *str - '0';
		if ((result > 922337203685477580)
			|| (result == 922337203685477580 && num > 7))
			return (-1 * (sign != -1));
		result = (*str - '0') + (result * 10);
		str++;
	}
	return (((int)result) * ((int)sign));
}
