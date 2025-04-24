/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:52:54 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:52:55 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*c_dst;
	const unsigned char	*c_src;

	c_src = (const unsigned char *)src;
	c_dst = (unsigned char *)dst;
	while (n && (dst || src))
	{
		c_dst[n - 1] = c_src[n - 1];
		n--;
	}
	return (dst);
}
