/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:14:53 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:58:50 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  (mutable) append string($orig) on end of $store.
 */
void	append_str(char ***store, char *orig)
{
	size_t	len;
	char	**tmp;
	char	*dup;

	len = null_terminated_array_len((void **)*store);
	tmp = ft_g_mmmalloc(sizeof(char *) * (len + 2));
	if (tmp == NULL)
	{
		set_error_type(ERR_SYSCALL);
		print_errmsg_with_str(EM_SYSCALL, NULL);
		*store = NULL;
		return ;
	}
	ft_memcpy(tmp, *store, sizeof(char *) * len);
	dup = ft_g_mmadd(ft_strdup(orig));
	if (dup == NULL)
	{
		set_error_type(ERR_SYSCALL);
		print_errmsg_with_str(EM_SYSCALL, NULL);
		*store = NULL;
		return ;
	}
	tmp[len] = dup;
	tmp[len + 1] = NULL;
	*store = tmp;
}
