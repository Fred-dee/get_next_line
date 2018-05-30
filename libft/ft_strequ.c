/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:15:49 by mdilapi           #+#    #+#             */
/*   Updated: 2018/05/21 08:15:50 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_strequ(char const *s1, char const *s2)
{
	size_t	i;

	if (s1 != NULL && s2 != NULL)
	{
		if (ft_strlen(s1) != ft_strlen(s2))
			return (0);
		i = 0;
		while (s1[i] != '\0')
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
	}
	return (1);
}
