/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:49:25 by mdilapi           #+#    #+#             */
/*   Updated: 2018/05/21 08:49:26 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;
	size_t			i;
	int				found;

	i = 0;
	found = 0;
	tmp = (unsigned char *)s;
	while (i < n && found == 0)
	{
		if ((unsigned char)tmp[i] == (unsigned char)c)
			found = 1;
		i++;
	}
	if (found == 1)
		return ((void *)s + i - 1);
	return (NULL);
}
