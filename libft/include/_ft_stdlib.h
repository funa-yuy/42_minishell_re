/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_stdlib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:48:44 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:48:44 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_STDLIB_H
# define _FT_STDLIB_H

# include <ft_htbl.h>
# include <ft_stdlib.h>
# include <ft_string.h>
# include <stddef.h>
# include <stdlib.h>

t_htbl	*_getenvp(void);
void	_delenv(t_htnode *n);

#endif
