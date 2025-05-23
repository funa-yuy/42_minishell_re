/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:54:48 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:54:48 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_stdio.h"

void	init_print_percent(t_format *f, t_print *p)
{
	p->p = (const unsigned char *)"%";
	p->inner_len = 1;
	(void)f;
}

void	init_print_s(t_format *f, t_print *p)
{
	f->s_flag.zero = 0;
	if (!f->u_val.ptr && !((size_t)f->s_flag.period && f->prec < 6))
		f->u_val.ptr = "(null)";
	if (!f->u_val.ptr)
		p->inner_len = 0;
	else
		p->inner_len = ft_strlen(f->u_val.ptr);
	if (f->s_flag.period && f->prec < p->inner_len)
		p->inner_len = f->prec;
	p->p = f->u_val.ptr;
	set_f_width(p, f);
}

void	init_print_c(t_format *f, t_print *p)
{
	f->s_flag.zero = 0;
	p->p = (const unsigned char *)&f->u_val.nbr;
	p->inner_len = 1;
	set_f_width(p, f);
}
