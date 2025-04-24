/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:56:37 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:57:13 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: builtin_unset
 * ----------------------------
 *  unset environment varibales
 */
int	builtin_unset(char **argv)
{
	size_t	i;

	i = 0;
	while (argv[i])
	{
		ft_unsetenv(argv[i]);
		i++;
	}
	return (0);
}
