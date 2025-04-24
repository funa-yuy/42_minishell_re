/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exit_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:59:16 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:59:17 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * Get exit status
 */
unsigned char	get_exit_status(void)
{
	unsigned char	*st_ptr;

	st_ptr = get_exit_status_p();
	return (*st_ptr);
}
