/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:53:58 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:53:59 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	cpy_len;

	dst_len = ft_strnlen(dst, dstsize);
	src_len = ft_strlen(src);
	if (dst_len >= dstsize)
		return (src_len + dstsize);
	if (dstsize > dst_len + src_len)
		cpy_len = src_len;
	else
		cpy_len = dstsize - dst_len - 1;
	ft_memmove(dst + dst_len, src, cpy_len);
	dst[dst_len + cpy_len] = '\0';
	return (src_len + dst_len);
}
