/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:00:02 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 11:00:03 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * Do anything before starting shell such as:
 *   setup signal handler
 *   setup function do on exit
 *   ...
 *
 * Returns: false if any unexpected result will happen, otherwise true
 */
bool	init(char **envp)
{
	rl_outstream = stderr;
	set_handlers_for_process();
	ft_atexit(ft_g_mmfree);
	ft_initenv(envp);
	return (true);
}
