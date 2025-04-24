/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:50:01 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:50:02 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <_ft_stdlib.h>

t_htbl	*_getenvp(void)
{
	static t_htbl	p;

	if (!p)
		p = htnew();
	return (&p);
}

void	_delenv(t_htnode *n)
{
	free((void *)n->key);
	free((void *)n->val);
	free((void *)n);
}

int	ft_initenv(char **envp)
{
	if (envp == NULL)
		return (-1);
	while (*envp)
	{
		if (ft_putenv(*envp) == -1)
			return (-1);
		envp++;
	}
	ft_atexit(ft_clearenv);
	return (0);
}

void	ft_clearenv(void)
{
	t_htbl	*p;

	p = _getenvp();
	if (p == NULL)
		return ;
	htclear(*p, _delenv);
	*p = NULL;
}
