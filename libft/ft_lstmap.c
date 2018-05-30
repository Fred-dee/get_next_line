/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 09:08:07 by mdilapi           #+#    #+#             */
/*   Updated: 2018/05/17 09:08:08 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	**ret;
	t_list	*iter;
	t_list	*tmp;
	t_list	*input;

	if (lst == NULL)
		return (NULL);
	if ((input = f(lst)) == NULL)
		return (NULL);
	if ((ret = (t_list**)malloc(sizeof(t_list *))) == NULL)
		return (NULL);
	if ((*ret = ft_lstnew(input->content, input->content_size)) == NULL)
		return (NULL);
	tmp = *ret;
	iter = lst->next;
	while (iter != NULL)
	{
		if ((input = f(iter)) == NULL)
			return (NULL);
		if (!(tmp->next = ft_lstnew(input->content, input->content_size)))
			return (NULL);
		tmp = tmp->next;
		iter = iter->next;
	}
	return (*ret);
}
