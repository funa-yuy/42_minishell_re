/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_identifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:58:37 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:58:37 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  check if is the given string valid as identifier
 */
bool	is_valid_identifier(char *string)
{
	if (string == NULL)
		return (false);
	if (!ft_isalpha(*string) && *string != '_')
		return (false);
	string++;
	while (*string)
	{
		if (!ft_isalnum(*string) && *string != '_')
			return (false);
		string++;
	}
	return (true);
}
