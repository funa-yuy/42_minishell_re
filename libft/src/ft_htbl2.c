/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htbl2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:51:11 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:51:12 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_htbl.h"
#include "ft_stdlib.h"
#include "ft_string.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void	htiter(t_htbl ht, void (*f)(t_htnode *, void *), void *p)
{
	int			h;
	t_htnode	*node;
	t_htnode	*_node;

	h = 0;
	while (h < HTSIZE)
	{
		node = ht[h];
		while (node)
		{
			_node = node->next;
			f(node, p);
			node = _node;
		}
		h++;
	}
}
