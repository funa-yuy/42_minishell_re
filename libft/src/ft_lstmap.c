/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:52:38 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:52:39 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"
#include <stdlib.h>

static void	free_all(t_list *n, void *c, t_list **root, void (*del)(void *))
{
	free(n);
	free(c);
	ft_lstclear(root, del);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*root;
	t_list	*new;
	t_list	*prev;
	t_list	*cur;
	void	*content;

	cur = lst;
	root = NULL;
	while (lst && f && del && cur)
	{
		content = f(cur->content);
		new = ft_lstnew(content);
		if (content == NULL || new == NULL)
		{
			free_all(new, content, &root, del);
			return (NULL);
		}
		if (root == NULL)
			root = new;
		else
			prev->next = new;
		prev = new;
		cur = cur->next;
	}
	return (root);
}
