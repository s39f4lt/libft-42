/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:57:34 by idunaver          #+#    #+#             */
/*   Updated: 2018/12/20 16:55:16 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(void *content, size_t content_size)
{
	if (content)
		free(content);
	content_size = 0;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*copy;

	if (!lst || !f)
		return (NULL);
	if (lst)
	{
		new = f(lst);
		copy = new;
		while (lst->next)
		{
			if (!(copy->next = f(lst->next)))
				ft_lstdel(&lst, ft_free);
			copy = copy->next;
			lst = lst->next;
		}
		return (new);
	}
	return (NULL);
}
