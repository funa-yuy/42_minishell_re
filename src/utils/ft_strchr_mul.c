/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_mul.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:01:12 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 11:01:13 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  returns place where character in $targets appears first on s.
 */
char	*ft_strchr_mul(const char *s, char *targets, size_t target_len)
{
	size_t	i;

	while (true)
	{
		i = 0;
		while (i < target_len)
		{
			if (*s == targets[i])
				return ((char *)s);
			i++;
		}
		if (*s == '\0')
			return (NULL);
		s++;
	}
}
