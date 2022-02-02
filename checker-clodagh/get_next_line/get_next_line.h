/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:26:23 by clmurphy          #+#    #+#             */
/*   Updated: 2021/12/13 16:36:07 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char *get_next_line(int fd);
char *ft_strdup2(const char *s1);
char *ft_strjoin2(char *s1, char *s2);
int ft_strchr(char *s, int c);
size_t ft_strlen(const char *s);

#endif
