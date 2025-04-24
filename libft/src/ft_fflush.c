/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fflush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:50:28 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:50:29 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_stdio.h"

#ifndef USE_STD_FILE_TYPE

int	ft_fflush(t_file *stream)
{
	(void)stream;
	return (0);
}

#else

int	ft_fflush(t_file *stream)
{
	return (fflush(stream));
}

#endif
