/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:53:18 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:53:19 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putabsnbr_fd(int n, int fd)
{
	char	c;

	if (n / 10)
		ft_putabsnbr_fd(n / 10, fd);
	c = '0' + (n % 10) * ((n > 0) * 2 - 1);
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	write(fd, "-", n < 0);
	ft_putabsnbr_fd(n, fd);
}
