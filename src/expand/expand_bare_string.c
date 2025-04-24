/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_bare_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:58:54 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:58:55 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: expand_bare_string
 * ----------------------------
 *  read characters from cur_p, and store it on buf_p.
 */
void	expand_bare_string(char **cur_p, char **buf_p)
{
	read_bare_string_m(cur_p, buf_p, (char [4]){'\"', '\'', '$', '\0'}, 4);
}
