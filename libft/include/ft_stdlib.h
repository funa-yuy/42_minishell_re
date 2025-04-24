/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:49:25 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/24 10:49:26 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H
# ifndef FT_MAX_F_ATEXIT
#  define FT_MAX_F_ATEXIT 32
# endif

# include <stddef.h>

int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(int n);
void	ft_exit(int status);
int		ft_atexit(void *function);
char	*ft_getenv(const char *name);
int		ft_setenv(const char *name, const char *value, int overwrite);
int		ft_putenv(char *string);
int		ft_unsetenv(const char *name);
int		ft_initenv(char **envp);
void	ft_clearenv(void);
char	**ft_getenvp(void);

#endif
