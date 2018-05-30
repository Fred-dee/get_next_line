/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:19:23 by mdilapi           #+#    #+#             */
/*   Updated: 2018/05/21 08:19:24 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int	is_found(const char *s1, const char *s2)
{
	const char	*tmp1;
	const char	*tmp2;

	tmp1 = s1;
	tmp2 = s2;
	while (*tmp1 == *tmp2 && *tmp1 != '\0' && *tmp2 != '\0')
	{
		tmp1++;
		tmp2++;
	}
	if (*tmp1 == '\0')
		return (1);
	return (0);
}

char		*ft_strstr(const char *s1, const char *s2)
{
	const char	*tmp;

	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	tmp = s1;
	while (*tmp != '\0')
	{
		if (*tmp == s2[0])
			if (is_found(s2, tmp) == 1)
				return ((char *)tmp);
		tmp++;
	}
	return (NULL);
}
