/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htbl1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:51:08 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:51:09 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_htbl.h"
#include "ft_stdlib.h"
#include "ft_string.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

static void	htnodedel(t_htnode *htnode, void (*del)(t_htnode *))
{
	if (del)
		del(htnode);
	else
	{
		free((void *)htnode->key);
		free((void *)htnode);
	}
}

void	htdelone(t_htnode **ht, const char *key, void (*del)(t_htnode *))
{
	uint8_t		h;
	t_htnode	*i;
	t_htnode	**p;

	h = hash(key);
	p = &ht[h];
	i = ht[h];
	while (i)
	{
		if (!ft_strcmp(i->key, key))
		{
			*p = i->next;
			htnodedel(i, del);
			return ;
		}
		p = &((*p)->next);
		i = i->next;
	}
}

void	htclear(t_htnode **ht, void (*del)(t_htnode *))
{
	uint8_t		h;
	t_htnode	*i;
	t_htnode	*tmp;

	h = 0;
	while (h < HTSIZE)
	{
		i = ht[h];
		while (i)
		{
			tmp = i->next;
			htnodedel(i, del);
			i = tmp;
		}
		h++;
	}
	free(ht);
}
