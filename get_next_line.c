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


static 	int	gnl(const int fd, char **ret_line, char **buffer)
{
	int		nl;
	int		read_ret;
	char	*vrytmp;

	nl = 0;
	read_ret = 3;
	while (nl == 0 && read_ret > 0)
	{
		if (ft_strchr(*buffer, '\n') != NULL)
		{
			nl = 1;
			vrytmp = get_uptonl(*buffer);
			for (size_t i = 0; i < ft_strlen(vrytmp); i++)
				*buffer = *buffer + 1;
			*buffer = *buffer + 1;
			swapnfree(ret_line, ft_strjoin(*ret_line, vrytmp));
			if ( **buffer == '\0')
				ft_strclr(*buffer);
		}
		else
		{
			swapnfree(ret_line, ft_strjoin(*ret_line, *buffer));
			read_ret = read(fd, *buffer, BUFF_SIZE);
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