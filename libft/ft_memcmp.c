/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:51:01 by mdilapi           #+#    #+#             */
/*   Updated: 2018/05/21 08:51:02 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ts1;
	unsigned char	*ts2;
	size_t			i;
	int				is_equal;

	i = 0;
	is_equal = 0;
	ts1 = (unsigned char *)s1;
	ts2 = (unsigned char *)s2;
	while (i < n && is_equal == 0)
	{
		if (ts1[i] != ts2[i])
			is_equal = 1;
		i++;
	}
	i--;
	return ((int)ts1[i] - (int)ts2[i]);
}
