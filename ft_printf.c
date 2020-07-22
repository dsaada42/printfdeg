/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 12:20:39 by dsaada            #+#    #+#             */
/*   Updated: 2020/07/22 16:05:05 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list a_list;
	t_value	*list;
	int		ret;

	va_start(a_list, format);
	list = NULL;
	if (!(ft_parser(&list, format, a_list)))
	{
		if (list)
			ft_clear_values(&list, ft_clear_struct);
		return (0);
	}
	ret = ft_print_list(&list);
	ft_clear_values(&list, ft_clear_struct);
	return (ret);
}
