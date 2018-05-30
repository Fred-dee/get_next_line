/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 09:23:16 by mdilapi           #+#    #+#             */
/*   Updated: 2018/05/21 09:23:18 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	const char *tmp;
	const char *ret;

	tmp = s;
	ret = NULL;
	while (*tmp != '\0')
	{
		if (*tmp == c)
			ret = tmp;
		tmp++;
	}
	if (*tmp == c)
		return ((char *)tmp);
	return ((char *)ret);
}
