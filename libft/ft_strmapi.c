/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:17:33 by mdilapi           #+#    #+#             */
/*   Updated: 2018/05/21 08:17:33 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;

	i = 0;
	ret = NULL;
	if (s != NULL)
	{
		if ((ret = ft_strnew(ft_strlen(s))) == NULL)
			return (NULL);
		while (s[i] != '\0')
		{
			ret[i] = f(i, s[i]);
			i++;
		}
	}
	return (ret);
}
