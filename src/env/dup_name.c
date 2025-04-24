/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 02:02:28 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:58:29 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: dup_name
 * ----------------------------
 *  get name sring from cur
 *  return value should be free
 */
char	*dup_name(char *cur)
{
	size_t	len;
	char	*str;

	len = namelen(cur);
	str = ft_g_mmadd(ft_strndup(cur, len));
	if (!str)
	{
		set_error_type(ERR_SYSCALL);
		print_errmsg_with_str(EM_SYSCALL, NULL);
		return (NULL);
	}
	return (str);
}
