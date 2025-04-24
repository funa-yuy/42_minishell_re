/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gmemory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:51:02 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:51:03 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

t_memory_manager	**ft_g_mmget_p(void)
{
	static t_memory_manager	*mm;

	if (mm == NULL)
		mm = ft_mmnew();
	return (&mm);
}

void	*ft_g_mmadd(void *ptr)
{
	t_memory_manager	**mm;

	mm = ft_g_mmget_p();
	if (!mm || !*mm)
		return (0);
	return (ft_mmadd(*mm, ptr));
}

void	*ft_g_mmmalloc(size_t size)
{
	t_memory_manager	**mm;

	mm = ft_g_mmget_p();
	if (!mm || !*mm)
		return (NULL);
	return (ft_mmmalloc(*mm, size));
}

void	*ft_g_mmcalloc(size_t size, size_t cnt)
{
	t_memory_manager	**mm;

	mm = ft_g_mmget_p();
	if (!mm || !*mm)
		return (NULL);
	return (ft_mmcalloc(*mm, size, cnt));
}

void	ft_g_mmfree(void)
{
	t_memory_manager	**mm;

	mm = ft_g_mmget_p();
	if (!mm)
		return ;
	ft_mmfree(*mm);
	*mm = NULL;
}
