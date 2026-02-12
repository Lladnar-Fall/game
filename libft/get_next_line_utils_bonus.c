/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutucir <rlutucir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 22:15:25 by rlutucir          #+#    #+#             */
/*   Updated: 2026/02/09 18:17:04 by rlutucir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gnl_strchr(const char *s, int c)
{
	char	d;
	int		i;

	if (!s)
		return (NULL);
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

char	*gnl_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*dst;

	i = 0;
	len = gnl_strlen(s1);
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	while (i < len)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (gnl_strdup(s2));
	if (!s2)
		return (gnl_strdup(s1));
	new_str = malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	return (new_str);
}

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*str;

	if (!s)
		return (NULL);
	s_len = gnl_strlen(s);
	if (start >= s_len)
		return (gnl_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[len] = '\0';
	return (str);
}
