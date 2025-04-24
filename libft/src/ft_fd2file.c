/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd2file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:50:23 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:50:24 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_stdio.h"

t_file	*ft_fd2file(int fd)
{
	t_file	*f;

	if (fd == 0)
		return (ft_stdin());
	if (fd == 1)
		return (ft_stdout());
	if (fd == 2)
		return (ft_stderr());
	f = ft_filenew();
	if (!f)
		return (NULL);
	ft_fset_fd(f, fd);
	return (f);
}
