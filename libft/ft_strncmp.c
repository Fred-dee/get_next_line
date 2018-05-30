/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 13:33:45 by mdilapi           #+#    #+#             */
/*   Updated: 2018/05/21 13:33:46 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (*s2 == '\0' && *s1 != '\0')
		return (1);
	if (*s1 == '\0' && *s2 != '\0')
		return (-1);
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if ((unsigned int)s1[i] > (unsigned int)s2[i])
			return (1);
		else if ((unsigned int)s1[i] < (unsigned int)s2[i])
			return (-1);
		i++;
	}
	return (0);
}
