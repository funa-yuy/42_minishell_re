/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwrite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:50:56 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:50:57 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

size_t	ft_fwrite(const void *ptr, size_t size, size_t nitems, t_file *stream)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < nitems)
	{
		while (j < size)
		{
			if (ft_fputc(((unsigned char *)ptr)[size * i + j], stream) == EOF)
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
