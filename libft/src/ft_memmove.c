/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:52:57 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:52:58 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*c_dst;
	const unsigned char	*c_src;
	char				sign;
	size_t				cur;

	c_src = (const unsigned char *)src;
	c_dst = (unsigned char *)dst;
	sign = (dst < src) * 2 - 1;
	cur = (sign == -1) * len;
	while (cur != (sign == 1) * len && (dst || src))
	{
		c_dst[cur - (sign == -1)] = c_src[cur - (sign == -1)];
		cur += sign;
	}
	return (dst);
}
