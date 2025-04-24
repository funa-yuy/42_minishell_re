/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   namelen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:59:25 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:59:26 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  get length of name. name as regex is :
 *  	[A-Za-z_][A-Za-z0-9_]*
 */
size_t	namelen(char *str)
{
	size_t	cnt;

	cnt = 0;
	if (!(ft_isalpha(*str) || *str == '_'))
		return (cnt);
	str++;
	cnt++;
	while (ft_isalnum(*str) || *str == '_')
	{
		str++;
		cnt++;
	}
	return (cnt);
}
