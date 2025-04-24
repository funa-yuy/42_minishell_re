/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:53:50 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:53:50 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdint.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	n_s1;
	size_t	n_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	n_s1 = ft_strlen(s1);
	n_s2 = ft_strlen(s2);
	if (n_s1 >= SIZE_MAX - n_s1)
		return (NULL);
	p = malloc(n_s1 + n_s2 + 1);
	if (p == NULL)
		return (NULL);
	ft_memmove(p, s1, n_s1);
	ft_memmove(p + n_s1, s2, n_s2);
	p[n_s1 + n_s2] = '\0';
	return (p);
}
