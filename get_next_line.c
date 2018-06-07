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

void		swapnfree(char **var, char *new_val)
{
	char	*tmp;

	tmp = new_val;
	free(*var);
	*var = tmp;
}

int	index_of(const char *s, const char c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}

static 	int	gnl(const int fd, char **ret_line, char **buffer)
{
	int		read_ret;
	int		nl;
	int		nl_index;

	read_ret = 3;
	nl = 0;
	while (nl == 0 && read_ret > 0)
	{
		nl_index = index_of(*buffer, '\n');
		if (nl_index != -1)
		{
			nl = 1;
			swapnfree(ret_line, ft_strjoin(*ret_line, ft_strsub(*buffer, 0, nl_index)));
			if (BUFF_SIZE - nl_index == 0)
				ft_strclr(*buffer);
			else *buffer = ft_strsub(*buffer, nl_index + 1, BUFF_SIZE - nl_index);
		}
		else
		{
			swapnfree(ret_line, ft_strjoin(*ret_line, *buffer));
			ft_strclr (*buffer);
			swapnfree(buffer, *buffer);
			*buffer = ft_strnew(BUFF_SIZE + 1);
			if ((read_ret = read(fd, *buffer, BUFF_SIZE)) == -1)
				return (-1);
			buffer[0][read_ret] = '\0';
		}
	}
	return (read_ret);
}

int			get_next_line(const int fd, char **line)
{
	char static	*buffer[100];
	char		*ret_line;
	int			read_ret;

	if (line == NULL || fd < 0)
		return (-1);
	if (buffer[fd] == NULL)
		buffer[fd] = ft_strnew(BUFF_SIZE + 1);
	ret_line = ft_strnew(BUFF_SIZE + 1);
	ft_strclr(ret_line);
	if (ft_isempty(buffer[fd]))
	{
		if ((read_ret = read(fd, buffer[fd], BUFF_SIZE)) < 0)
			return (-1);
		buffer[fd][read_ret] = '\0';
	}
	read_ret = gnl(fd, &ret_line, &buffer[fd]);
	if (read_ret < 0)
		return (-1);
	if (ft_isempty(ret_line) && read_ret == 0)
		return (0);
	*line = ret_line;
	return (1);
}