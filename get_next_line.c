/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 09:36:20 by mdilapi           #+#    #+#             */
/*   Updated: 2018/06/04 09:36:21 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./libft/includes/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static void		swapnfree(char **var, char *new_val)
{
	char	*tmp;

	tmp = new_val;
	free(*var);
	*var = tmp;
}

static char		*get_uptonl(char *s1)
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

static char		*get_afternl(char *s1)
{
	size_t i;
	size_t j;
	char *ret;

	i = 0;
	while (s1[i] != '\0' && s1[i] != '\n')
		i++;
	if (s1[i] == '\0')
		return (NULL);
	i++;
	j = 0;
	if ((ret = (char *)malloc(sizeof(char) * ft_strlen(s1) - i + 1)) != NULL)
	{
		while(s1[i] != '\0')
			ret[j++] = s1[i++];
		ret[j] = '\0';
	}
	return (ret);
}

static int	gnl(const int fd, char **ret_line, char **buffer)
{
	char	*tmp;
	int		nl;
	int		read_ret;
	char	*vrytmp;

	nl = 0;
	read_ret = 10;
	while (nl == 0 && read_ret > 0)
	{
		tmp = ft_strchr(*buffer, '\n');
		if (tmp)
		{
			nl = 1;
			vrytmp = get_uptonl(*buffer);
			swapnfree(ret_line, ft_strjoin(*ret_line, vrytmp));
			if (*(tmp + 1) == '\0')
				ft_strclr(*buffer);
			else
			{
				swapnfree(buffer, get_afternl(*buffer));
			}
			free(vrytmp);
		}
		else
		{
			swapnfree(ret_line, ft_strjoin(*ret_line, *buffer));
			ft_strclr(*buffer);
			if((read_ret = read(fd, *buffer, BUFF_SIZE)) == -1)
				return (-1);
			buffer[0][read_ret] = '\0';
		}
	}
	return (read_ret);
}
int			get_next_line(const int fd, char **line)
{
	char static	*buffers[1000];
	char		*ret_line;
	int			read_ret;

	if (line == NULL || fd < 0)
		return (-1);
	if (buffers[fd] == NULL)
		buffers[fd] = ft_strnew(BUFF_SIZE + 1);
	ret_line = ft_strnew(BUFF_SIZE + 1);
	if (ft_isempty(buffers[fd]))
	{
		if((read_ret = read(fd, buffers[fd], BUFF_SIZE)) == -1)
			return (-1);
		buffers[fd][read_ret] = '\0';  
	}
	if((read_ret = gnl(fd, &ret_line, &buffers[fd]) < 0))
		return (-1);
	if (ft_isempty(ret_line) && read_ret == 0)
		return (0);
	*line = ret_line;
	return (1);
}