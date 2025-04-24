/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:54:51 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:54:52 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_stdio.h"

void	init_print_d(t_format *f, t_print *p)
{
	p->sign = get_sign(f);
	if (p->sign == '-')
		f->u_val.nbr *= -1;
	p->p = (const unsigned char *)ft_ui64toa_base(
			(uint64_t)(uint32_t)f->u_val.nbr,
			"0123456789",
			10);
	ft_mmadd(vfpmm(), (void *)p->p);
	p->inner_len = ft_strlen((const char *)p->p);
	if (!f->u_val.nbr && f->s_flag.period && !f->prec)
		p->inner_len = 0;
	set_prec(p, f);
	set_f_width(p, f);
}

void	init_print_u(t_format *f, t_print *p)
{
	p->p = (const unsigned char *)ft_ui64toa_base(
			(uint64_t)(uint32_t)f->u_val.nbr,
			"0123456789",
			10);
	ft_mmadd(vfpmm(), (void *)p->p);
	p->inner_len = ft_strlen((const char *)p->p);
	if (!f->u_val.nbr && f->s_flag.period && !f->prec)
		p->inner_len = 0;
	set_prec(p, f);
	set_f_width(p, f);
}

void	init_print_x(t_format *f, t_print *p)
{
	if (f->s_flag.num)
		p->prefix = "0x";
	p->p = (const unsigned char *)ft_ui64toa_base(
			(uint64_t)(uint32_t)f->u_val.nbr,
			"0123456789abcdef",
			16);
	ft_mmadd(vfpmm(), (void *)p->p);
	p->inner_len = ft_strlen((const char *)p->p);
	if (!f->u_val.nbr && f->s_flag.period && !f->prec)
		p->inner_len = 0;
	set_prec(p, f);
	set_f_width(p, f);
}

void	init_print_xx(t_format *f, t_print *p)
{
	if (f->s_flag.num)
		p->prefix = "0X";
	p->p = (const unsigned char *)ft_ui64toa_base(
			(uint64_t)(uint32_t)f->u_val.nbr,
			"0123456789ABCDEF",
			16);
	ft_mmadd(vfpmm(), (void *)p->p);
	p->inner_len = ft_strlen((const char *)p->p);
	if (!f->u_val.nbr && f->s_flag.period && !f->prec)
		p->inner_len = 0;
	set_prec(p, f);
	set_f_width(p, f);
}

void	init_print_p(t_format *f, t_print *p)
{
	if (!f->u_val.ptr)
		p->p = (const unsigned char *)"(nil)";
	else
	{
		p->prefix = "0x";
		p->p = (const unsigned char *)ft_ui64toa_base(
				(uint64_t)f->u_val.ptr,
				"0123456789abcdef",
				16);
		ft_mmadd(vfpmm(), (void *)p->p);
	}
	p->inner_len = ft_strlen((const char *)p->p);
	set_prec(p, f);
	set_f_width(p, f);
}
