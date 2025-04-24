/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:49:50 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:49:51 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_ctype.h"

int	ft_atoi(const char *str)
{
	char	sign;
	long	num;
	long	limit;

	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	sign = 1 - 2 * (*str == '-');
	str += (*str == '+' || *str == '-');
	limit = LONG_MIN + (sign + 1) / 2;
	num = 0;
	while (ft_isdigit(*str))
	{
		if (sign * -1 * num < (limit + *str - '0') / 10)
			return ((sign + 1) * -1 / 2);
		num = num * 10 + sign * (*str - '0');
		str++;
	}
	return (num & -1);
}

int	ft_atoi_p(const char **str)
{
	char	sign;
	long	num;
	long	limit;

	while ((**str >= 9 && **str <= 13) || **str == ' ')
		++*str;
	sign = 1 - 2 * (**str == '-');
	*str += (**str == '+' || **str == '-');
	limit = LONG_MIN + (sign + 1) / 2;
	num = 0;
	while (ft_isdigit(**str))
	{
		if (sign * -1 * num < (limit + **str - '0') / 10)
			return ((sign + 1) * -1 / 2);
		num = num * 10 + sign * (**str - '0');
		++*str;
	}
	return (num & -1);
}
