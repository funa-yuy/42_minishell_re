/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_single_quote.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:59:08 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:59:09 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: expand_single_quote
 * ----------------------------
 *  read string within single quote and storre it on buf_p
 */
void	expand_single_quote(char **cur_p, char **buf_p)
{
	*cur_p += 1;
	read_bare_string_m(cur_p, buf_p, "\'", 1);
	*cur_p += 1;
}
