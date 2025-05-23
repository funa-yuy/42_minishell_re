/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:33:15 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:59:49 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * Execute pipeline
 *
 * const char *cmd_line: string to do as a command
 * // TODO: session = init_session();
 * // TODO: env = ENV_CHILD;
 * // TODO: env = ENV_PARENT;
 * // TODO: del_pipe(pipe);
 * // TODO: ->free_simple_cmds((t_simple_cmd *)scmd_list);
 */
unsigned char	eval_pipe(const t_simple_cmd *scmd_list)
{
	t_simple_cmd		*cur;
	int					stdio_fd[2];
	int					next_in_fd;

	stdio_fd[0] = STDIN_FILENO;
	stdio_fd[1] = STDOUT_FILENO;
	next_in_fd = STDIN_FILENO;
	cur = (t_simple_cmd *)scmd_list;
	if (cur && cur->next == NULL && is_builtin(cur->ecmds[0]))
		return (execute_on_current_env(cur->ecmds, cur->redir));
	while (cur)
	{
		if (!iterate_pipefd(cur == scmd_list, cur->next == NULL, &stdio_fd, \
			&next_in_fd))
		{
			close_fds_no_stdio(stdio_fd, 2);
			close_fds_no_stdio(&next_in_fd, 1);
			break ;
		}
		execute_simple_cmd(cur, stdio_fd, next_in_fd);
		cur = cur->next;
	}
	close_fds_no_stdio((int [3]){stdio_fd[0], stdio_fd[1], next_in_fd}, 3);
	return (wait_status());
}
