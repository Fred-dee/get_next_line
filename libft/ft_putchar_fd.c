/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:12:58 by mdilapi           #+#    #+#             */
/*   Updated: 2018/05/21 08:12:59 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	int buff[2];

	if (fd >= 0)
	{
		if (ft_isascii(c))
			write(fd, &c, 1);
		else
		{
			ft_memmove(buff, "\u00A9", 2);
			ft_memmove(buff + 1, &c, 1);
			write(fd, buff, 2);
		}
	}
}
