/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds_no_stdio.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:03:26 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 11:03:27 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * Close file descripters safely, this means not to close fd if it is stdio
 *
 * int fds: top pointer of file descriptors array
 * size_t size: array size of fds
 */
void	close_fds_no_stdio(int *fds, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (fds[i] == STDIN_FILENO
			|| fds[i] == STDOUT_FILENO
			|| fds[i] == STDERR_FILENO)
			;
		else
			close(fds[i]);
		i++;
	}
}
