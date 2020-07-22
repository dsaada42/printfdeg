/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 17:09:29 by dsaada            #+#    #+#             */
/*   Updated: 2020/07/16 18:12:43 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include "../ft_printf.h"

int		ft_isnum(char c);
int		ft_istype(char c);
t_value	*ft_indicator_parser(const char *str);
int		ft_width_parser(const char *str, t_value *val);
int		ft_dot_parser(const char *str, t_value *val);
int		ft_precision_parser(const char *str, t_value *val);
int		ft_type_parser(const char *str, t_value *val);
t_value	*ft_string_parser(const char *str);
int		ft_parser(t_value **list, const char *str, va_list a_list);
t_value	*ft_parser_value(const char *str, va_list a_list, int *i);

#endif
