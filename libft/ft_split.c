/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutucir <rlutucir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:51:54 by rlutucir          #+#    #+#             */
/*   Updated: 2025/12/07 12:57:23 by rlutucir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_it(char **s)
{
	if (!s)
		return ;
	int i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

static int	words_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s && *s == c)
		s++;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

static char	**split_words(char **str, char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		len = words_len(s, c);
		if (len > 0)
		{
			str[i] = (char *)malloc(len + 1);
			if (!str[i])
			{
				free_it(str);
				return (NULL);
			}
			ft_strlcpy(str[i], s, len + 1);
			str[i][len] = '\0';
			i++;
			s += len;
		}
	}
	str[i] = NULL;
	return (str);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (*s)
	{
		if (*s != c && !counter)
		{
			counter = 1;
			i++;
		}
		else if (*s == c)
		{
			counter = 0;
		}
		s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	len;

	if (!s)
		return (NULL);
	len = count_words(s, c);
	str = (char **)malloc(sizeof(char *) * (len + 1));
	if (!str)
		return (NULL);
	if (!split_words(str, s, c))
		return (NULL);
	return (str);
}
