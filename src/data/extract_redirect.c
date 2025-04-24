/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:57:38 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:57:38 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: extract_redirect
 * ----------------------------
 *  extract redirect from token_p to redir_p
 *  NOTE: redirect on token_p will be unlinked from list
 */
bool	extract_redirect(t_text_list **token_p, t_redirect **redir_p)
{
	t_redirect	*redir;
	t_text_list	**token_addr;

	*redir_p = NULL;
	token_addr = token_p;
	while (*token_addr)
	{
		if (get_redirect_type((*token_addr)->text) == REDIR_NONE)
			token_addr = &((*token_addr)->next);
		else
		{
			if (!is_valid_redirect_syntax(*token_addr))
				return (false);
			redir = token2redir((*token_addr)->text, (*token_addr)->next->text);
			if (!redir)
				return (false);
			add_redir_list_last(redir_p, redir);
			*token_addr = (*token_addr)->next->next;
		}
	}
	return (true);
}
