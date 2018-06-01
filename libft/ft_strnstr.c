/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 13:32:56 by mdilapi           #+#    #+#             */
/*   Updated: 2018/05/21 13:32:57 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int	is_found(const char *s1, const char *s2, size_t k, size_t len)
{
	const char	*tmp1;
	const char	*tmp2;

	tmp1 = s1;
	tmp2 = s2;
	while (*tmp1 == *tmp2 && *tmp1 != '\0' && *tmp2 != '\0')
	{
		tmp1++;
		tmp2++;
		k++;
	}
	if (*tmp1 == '\0' && k <= len)
		return (1);
	return (0);
}

char		*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	const char	*tmp;
	size_t		i;

	i = 0;
	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	if (ft_strlen(s1) == 0 || len == 0)
		return (NULL);
	tmp = s1;
	while (*tmp != '\0' && i < len)
	{
		if (*tmp == s2[0])
			if (is_found(s2, tmp, i, len) == 1)
				return ((char *)tmp);
		tmp++;
		i++;
	}
	return (NULL);
}
