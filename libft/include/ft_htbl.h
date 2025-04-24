/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htbl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:49:09 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:49:10 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HTBL_H
# define FT_HTBL_H
# include <stdint.h>
# define HTSIZE UINT8_MAX

typedef struct s_htnode	t_htnode;
typedef t_htnode		**t_htbl;

struct					s_htnode
{
	const char			*key;
	void				*val;
	t_htnode			*next;
};

uint8_t					hash(const char *key);
t_htbl					htnew(void);
t_htbl					htadd(t_htbl ht, const char *key, void *val);
t_htbl					htget(t_htbl ht, const char *key);
void					htdelone(t_htbl ht, const char *key,
							void (*del)(t_htnode *));
void					htclear(t_htbl ht, void (*del)(t_htnode *));
void					htiter(t_htbl ht, void (*f)(t_htnode *, void *),
							void *p);

#endif
