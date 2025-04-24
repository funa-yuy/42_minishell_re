/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fileno.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:50:35 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:50:36 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_stdio.h"

#ifdef USE_STD_FILE_TYPE

int	ft_fileno(t_file *stream)
{
	return (fileno(stream));
}

#else

int	ft_fileno(t_file *stream)
{
	return (stream->_fd);
}

#endif
