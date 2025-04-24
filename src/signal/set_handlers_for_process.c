/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_handlers_for_process.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:00:49 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 11:00:50 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  during system processing, catch signal and record it
 */
void	set_handlers_for_process(void)
{
	signal(SIGINT, set_signal);
	signal(SIGQUIT, set_signal);
}
