/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutucir <rlutucir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:00:34 by rlutucir          #+#    #+#             */
/*   Updated: 2026/02/09 18:12:51 by rlutucir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

char		*get_next_line(int fd);
char		*gnl_strchr(const char *s, int c);
char		*gnl_strdup(const char *s1);
char		*gnl_strjoin(char const *s1, char const *s2);
char		*gnl_substr(char const *s, unsigned int start, size_t len);
size_t		gnl_strlen(const char *s);

#endif