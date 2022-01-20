/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:34:03 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/17 17:29:27 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#define BUFFER_SIZE 42
static char *next_line(char *save)
{
	unsigned int i;
	unsigned int j;
	char *res;

	i = 0;
	j = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i] || !save[i + 1])
		return (free(save), NULL);
	if (save[i])
		i++;
	res = malloc(sizeof(char) * ft_strlen(save + i) + 1);
	if (!res)
		return (free(save), NULL);
	while (save[i])
	{
		res[j] = save[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (free(save), res);
}

char *get_next_line(int fd)
{
	static char *save = NULL;
	char *buf;
	char *res;
	int count;

	count = 1;
	if (BUFFER_SIZE <= 0 && fd < 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (count && (ft_strchr(save, '\n') == 0))
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count <= 0)
			break;
		buf[count] = '\0';
		save = ft_strjoin2(save, buf);
	}
	res = ft_strdup2(save);
	save = next_line(save);
	return (free(buf), res);
}
/*
int	main(void)
{
	int		fd;
	char	*str;

	fd = open("big_line_with_nl", O_RDWR);
	if (fd == -1)
	{
		printf("error");
		return (0);
	}
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("GNL RESULT : %s\n", str);
		free(str);
	}
	close(fd);
	return (0);
}*/
