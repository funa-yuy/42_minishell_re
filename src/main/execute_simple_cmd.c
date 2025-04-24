/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:30:10 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:59:59 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * execute simple command
 *
 * const t_simple_cmd: is raw simple command
 * int stdio_fd[2]: are fds to be redirect from stdio
 * int next_in_fd: is fd to be close on child process
 * TODO; bool	execute_simple_cmd(t_simple_cmd *scmd_list, \
 * 				t_execute_session session)
 */
bool	execute_simple_cmd(const t_simple_cmd *scmd_list, int stdio_fd[2],
		int next_in_fd)
{
	int			chpid;
	int			status;

	chpid = fork();
	if (chpid)
	{
		return (chpid != -1);
	}
	set_handlers_default();
	close_fds_no_stdio(&next_in_fd, 1);
	resolve_redirects(stdio_fd, scmd_list->redir);
	if (!scmd_list->ecmds[0])
		ft_exit(0);
	if (is_builtin(scmd_list->ecmds[0]))
		ft_exit(execute_builtin(scmd_list->ecmds));
	status = exec_with_path(scmd_list->ecmds[0], scmd_list->ecmds);
	ft_exit(exec_error_handling((char *)scmd_list->ecmds[0], status, errno));
	return (false);
}
