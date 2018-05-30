/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:16:38 by mdilapi           #+#    #+#             */
/*   Updated: 2018/05/21 08:16:39 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;
	int		j;

	ret = NULL;
	if (s1 != NULL && s2 != NULL)
	{
		ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (ret != NULL)
		{
			i = 0;
			j = 0;
			while (s1[i] != '\0')
			{
				ret[i] = s1[i];
				i++;
			}
			while (s2[j] != 0)
				ret[i++] = s2[j++];
			ret[i] = '\0';
		}
	}
	return (ret);
}
