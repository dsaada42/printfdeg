/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:30:10 by dsaada            #+#    #+#             */
/*   Updated: 2020/07/22 15:11:27 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printer.h"

int		ft_print_ptr_null(t_value *val)
{
	if (ft_strlen(val->toprint) == 2)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		return (0);
}

int		ft_print_ptr_val(t_value *val)
{
	int	nbspaces;
	int i;

	i = 0;
	nbspaces = 0;
	if (val->width > (int)ft_strlen(val->toprint))
		nbspaces = val->width - ft_strlen(val->toprint);
	if (ft_strlen(val->toprint) == 2)
		nbspaces--;
	if (val->minus)
	{
		i += ft_print_chars(val->toprint, ft_strlen(val->toprint));
		i += ft_print_ptr_null(val);
		i += ft_print_spaces(nbspaces);
	}
	else
	{
		i += ft_print_spaces(nbspaces);
		i += ft_print_chars(val->toprint, ft_strlen(val->toprint));
		i += ft_print_ptr_null(val);
	}
	return (i);
}
