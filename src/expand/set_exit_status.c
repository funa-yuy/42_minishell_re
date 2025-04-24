/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_exit_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:59:42 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:59:42 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * Set exit status use as $?
 *
 * unsigned char st: exit status
 */
void	set_exit_status(unsigned char st)
{
	unsigned char	*st_ptr;

	st_ptr = get_exit_status_p();
	*st_ptr = st;
}
