/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fset_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:50:53 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:50:54 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_stdio.h"

#ifndef USE_STD_FILE_TYPE

void	ft_fset_fd(t_file *f, int fd)
{
	f->_fd = fd;
}

#else

void	ft_fset_fd(t_file *f, int fd)
{
	(void)f;
	(void)fd;
}

#endif
