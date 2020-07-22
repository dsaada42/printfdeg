/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 17:50:43 by dsaada            #+#    #+#             */
/*   Updated: 2020/07/22 02:12:11 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int	ft_free_val(t_value *val)
{
	free(val);
	return (0);
}

int	ft_parser(t_value **list, const char *str, va_list a_list)
{
	int		i;
	t_value	*new;

	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			if (!(new = ft_string_parser(&str[i])))
				return (0);
			i += new->size;
		}
		else if (str[i] == '%' && str[i + 1] == '%')
		{
			if (!(new = ft_new_value()))
				return (0);
			if (!(new->toprint = ft_strdup("%")))
				return (ft_free_val(new));
			i += 2;
		}
		else if (!(new = ft_parser_value(str, a_list, &i)))
			return (0);
		ft_add_value_back(list, new);
	}
	return (1);
}
