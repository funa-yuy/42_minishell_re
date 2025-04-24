/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:33:01 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:55:49 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  show agument to stdout
 */
int	builtin_echo(char **argv)
{
	bool	opt_n;

	opt_n = (*argv && ft_strcmp(*argv, "-n") == 0);
	while (*argv && ft_strcmp(*argv, "-n") == 0)
		argv++;
	while (*argv)
	{
		ft_putstr_fd(*argv, STDOUT_FILENO);
		if (*(argv + 1))
			ft_putstr_fd(" ", STDOUT_FILENO);
		argv++;
	}
	if (!opt_n)
		ft_putendl_fd("", STDOUT_FILENO);
	return (0);
}
