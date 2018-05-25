/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 11:40:05 by mdilapi           #+#    #+#             */
/*   Updated: 2018/05/23 11:40:06 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static int	found_nl(const char *s)
{
	int i;

	i = 0;
	if (s == NULL)
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i++] == '\n')
			return (i - 1);
	}
	return (-1);
}

static int gnl(char *ret, char **tmp, const int fd)
{
	int		count;
	int		new_line;
	int 	read_ret;
	size_t	i;
	
	count = 1;
	i = 0;
	new_line = -1;
	while(read_ret != 0 && new_line == -1 && i < BUFF_SIZE * count)
	{
		ft_strclr(ret);
		read_ret = read(fd, ret, 1);
		if (read_ret == -1)
			return (read_ret);
		new_line = found_nl(ret);
		if (new_line != -1)
			ret[new_line] = '\0';	
		if (i == BUFF_SIZE * count - 1)
		{
			count++;
			*tmp = ft_strjoin(*tmp, ret);
		} else *tmp = ft_strncat(*tmp, ret, BUFF_SIZE * count);
		i++;
	}
	return (read_ret);
}

int	get_next_line(const int fd, char **line)
{
	int		read_ret;
	char	*ret;
	char	*tmp;

	if (fd < 0)
		return (-1);
	if (line == NULL)
		if ((line = (char **)malloc(sizeof(char *))) == NULL)
			return (-1);
	ret = ft_strnew(BUFF_SIZE);
	tmp = ft_strnew(BUFF_SIZE);
	ft_strclr(tmp);
	read_ret = gnl(ret, &tmp, fd);
	*line = tmp;
	free(ret);
	if (read_ret == -1)
		return (read_ret);
	if (read_ret == 0)
		return (0);
	return (1);
}
