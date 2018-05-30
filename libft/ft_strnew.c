/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:18:27 by mdilapi           #+#    #+#             */
/*   Updated: 2018/05/21 08:18:29 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strnew(size_t size)
{
	char	*ret;
	size_t	i;

	if ((ret = (char *)malloc(sizeof(char) * size + 1)) != NULL)
	{
		i = 0;
		while (i < size + 1)
			ret[i++] = '\0';
		return (ret);
	}
	return (NULL);
}
