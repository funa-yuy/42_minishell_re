/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:53:30 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:53:31 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_stdio.h"

#ifndef USE_STD_FILE_TYPE

t_file	*ft_stdin(void)
{
	static unsigned int	has_build;
	static t_file		f;

	if (!has_build)
	{
		ft_fset_fd(&f, STDIN_FILENO);
		has_build = 1;
	}
	return (&f);
}

#else

t_file	*ft_stdin(void)
{
	return (stdin);
}

#endif
