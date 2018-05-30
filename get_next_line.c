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

char *get_uptonl(char *s1)
{
	size_t i;
	char *ret;

	i = 0;
	while (s1[i] != '\0' && s1[i] != '\n')
		i++;
	if((ret = (char *)malloc(sizeof(char) * i + 1)) != NULL)
	{
		i = 0;
		while(s1[i] != '\0' && s1[i] != '\n')
		{
			ret[i] = s1[i];
			i++;
		}
		ret[i] = '\0';
	}
	return (ret);
}

int	get_next_line(const int fd, char **line)
{
	static char	buffer[BUFF_SIZE + 1];
	static char *ptr;
	char *tmp;
	char *ret_line;
	int	read_ret;
	int newline = 0;
	read_ret = 20;
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
	while (newline == 0 && read_ret > 0)
	{
		tmp = ft_strchr(ptr, '\n');
		if(tmp)
		{
			ret_line = ft_strjoin(ret_line, get_uptonl(ptr));
			newline = 1;
			if (ptr - tmp  == 0)
			{
				ft_strclr(buffer);
				ptr = buffer;
			}
			ptr = ++tmp;	
		}
		else 
		{
			ret_line = ft_strjoin(ret_line, ptr);
			read_ret = read(fd, buffer, BUFF_SIZE);
			buffer[read_ret] = '\0';
			ptr = buffer;
		}
	}
	*line = ret_line;
	return (read_ret);
}