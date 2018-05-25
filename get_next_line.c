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
static int	cat_join(size_t *i, int *count, char **tmp, char *ret)
{
	if (*i == (size_t)(BUFF_SIZE * *count - 1))
	{
		*count = *count + 1;
		if ((*tmp = ft_strjoin(*tmp, ret)) == NULL)
			return (-1);
	} else 
	{
		*tmp = ft_strncat(*tmp, ret, BUFF_SIZE * *count + 3);
	}
	return (1);
}
static int	gnl(char *ret, char **tmp, const int fd)
{
	int		count;
	int		new_line;
	int 	read_ret;
	size_t	i;
	
	count = 1;
	i = 0;
	new_line = -1;
	read_ret = 3;
	while(read_ret != 0 && new_line == -1 && i < (size_t)BUFF_SIZE * count)
	{
		ft_strclr(ret);
		read_ret = read(fd, ret, 1);
		if (read_ret == -1)
			return (read_ret);
		new_line = found_nl(ret);
		if (new_line != -1)
			ret[new_line] = '\0';	
		if (cat_join(&i, &count, tmp, ret) == - 1)
			return (-1);
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
		return (-1);
	ret = ft_strnew(BUFF_SIZE + 1);
	tmp = ft_strnew(BUFF_SIZE + 1);
	ft_strclr(tmp);
	read_ret = gnl(ret, &tmp, fd);
	if (read_ret == -1)
		return (read_ret);
	*line = tmp;
	free(ret);
	if (read_ret == 0)
		return (0);
	return (1);
}
