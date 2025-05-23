/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_redirects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:27:06 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:57:53 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * free memory of redirects
 */
void	free_redirects(t_redirect *redir)
{
	t_redirect	*tmp;

	while (redir != NULL)
	{
		free((char *)redir->path);
		tmp = redir;
		redir = redir->next;
		free(tmp);
	}
}
