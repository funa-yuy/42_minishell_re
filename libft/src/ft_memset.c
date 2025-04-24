/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:53:00 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:53:01 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	ch;
	unsigned char	*c_b;

	ch = (unsigned char)c;
	c_b = (unsigned char *)b;
	while (len)
	{
		c_b[len - 1] = ch;
		len--;
	}
	return (b);
}
