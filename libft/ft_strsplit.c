/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:19:05 by mdilapi           #+#    #+#             */
/*   Updated: 2018/05/21 08:19:06 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static size_t	word_count(char const *s, char c)
{
	char const	*tmp;
	size_t		count;

	count = 0;
	tmp = s;
	while (*tmp != '\0')
	{
		while (*tmp == c && *tmp != '\0')
			tmp++;
		while (*tmp != c && *tmp != '\0')
			tmp++;
		if (*(tmp - 1) != c)
			count++;
	}
	return (count);
}

static size_t	word_len(char const *s, char c)
{
	char const	*tmp;
	size_t		count;

	tmp = s;
	count = 0;
	while (*tmp != c && *tmp != '\0')
	{
		tmp++;
		count++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**ret;
	size_t		d_len;
	size_t		w_len;
	size_t		i;
	size_t		j;
	char const	*tmp;

	if (s == NULL)
		return (NULL);
	tmp = s;
	d_len = word_count(tmp, c);
	if ((ret = (char **)malloc(sizeof(char *) * d_len + 1)) != NULL)
	{
		i = 0;
		while (i < d_len)
		{
			while (*tmp == c && *tmp != '\0')
				tmp++;
			w_len = word_len(tmp, c);
			ret[i] = (char *)malloc(sizeof(char) * w_len + 1);
			j = 0;
			while (*tmp != c && *tmp != '\0')
				ret[i][j++] = *tmp++;
			ret[i][j] = '\0';
			i++;
		}
		ret[i] = NULL;
	}
	return (ret);
}
