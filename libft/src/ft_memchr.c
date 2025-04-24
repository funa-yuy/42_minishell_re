/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:52:47 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:52:47 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*c_s;

	c_s = (unsigned char *)s;
	if (n && *c_s == (unsigned char)c)
		return ((void *)s);
	if (n)
		return (ft_memchr((const void *)(c_s + 1), c, n - 1));
	return (NULL);
}
