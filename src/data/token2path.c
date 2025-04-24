/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token2path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:14:37 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:58:24 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: token2path
 * ----------------------------
 * expand token to file path
 */
char	*token2path(char *token)
{
	char	**expanded;

	expanded = expand_single_token(token);
	if (expanded == NULL)
	{
		print_errmsg_with_str(EM_SYSCALL, NULL);
		ft_exit(1);
	}
	if (null_terminated_array_len((void **)expanded) != 1)
	{
		set_error_type(ERR_AMBRDIR);
		print_errmsg_with_str(EM_AMBRDIR, token);
		return (NULL);
	}
	return (expanded[0]);
}
