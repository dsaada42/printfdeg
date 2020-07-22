/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 20:09:33 by dsaada            #+#    #+#             */
/*   Updated: 2020/07/22 15:26:27 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printer.h"

int		ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int		ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int		ft_print_zero(int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		write(1, "0", 1);
		i++;
	}
	return (i);
}

int		ft_print_spaces(int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int		ft_handle_edge_precision(t_value *val, int i)
{
	if (val->width == 0)
		return (i);
	if (val->zero)
		write(1, "0", 1);
	else
		write(1, " ", 1);
	return (i + 1);
}
