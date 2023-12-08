/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavorni <mgavorni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:55:20 by mgavorni          #+#    #+#             */
/*   Updated: 2023/12/01 14:39:56 by mgavorni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE  2

#endif

char	*get_next_line(int fd);
char	*ft_free(char *result_buffer, char *string_buffer);
char	*ft_reader(int fd, char *result);
char	*ft_strrchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_next(char *string_buffer);
size_t  ft_strlen(char *str);


#endif