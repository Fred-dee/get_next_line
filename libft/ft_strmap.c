/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:17:17 by mdilapi           #+#    #+#             */
/*   Updated: 2018/05/21 08:17:18 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	int		i;

	ret = NULL;
	if (s != NULL)
	{
		if ((ret = ft_strnew(ft_strlen(s))) == NULL)
			return (NULL);
		i = 0;
		while (s[i] != '\0')
		{
			ret[i] = f(s[i]);
			i++;
		}
	}
	return (ret);
}
