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
#include "./libft/includes/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


void	swapnfree(char **var, char *new_val)
{
	char	*tmp;

	tmp = new_val;
	free(*var);
	*var = tmp;
}
static char	*get_uptonl(char *s1)
{
	size_t	i;
	char	*ret;

	i = 0;
	while (s1[i] != '\0' && s1[i] != '\n')
		i++;
	if ((ret = (char *)malloc(sizeof(char) * i + 1)) != NULL)
	{
		i = 0;
		while (s1[i] != '\0' && s1[i] != '\n')
		{
			ret[i] = s1[i];
			i++;
		}
		ret[i] = '\0';
	}
	return (ret);
}

static void	work(char **tmp, char **ret_line, char **buffer, char **ptr)
{
	swapnfree(ret_line,ft_strjoin(*ret_line, get_uptonl(*ptr)));
	if (*ptr - *tmp == 0)
	{
		ft_strclr(*buffer);
		*ptr = *buffer;
	}
	else
	{
		*tmp = *tmp + 1;
		*ptr = *tmp;
	}
}

static int	gnl(const int fd, char **ret_line, char **buffer, char **ptr)
{
	int		read_ret;
	char	*tmp;
	int		newline;

	read_ret = 20;
	newline = 0;
	while (newline == 0 && read_ret > 0)
	{
		tmp = ft_strchr(*ptr, '\n');
		if (tmp)
		{
			newline = 1;
			work(&tmp, ret_line, buffer, ptr);
		}
		else
		{
			swapnfree(ret_line, ft_strjoin(*ret_line, *ptr));
			read_ret = read(fd, *buffer, BUFF_SIZE);
			buffer[0][read_ret] = '\0';
			*ptr = *buffer;
		}
	}
	return (read_ret);
}

int			get_next_line(const int fd, char **line)
{
	static char	*buffer;
	static char	*ptr;
	char		*ret_line;
	int			read_ret;

	if (buffer == NULL)
		buffer = ft_strnew(BUFF_SIZE + 1);
	if (line == NULL || fd < 0)
		return (-1);
	ret_line = ft_strnew(BUFF_SIZE + 1);
	ft_strclr(ret_line);
	if (ft_isempty(buffer))
	{
		read_ret = read(fd, buffer, BUFF_SIZE);
		buffer[read_ret] = '\0';
		if (read_ret == -1)
			return (read_ret);
		ptr = buffer;
	}
	read_ret = gnl(fd, &ret_line, &buffer, &ptr);
	*line = ret_line;
	if (read_ret > 0)
		return (1);
	return (read_ret);
}
