/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:01:15 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 11:01:16 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  (immutable) returns string s1 with s2_len chars head of s2.
 *  if s1 is null, this works as strndup(s2, s2_len).
 */
char	*ft_strnjoin(char *s1, char *s2, size_t s2_len)
{
	char	*joined;
	size_t	s1_len;

	s1_len = 0;
	if (s1 != NULL)
		s1_len = ft_strlen(s1);
	joined = ft_g_mmmalloc(sizeof(char) * (s1_len + s2_len + 1));
	if (joined == NULL)
		return (NULL);
	ft_memcpy(joined, s1, s1_len);
	ft_memcpy(joined + s1_len, s2, s2_len);
	joined[s1_len + s2_len] = '\0';
	return (joined);
}
