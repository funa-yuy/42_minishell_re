/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at_sigint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:00:38 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 11:00:39 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  do when catch sigint on prompt
 */
void	at_sigint(int signal)
{
	(void)signal;
	g_signal = signal;
	set_exit_status(signal + 128);
	flush_prompt();
}
