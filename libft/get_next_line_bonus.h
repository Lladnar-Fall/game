/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutucir <rlutucir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:43:18 by rlutucir          #+#    #+#             */
/*   Updated: 2026/02/09 18:19:11 by rlutucir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

char		*get_next_line(int fd);
char		*gnl_strchr(const char *s, int c);
char		*gnl_strdup(const char *s1);
char		*gnl_strjoin(char const *s1, char const *s2);
size_t		gnl_strlen(const char *s);
char		*gnl_substr(char const *s, unsigned int start, size_t len);

#endif