/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:04:20 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 11:00:05 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

volatile unsigned char	g_signal = 0;

int	main(int argc, char **argv, char **envp)
{
	unsigned char	last_status;

	(void)argc;
	(void)argv;
	init(envp);
	while (true)
	{
		last_status = eval_cmd_line();
		set_exit_status(last_status);
		ft_g_mmfree();
	}
	return (0);
}
