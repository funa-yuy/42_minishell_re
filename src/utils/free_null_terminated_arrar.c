/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_null_terminated_arrar.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:01:08 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 11:01:09 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  free null-terminated-array.
 */
void	free_null_terminated_array(void **arr)
{
	void	**bak;

	if (arr == NULL)
		return ;
	bak = arr;
	while (*arr != NULL)
	{
		free(*arr);
		arr++;
	}
	free(bak);
}
