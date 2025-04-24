/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_simple_cmds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:32:33 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:57:58 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * free memory of simple command
 */
void	free_simple_cmds(t_simple_cmd *scmd_list)
{
	t_simple_cmd	*tmp;

	while (scmd_list)
	{
		tmp = scmd_list;
		scmd_list = scmd_list->next;
		free(tmp);
	}
}
