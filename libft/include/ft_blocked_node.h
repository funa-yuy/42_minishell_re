/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blocked_node.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:48:58 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:48:59 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BLOCKED_NODE_H
# define FT_BLOCKED_NODE_H
# define BN_STORE_MAX 256

# include <stdlib.h>

typedef struct s_blocked_node	t_blocked_node;

struct							s_blocked_node
{
	void						*p[BN_STORE_MAX];
	size_t						cnt;
	t_blocked_node				*next;
};

t_blocked_node					*ft_bnnew(void);
int								ft_bnadd(t_blocked_node *bn, void *ptr);
void							ft_bnfree_shallow(t_blocked_node *bn);

#endif
