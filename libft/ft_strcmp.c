/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 13:33:04 by mdilapi           #+#    #+#             */
/*   Updated: 2018/05/21 13:33:05 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	if (*s2 == '\0' && *s1 != '\0')
		return (1);
	if (*s1 == '\0' && *s2 != '\0')
		return (-1);
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if ((unsigned int)s1[i] > (unsigned int)s2[i])
			return (1);
		else if ((unsigned int)s1[i] < (unsigned int)s2[i])
			return (-1);
		i++;
	}
	return ((unsigned int)s2[i] - (unsigned int)s1[i]);
}
