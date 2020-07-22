/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 15:25:02 by dsaada            #+#    #+#             */
/*   Updated: 2020/07/22 05:19:09 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_convert.h"

char	*ft_convert_char(char c)
{
	char	*str;

	str = NULL;
	if (!(str = malloc(sizeof(char) * 2)))
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

char	*ft_convert_uint(unsigned int nb)
{
	int				cpt;
	char			*res;
	unsigned int	n;

	res = NULL;
	n = nb;
	cpt = 0;
	while (n)
	{
		n = n / 10;
		cpt++;
	}
	if (!(res = malloc(sizeof(char) * (cpt + 1))))
		return (NULL);
	res[cpt] = '\0';
	while (nb)
	{
		res[cpt - 1] = (nb % 10) + 48;
		nb = nb / 10;
		cpt--;
	}
	return (res);
}

char	*ft_convert_hexa(int select, unsigned int nb)
{
	char			*str;
	int				cpt;

	cpt = ft_count_hexa(nb);
	if (!(str = malloc(sizeof(char) * (cpt + 1))))
		return (NULL);
	str[cpt] = '\0';
	while (nb)
	{
		if ((nb % 16) < 10)
			str[cpt - 1] = (nb % 16) + 48;
		else if (select == 0)
			str[cpt - 1] = (nb % 16) - 10 + 'a';
		else
			str[cpt - 1] = (nb % 16) - 10 + 'A';
		nb = nb / 16;
		cpt--;
	}
	return (str);
}

char	*ft_convert_ptr(void *ptr)
{
	unsigned long int	n;
	char				*str;
	int					cpt;

	n = (unsigned long int)ptr;
	cpt = ft_count_hexa_ptr(n);
	cpt += 2;
	if (!(str = malloc(sizeof(char) * (cpt + 1))))
		return (NULL);
	str[0] = '0';
	str[1] = 'x';
	str[cpt] = '\0';
	while (n)
	{
		if ((n % 16) < 10)
			str[cpt - 1] = (n % 16) + 48;
		else
			str[cpt - 1] = (n % 16) - 10 + 'a';
		n = n / 16;
		cpt--;
	}
	return (str);
}

char	*ft_convert(t_value *val, va_list a_list)
{
	char *str;

	str = NULL;
	if (val->type == 'i' || val->type == 'd')
		str = ft_itoa(va_arg(a_list, int));
	else if (val->type == 'c')
		str = ft_convert_char(va_arg(a_list, int));
	else if (val->type == 's')
	{
		if (!(str = va_arg(a_list, char*)))
			str = ft_strdup("(null)");
	}
	else if (val->type == 'p')
		str = ft_convert_ptr(va_arg(a_list, void*));
	else if (val->type == 'x')
		str = ft_convert_hexa(0, va_arg(a_list, unsigned int));
	else if (val->type == 'X')
		str = ft_convert_hexa(1, va_arg(a_list, unsigned int));
	else if (val->type == 'u')
		str = ft_convert_uint(va_arg(a_list, unsigned int));
	return (str);
}
