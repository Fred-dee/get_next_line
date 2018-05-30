/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:14:06 by mdilapi           #+#    #+#             */
/*   Updated: 2018/05/21 08:14:08 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursive_fd(int n, int fd)
{
	if (ABS(n) > 9 || ABS(n) < 0)
		recursive_fd(n / 10, fd);
	ft_putchar_fd(ABS(ABS(n) % 10) + '0', fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	recursive_fd(n, fd);
}
