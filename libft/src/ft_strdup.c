/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:53:42 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:53:43 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	return (ft_strndup(s1, ft_strlen(s1)));
}

char	*ft_strndup(const char *s1, size_t size)
{
	char	*p;

	p = malloc(size + 1);
	if (p == NULL)
		return (NULL);
	ft_memcpy(p, s1, size);
	ft_memset(p + size, 0, 1);
	return (p);
}
