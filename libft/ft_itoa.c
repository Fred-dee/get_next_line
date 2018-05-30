/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 09:01:03 by mdilapi           #+#    #+#             */
/*   Updated: 2018/05/17 09:01:05 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static char	*is_zero(void)
{
	char *s;

	s = (char *)malloc(sizeof(char) * 2);
	s[0] = '0';
	s[1] = '\0';
	return (s);
}

static void	is_negative(int *a, int *count)
{
	if (*a < 0)
	{
		*a = *a * -1;
		if (*a < 0)
		{
			*a = *a + 1;
			*a = *a * -1;
		}
		*count = *count + 1;
	}
}

char		*ft_itoa(int n)
{
	int		tmp;
	int		count;
	char	*ret;

	if (n == 0)
		return (is_zero());
	count = 0;
	tmp = n;
	is_negative(&tmp, &count);
	while (tmp > 0)
	{
		tmp /= 10;
		count++;
	}
	if ((ret = ft_strnew(count--)) == NULL)
		return (NULL);
	if (n < 0)
		ret[0] = '-';
	while (n != 0)
	{
		ret[count--] = ABS(ABS(n) % 10) + '0';
		n /= 10;
	}
	return (ret);
}
