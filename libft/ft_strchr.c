/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutucir <rlutucir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:52:23 by rlutucir          #+#    #+#             */
/*   Updated: 2025/08/06 09:52:36 by rlutucir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	d;
	int		i;

	d = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == d)
			return ((char *)s + i);
		i++;
	}
	if (d == '\0')
		return ((char *)s + i);
	return (NULL);
}
