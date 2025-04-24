/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:50:47 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:50:48 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_stdio.h"

#ifndef USE_STD_FILE_TYPE

int	ft_fputc(int c, t_file *stream)
{
	if (write(ft_fileno(stream), &c, 1) == -1)
		return (EOF);
	return (c);
}

#else

int	ft_fputc(int c, t_file *stream)
{
	return (fputc(c, stream));
}

#endif
