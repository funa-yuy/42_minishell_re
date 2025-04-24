/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:49:05 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:49:06 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GLOBAL_H
# define FT_GLOBAL_H

# include "ft_htbl.h"
# include "ft_memory.h"

t_htbl	ft_get_globals(void);
int		ft_set_global(const char *key, void *val);
void	*ft_get_global(const char *key);
void	ft_delone_global(const char *key, void (*del)(t_htnode *));

#endif
