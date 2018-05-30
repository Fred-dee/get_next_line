/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:14:35 by mdilapi           #+#    #+#             */
/*   Updated: 2018/05/21 08:14:36 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <string.h>

void	ft_putstr_fd(char const *s, int fd)
{
	int i;

	if (fd >= 0 && s != NULL)
	{
		i = 0;
		while (s[i] != '\0')
			write(fd, &s[i++], 1);
	}
}
