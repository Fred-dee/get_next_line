/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:15:35 by mdilapi           #+#    #+#             */
/*   Updated: 2018/05/21 08:15:36 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *s)
{
	char	*ret;
	int		i;

	ret = NULL;
	if ((ret = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)) != NULL)
	{
		i = 0;
		while (s[i] != '\0')
		{
			ret[i] = s[i];
			i++;
		}
		ret[i] = '\0';
	}
	return (ret);
}
