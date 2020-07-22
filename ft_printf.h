/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 12:01:01 by dsaada            #+#    #+#             */
/*   Updated: 2020/07/22 01:52:22 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct	s_value
{
	int				size;
	int				minus;
	int				zero;
	int				width;
	int				dot;
	int				precision;
	char			type;
	char			*toprint;
	struct s_value	*next;
}				t_value;

void			ft_clear_values(t_value **alst, void(*del)(t_value*));
void			ft_clear_struct(t_value *val);
int				ft_printf(const char *format, ...);
t_value			*ft_new_value(void);
int				ft_printer(t_value *val);
void			ft_add_value_back(t_value **alst, t_value *new);
int				ft_parser(t_value **list, const char *str, va_list a_list);

#endif
