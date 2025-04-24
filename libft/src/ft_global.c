/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:50:59 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:51:00 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_global.h"

t_htbl	ft_get_globals(void)
{
	static t_htnode	*dict[HTSIZE];

	return (dict);
}

int	ft_set_global(const char *key, void *val)
{
	t_htbl	dict;

	dict = ft_get_globals();
	if (!dict)
		return (0);
	return (!!htadd(dict, key, val));
}

void	*ft_get_global(const char *key)
{
	t_htbl	dict;

	dict = ft_get_globals();
	if (!dict)
		return (0);
	return (htget(dict, key));
}

void	ft_delone_global(const char *key, void (*del)(t_htnode *))
{
	t_htbl	dict;

	dict = ft_get_globals();
	if (!dict)
		return ;
	return (htdelone(dict, key, del));
}
