/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_handlers_for_prompt.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:00:55 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 11:00:56 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  during waiting user input, reflesh prompt on SIGINT
 */
void	set_handlers_for_prompt(void)
{
	signal(SIGINT, at_sigint);
	signal(SIGQUIT, SIG_IGN);
}
