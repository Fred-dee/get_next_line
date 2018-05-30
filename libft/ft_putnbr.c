/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:13:56 by mdilapi           #+#    #+#             */
/*   Updated: 2018/05/21 08:13:57 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursive(int n)
{
	if (ABS(n) > 9 || ABS(n) < 0)
		recursive(n / 10);
	ft_putchar(ABS(ABS(n) % 10) + '0');
}

void		ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	recursive(n);
}
