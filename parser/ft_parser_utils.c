/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 23:48:31 by dsaada            #+#    #+#             */
/*   Updated: 2020/07/22 02:17:36 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "../converter/ft_convert.h"

int		ft_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int		ft_istype(char c)
{
	if (c == 'c' || c == 's' || c == 'p'
			|| c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	else
		return (0);
}

t_value	*ft_string_parser(const char *str)
{
	int		i;
	t_value	*new;

	i = 0;
	if (!(new = ft_new_value()))
		return (NULL);
	while (str[i] && str[i] != '%')
		i++;
	if (!(new->toprint = ft_substr(str, 0, i)))
		return (NULL);
	new->size = ft_strlen(new->toprint);
	return (new);
}

t_value	*ft_free(t_value *val)
{
	free(val);
	return (NULL);
}

t_value	*ft_parser_value(const char *str, va_list a_list, int *i)
{
	t_value	*new;
	char	*res;
	int		ret;

	if (!(new = ft_indicator_parser(&str[*i])))
		return (NULL);
	if ((ret = ft_width_parser(&str[*i], new)) == -1)
		return (ft_free(new));
	if (ret)
	{
		new->width = va_arg(a_list, int);
		if (new->width < 0)
		{
			new->width = -1 * new->width;
			new->minus += 1;
		}
	}
	if (!(ft_dot_parser(&str[*i], new)))
		return (ft_free(new));
	if ((ret = ft_precision_parser(&str[*i], new)) == -1)
		return (ft_free(new));
	if (ret)
		new->precision = va_arg(a_list, int);
	if (!(ft_type_parser(&str[*i], new)))
		return (ft_free(new));
	if (!(res = ft_convert(new, a_list)))
		return (NULL);
	new->toprint = res;
	(*i) += new->size;
	return (new);
}
