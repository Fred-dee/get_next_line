/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:22:09 by mdilapi           #+#    #+#             */
/*   Updated: 2018/05/21 08:22:11 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char	*ts1;
	char	*ts2;
	size_t	i;

	i = 0;
	ts1 = (char *)s1;
	ts2 = (char *)s2;
	while (i < n)
	{
		ts1[i] = ts2[i];
		i++;
	}
	return (s1);
}
