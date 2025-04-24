/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:50:41 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:50:45 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_stdio.h"

int	ft_fprintf(t_file *s, const char *format, ...)
{
	va_list	args;
	int		n;

	va_start(args, format);
	n = ft_vfprintf(s, format, args);
	va_end(args);
	return (n);
}
