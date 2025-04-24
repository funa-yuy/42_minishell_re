/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:57:20 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:57:21 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  return true if arg text is builtin
 */
bool	is_builtin(char *ecmd)
{
	if (ecmd == NULL)
		return (false);
	if (ft_strcmp(ecmd, "cd") == 0)
		return (true);
	if (ft_strcmp(ecmd, "echo") == 0)
		return (true);
	if (ft_strcmp(ecmd, "env") == 0)
		return (true);
	if (ft_strcmp(ecmd, "exit") == 0)
		return (true);
	if (ft_strcmp(ecmd, "export") == 0)
		return (true);
	if (ft_strcmp(ecmd, "pwd") == 0)
		return (true);
	if (ft_strcmp(ecmd, "unset") == 0)
		return (true);
	return (false);
}
