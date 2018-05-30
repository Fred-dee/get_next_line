/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:11:23 by mdilapi           #+#    #+#             */
/*   Updated: 2018/05/21 08:11:57 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char	*ts1;
	char	*ts2;
	size_t	i;
	int		flag;

	ts1 = (char *)s1;
	ts2 = (char *)s2;
	i = 0;
	flag = 0;
	while (i < n && flag == 0)
	{
		if ((unsigned char)ts2[i] == (unsigned char)c)
			flag = 1;
		ts1[i] = ts2[i];
		i++;
	}
	if (flag == 1)
		return (s1 + i);
	return (NULL);
}
