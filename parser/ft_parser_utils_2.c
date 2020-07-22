/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 17:10:34 by dsaada            #+#    #+#             */
/*   Updated: 2020/07/16 19:43:22 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

t_value	*ft_indicator_parser(const char *str)
{
	int		i;
	t_value	*elem;

	if (*str != '%')
		return (NULL);
	if (!(elem = ft_new_value()))
		return (NULL);
	i = 1;
	while (str[i] == '-' || str[i] == '0')
	{
		if (str[i] == '-')
			elem->minus += 1;
		if (str[i] == '0')
			elem->zero += 1;
		i++;
	}
	elem->size += i;
	return (elem);
}

int		ft_width_parser(const char *str, t_value *val)
{
	int	i;
	int	width;

	width = 0;
	i = val->size;
	if (str[i] == '*')
	{
		if (str[i + 1] == '.' || ft_istype(str[i + 1]))
		{
			val->size += 1;
			return (1);
		}
		else
			return (-1);
	}
	while (ft_isnum(str[i]))
	{
		width = 10 * width + str[i] - 48;
		i++;
	}
	val->width = width;
	val->size = i;
	return (0);
}

int		ft_dot_parser(const char *str, t_value *val)
{
	int	i;

	i = val->size;
	if (str[i] == '.')
	{
		if (str[i + 1] == '*' || ft_isnum(str[i + 1]) || ft_istype(str[i + 1]))
		{
			val->dot += 1;
			val->size += 1;
		}
		else
			return (0);
	}
	return (1);
}

int		ft_precision_parser(const char *str, t_value *val)
{
	int	i;
	int	precision;

	precision = 0;
	i = val->size;
	if (str[i] == '*')
	{
		if (ft_istype(str[i + 1]))
		{
			val->size += 1;
			return (1);
		}
		else
			return (-1);
	}
	while (ft_isnum(str[i]))
	{
		precision = precision * 10 + str[i] - 48;
		i++;
	}
	val->precision = precision;
	val->size = i;
	return (0);
}

int		ft_type_parser(const char *str, t_value *val)
{
	int i;

	i = val->size;
	if (ft_istype(str[i]))
	{
		val->type = str[i];
		val->size += 1;
		return (1);
	}
	return (-1);
}
