/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_pipefd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:00:08 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 11:00:08 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * Repeat set/unset fds use on next simple command as stdio
 *
 * bool is_first: tells the command execute next is first or not
 * bool is_last: tells the command execute next is lst or not
 * int (*stdio_fd)[2]: pointer to store fds of stdio on next command
 * int *next_in_fd: pointer to store pipe_fd[0] for next iteration
 *
 * Returns: false if fail to create pipe, otherwise true
 */
bool	iterate_pipefd(bool is_first, bool is_last, int (*stdio)[2],
		int *next_in)
{
	int	pp_fd[2];

	if (is_first && !is_last)
	{
		if (pipe(pp_fd))
			return (false);
		ft_memcpy(*stdio, (int [2]){STDIN_FILENO, pp_fd[1]}, sizeof(int [2]));
		*next_in = pp_fd[0];
		return (true);
	}
	if (is_last)
	{
		close_fds_no_stdio(*stdio, 2);
		ft_memcpy(stdio, (int [2]){*next_in, STDOUT_FILENO}, sizeof(int [2]));
		*next_in = STDIN_FILENO;
		return (true);
	}
	if (pipe(pp_fd))
		return (false);
	close_fds_no_stdio(*stdio, 2);
	ft_memcpy(stdio, (int [2]){*next_in, pp_fd[1]}, sizeof(int [2]));
	*next_in = pp_fd[0];
	return (true);
}
