/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:54:08 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:54:09 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	const char	*t;

	t = s;
	while (*t)
		t++;
	return (t - s);
}

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t	cnt;

	cnt = 0;
	while (cnt < maxlen && s[cnt])
		cnt++;
	return (cnt);
}
