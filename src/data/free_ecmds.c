/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ecmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:26:32 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:57:48 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * free memory of ecmds
 */
void	free_ecmds(char **ecmds)
{
	int	i;

	i = 0;
	if (ecmds == NULL)
		return ;
	while (ecmds[i])
	{
		free(ecmds[i]);
		i++;
	}
	free(ecmds);
}
