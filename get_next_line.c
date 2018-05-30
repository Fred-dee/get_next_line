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

int	get_next_line(const int fd, char **line)
{
	static char	buffer[BUFF_SIZE];
	static char *ptr;
	char *tmp;
	char *ret_line;
	int	read_ret;
	int newline = 0;
	read_ret = 3;
	if (line == NULL || fd < 0)
		return (-1);
	ret_line = ft_strnew(BUFF_SIZE + 1);
	ft_strclr(ret_line);
	if (ft_isempty(buffer))
	{
		read_ret = read(fd, buffer, BUFF_SIZE);
		if (read_ret == -1)
			return (read_ret);
		ptr = buffer;
	}
	while (newline == 0 && read_ret != -1)
	{
		tmp = ft_strchr(ptr, '\n');
		if(tmp)
		{
			ret_line = ft_strjoin(ret_line, ft_strsub(ptr, 0, ptr - tmp));
			newline = 1;
			if (ptr - tmp  == 0)
			{
				ft_strclr(buffer);
			} else ptr = ++tmp;			
		}
		else 
		{
			ret_line = ft_strjoin(ret_line, buffer);
			read_ret = read(fd, buffer, BUFF_SIZE);
			ptr = buffer;
		}
	}
	*line = ret_line;
	return (read_ret);
}