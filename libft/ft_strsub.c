/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:19:37 by mdilapi           #+#    #+#             */
/*   Updated: 2018/05/21 08:19:38 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;
	size_t			count;

	ret = NULL;
	if (s != NULL)
	{
		ret = ft_strnew(len);
		if (ret != NULL)
		{
			i = start;
			count = 0;
			while (s[i] != '\0' && count < len)
				ret[count++] = s[i++];
		}
	}
	return (ret);
}
