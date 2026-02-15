/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutucir <rlutucir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:59:03 by rlutucir          #+#    #+#             */
/*   Updated: 2026/02/09 18:14:00 by rlutucir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	void	free_leftover(char **leftover)
{
	free(*leftover);
	*leftover = NULL;
}

static	char	*extract_line_from_leftover(char **leftover)
{
	char	*tmp;
	char	*line;
	size_t	i;

	i = 0;
	if (!*leftover)
		return (NULL);
	while ((*leftover)[i] && (*leftover)[i] != '\n')
		i++;
	if ((*leftover)[i] == '\n')
		i++;
	line = gnl_substr(*leftover, 0, i);
	if (!line)
	{
		free_leftover(leftover);
		return (NULL);
	}
	tmp = NULL;
	if ((*leftover)[i] != '\0')
		tmp = gnl_strdup(*leftover + i);
	free(*leftover);
	*leftover = tmp;
	return (line);
}

static	char	*check_line(char **leftover, ssize_t bytes_read, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp;
	char	*line;

	while (!gnl_strchr(*leftover, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		tmp = gnl_strjoin(*leftover, buffer);
		if (!tmp)
			return (free_leftover(leftover), NULL);
		free(*leftover);
		*leftover = tmp;
	}
	if (bytes_read < 0)
	{
		free_leftover(leftover);
		return (NULL);
	}
	line = extract_line_from_leftover(leftover);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	ssize_t		bytes_read;

	bytes_read = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	if (leftover && gnl_strchr(leftover, '\n'))
		return (extract_line_from_leftover(&leftover));
	return (check_line(&leftover, bytes_read, fd));
}
