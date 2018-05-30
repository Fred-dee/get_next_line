/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:11:09 by mdilapi           #+#    #+#             */
/*   Updated: 2018/05/21 08:11:11 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	void	*ret;
	size_t	i;
	char	*tmp;

	if ((ret = (void *)malloc(sizeof(void) * size)) != NULL)
	{
		tmp = (char *)ret;
		i = 0;
		while (i < size)
			tmp[i++] = 0;
		return (ret);
	}
	return (NULL);
}
