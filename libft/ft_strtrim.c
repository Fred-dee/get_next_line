/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:19:54 by mdilapi           #+#    #+#             */
/*   Updated: 2018/05/21 08:19:54 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static size_t	white_count(char const *s, size_t *i)
{
	size_t		count;

	count = 0;
	while (s[*i] == ' ' || s[*i] == '\t' || s[*i] == '\n')
	{
		*i = *i - 1;
		count++;
	}
	return (count);
}

char			*ft_strtrim(char const *s)
{
	size_t		i;
	char const	*tmp;
	char		*ret;
	size_t		n_size;

	if (s == NULL)
		return (NULL);
	tmp = s;
	while (*tmp == ' ' || *tmp == '\t' || *tmp == '\n')
		tmp++;
	if (*tmp == '\0')
		return (ft_strdup(""));
	i = ft_strlen(s) - 1;
	n_size = ft_strlen(tmp) - white_count(s, &i);
	if ((ret = ft_strnew(n_size)) != NULL)
	{
		i = 0;
		while (tmp[i] != '\0' && i < n_size)
		{
			ret[i] = tmp[i];
			i++;
		}
		ret[i] = '\0';
	}
	return (ret);
}
