/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htbl0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:51:05 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:51:06 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_htbl.h"
#include "ft_stdlib.h"
#include "ft_string.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

t_htbl	htnew(void)
{
	return ((t_htbl)ft_calloc(sizeof(t_htnode *), HTSIZE));
}

uint8_t	hash(const char *key)
{
	if (!key || !key[0] || !key[1])
		return (HTSIZE - 1);
	return (key[0] * key[1] % 251);
}

static t_htnode	*htnodenew(const char *key, void *val)
{
	t_htnode	*p;

	p = (t_htnode *)ft_calloc(sizeof(t_htnode), 1);
	if (!p)
		return (NULL);
	p->key = ft_strdup(key);
	p->val = val;
	return (p);
}

t_htbl	htadd(t_htbl ht, const char *key, void *val)
{
	uint8_t		h;
	t_htnode	*newi;
	t_htnode	**p;

	h = hash(key);
	p = &ht[h];
	while (*p)
	{
		if (!ft_strcmp((*p)->key, key))
		{
			(*p)->val = val;
			return (ht);
		}
		p = &(*p)->next;
	}
	newi = htnodenew(key, val);
	if (!newi)
		return (NULL);
	(*p) = newi;
	return (ht);
}

t_htbl	htget(t_htbl ht, const char *key)
{
	uint8_t		h;
	t_htnode	*i;

	h = hash(key);
	i = ht[h];
	while (i)
	{
		if (!ft_strcmp(i->key, key))
			return (i->val);
		i = i->next;
	}
	return (NULL);
}
