/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:54:25 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:54:26 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

static size_t	strlen_pref(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == NULL)
			break ;
		i++;
	}
	return (i);
}

static size_t	strlen_suf(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		if (ft_strchr(set, s1[len - 1 - i]) == NULL)
			break ;
		i++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	n_pref;
	size_t	n_p;
	size_t	n_s1;

	if (s1 == NULL || set == NULL)
		return (NULL);
	n_pref = strlen_pref(s1, set);
	n_s1 = ft_strlen(s1);
	n_p = (n_pref != n_s1) * (n_s1 - n_pref - strlen_suf(s1, set));
	p = ft_substr(s1, n_pref, n_p);
	return (p);
}
