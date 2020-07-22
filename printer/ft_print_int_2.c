/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:34:56 by dsaada            #+#    #+#             */
/*   Updated: 2020/07/22 15:35:46 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printer.h"

int		ft_int_printer(t_value *val, int sign, int nbspaces)
{
	int	i;

	i = 0;
	if (val->minus)
	{
		i = ft_print_int_precision(val, sign);
		i += ft_print_spaces(nbspaces);
	}
	else if (!(val->zero))
	{
		i = ft_print_spaces(nbspaces);
		i += ft_print_int_precision(val, sign);
	}
	else
		i = ft_print_int_zero(val, sign);
	return (i);
}
