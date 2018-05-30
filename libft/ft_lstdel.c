/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 09:06:00 by mdilapi           #+#    #+#             */
/*   Updated: 2018/05/17 09:06:02 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *prev;

	tmp = *alst;
	while (tmp != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
		del(prev->content, prev->content_size);
		free(prev);
	}
	free(tmp);
	*alst = NULL;
}
