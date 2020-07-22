/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 01:07:40 by dsaada            #+#    #+#             */
/*   Updated: 2020/07/22 03:41:29 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printer.h"

int		ft_print_uint_precision(t_value *val)
{
	int i;

	i = 0;
	if ((val->toprint)[0] == '\0' && ((val->dot && val->precision < 0) || (!val->dot)))
	{
		write(1, "0", 1);
		return (1);
	}
	if (val->dot && (int)ft_strlen(val->toprint) < val->precision)
		i += ft_print_zero(val->precision - ft_strlen(val->toprint));
	i += ft_print_chars(val->toprint, ft_strlen(val->toprint));
	return (i);
}

int		ft_print_uint_val(t_value *val)
{
	int	size;
	int nbspaces;
	int i;
	
	i = 0;
	nbspaces = 0;
	if (val->width > (size = ft_max(ft_strlen(val->toprint), val->precision)))
	{
		if (!size && !(val->dot && val->precision == 0))
			size++;
		nbspaces = val->width - size;
	}
	if (val->minus)
	{
		i += ft_print_uint_precision(val);
		i += ft_print_spaces(nbspaces);
	}
	else
	{
		if (val->zero && (val->dot == 0 || val->precision < 0))
			i += ft_print_zero(nbspaces);
		else
			i += ft_print_spaces(nbspaces);
		i += ft_print_uint_precision(val);
	}
	return (i);
}

int		ft_print_int_precision(t_value *val, int sign)
{
	int	size;
	int	i;

	i = 0;
	if (val->precision == 0 && val->dot && ft_strlen(val->toprint) == 1 && (val->toprint)[0] == '0')
	{
		if (val->width == 0)
			return (i);
		if (val->zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		return (i + 1);
	}
	if (sign)
	{
		i++;
		write(1, "-", 1);
		if (val->precision > (size = (ft_strlen(val->toprint) - 1)))
			i += ft_print_zero(val->precision - size);
		i += ft_print_chars(val->toprint + 1, ft_strlen(val->toprint) - 1);
	}
	else
	{
		if (val->precision > (size = ft_strlen(val->toprint)))
			i += ft_print_zero(val->precision - size);
		i += ft_print_chars(val->toprint, ft_strlen(val->toprint));
	}
	return (i);
}

int		ft_print_int_zero(t_value *val, int sign)
{
	int	size;
	int i;

	i = 0;
	if (sign)
	{
		i++;
		write(1, "-", 1);
		if (val->width > (size = ft_strlen(val->toprint)))
			i += ft_print_zero(val->width - size);
		i += ft_print_chars(val->toprint + 1, ft_strlen(val->toprint) - 1);
	}
	else
	{
		if (val->width > (size = ft_strlen(val->toprint)))
			i += ft_print_zero(val->width - size);
		i += ft_print_chars(val->toprint, ft_strlen(val->toprint));
	}
	return (i);
}

int		ft_print_int_val(t_value *val)
{
	int	sign;
	int	size;
	int	nbspaces;
	int i;

	i = 0;
	nbspaces = 0;
	sign = 0;
	if (val->minus || (val->dot && val->precision >= 0))
		val->zero = 0;
	if (val->toprint[0] == '-')
		sign = 1;
	if (val->width
		> (size = ft_max(ft_strlen(val->toprint), val->precision + sign)))
		nbspaces = val->width - size;
	if (val->minus)
	{
		i += ft_print_int_precision(val, sign);
		i += ft_print_spaces(nbspaces);
	}
	else if (!(val->zero))
	{
		i += ft_print_spaces(nbspaces);
		i += ft_print_int_precision(val, sign);
	}
	else
		i += ft_print_int_zero(val, sign);
	return (i);
}
