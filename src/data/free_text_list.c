/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_text_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:27:06 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:58:01 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * free memory of text_list
 */
void	free_text_list(t_text_list *scmds)
{
	t_text_list	*tmp;

	while (scmds)
	{
		tmp = scmds->next;
		if (scmds->text)
			free(scmds->text);
		free(scmds);
		scmds = tmp;
	}
}
