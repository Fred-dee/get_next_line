/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:16:50 by mdilapi           #+#    #+#             */
/*   Updated: 2018/05/21 08:16:51 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(src);
	while (*dst && dstsize > 0)
	{
		dst++;
		i++;
		dstsize--;
	}
	if (dstsize == 0)
		return (i + j);
	while (*src != '\0')
	{
		if (dstsize != 1)
		{
			*dst++ = *src;
			dstsize--;
		}
		src++;
	}
	if (dstsize == 1 || *src == '\0')
		*dst = '\0';
	return (j + i);
}
