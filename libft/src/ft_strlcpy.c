/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:54:04 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:54:05 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	c;

	src_len = ft_strlen(src);
	if (src_len + 1 < dstsize)
		c = src_len + 1;
	else
		c = dstsize;
	if (c)
	{
		ft_memcpy(dst, src, c - 1);
		dst[c - 1] = '\0';
	}
	return (src_len);
}
