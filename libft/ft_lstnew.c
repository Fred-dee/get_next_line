/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 09:53:13 by mdilapi           #+#    #+#             */
/*   Updated: 2018/05/17 09:53:14 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ret;

	if ((ret = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content != NULL)
	{
		ret->content = (void *)malloc(content_size);
		ft_memmove(ret->content, content, content_size);
		ret->content_size = content_size;
		ret->next = NULL;
	}
	else
	{
		ret->content = NULL;
		ret->content_size = 0;
		ret->next = 0;
	}
	return (ret);
}
