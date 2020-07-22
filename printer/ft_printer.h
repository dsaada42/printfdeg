/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:59:04 by dsaada            #+#    #+#             */
/*   Updated: 2020/07/22 15:36:49 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTER_H
# define FT_PRINTER_H

# include "../ft_printf.h"

int		ft_printer(t_value *val);
int		ft_print_constant_val(t_value *val);
int		ft_print_int_val(t_value *val);
int		ft_print_uint_val(t_value *val);
int		ft_print_uint_precision(t_value *val);
int		ft_print_ptr_val(t_value *val);
int		ft_print_char_val(t_value *val);
int		ft_print_str_val(t_value *val);
int		ft_print_chars(char *str, int txtsize);
int		ft_print_spaces(int nb);
int		ft_print_zero(int nb);
int		ft_print_int_precision(t_value *val, int sign);
int		ft_print_int_zero(t_value *val, int sign);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		ft_handle_edge_precision(t_value *val, int i);
int		ft_int_printer(t_value *val, int sign, int nbspaces);

#endif
