/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:12:18 by mdilapi           #+#    #+#             */
/*   Updated: 2018/05/21 08:12:19 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*ts1;
	char	*ts2;
	char	*tmp;
	size_t	i;

	i = 0;
	if ((tmp = (char *)malloc(sizeof(char) * n)) != NULL)
	{
		ts1 = (char *)s1;
		ts2 = (char *)s2;
		while (i < n)
		{
			tmp[i] = ts2[i];
			i++;
		}
		i = 0;
		while (i < n)
		{
			ts1[i] = tmp[i];
			i++;
		}
		free(tmp);
		tmp = NULL;
	}
	return (s1);
}
