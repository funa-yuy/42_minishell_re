/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:50:50 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:50:51 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_stdio.h"

int	ft_fputs(const char *s, t_file *stream)
{
	int	cnt;

	cnt = 0;
	while (s[cnt] != '\0')
	{
		if (cnt == INT_MAX)
			return (EOF);
		if (ft_fputc(s[cnt], stream) == EOF)
			return (EOF);
		cnt++;
	}
	return (cnt);
}
