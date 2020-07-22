/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 20:02:52 by dsaada            #+#    #+#             */
/*   Updated: 2020/07/22 05:37:22 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printer.h"

int		ft_printer(t_value *val)
{
	int	i;

	i = 0;
	if (val->type == 'c')
		i += ft_print_char_val(val);
	else if (val->type == 's')
		i += ft_print_str_val(val);
	else if (val->type == 'p')
		i += ft_print_ptr_val(val);
	else if (val->type == 'd' || val->type == 'i')
		i += ft_print_int_val(val);
	else if (val->type == 'u')
		i += ft_print_uint_val(val);
	else if (val->type == 'x' || val->type == 'X')
		i += ft_print_uint_val(val);
	else if (val->type == 0)
		i += ft_print_constant_val(val);
	return (i);
}

int		ft_print_constant_val(t_value *val)
{
	return (ft_print_chars(val->toprint, ft_strlen(val->toprint)));
}

int		ft_print_str_val(t_value *val)
{
	int	txtsize;
	int	nbspaces;
	int i;

	i = 0;
	nbspaces = 0;
	if (!val->dot || val->precision < 0)
		txtsize = ft_strlen(val->toprint);
	else
		txtsize = ft_min(val->precision, ft_strlen(val->toprint));
	if (val->width > txtsize)
		nbspaces = val->width - txtsize;
	if (val->minus)
	{
		i += ft_print_chars(val->toprint, txtsize);
		i += ft_print_spaces(nbspaces);
	}
	else
	{
		i += ft_print_spaces(nbspaces);
		i += ft_print_chars(val->toprint, txtsize);
	}
	return (i);
}

int		ft_print_char_val(t_value *val)
{
	int	nbspaces;
	int	i;

	i = 0;
	nbspaces = 0;
	if (val->width > 1)
		nbspaces = val->width - 1;
	if (val->minus)
	{
		write(1, &(val->toprint[0]), 1);
		i++;
		i += ft_print_spaces(nbspaces);
	}
	else
	{
		i += ft_print_spaces(nbspaces);
		write(1, &(val->toprint[0]), 1);
		i++;
	}
	return (i);
}

int		ft_print_chars(char *str, int txtsize)
{
	int	i;

	i = -1;
	while (str[++i] && i < txtsize)
		write(1, &str[i], 1);
	return (i);
}
