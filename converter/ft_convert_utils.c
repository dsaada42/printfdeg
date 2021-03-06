/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:44:19 by dsaada            #+#    #+#             */
/*   Updated: 2020/07/22 16:07:25 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_convert.h"

int		ft_count_hexa(unsigned int nb)
{
	int cpt;

	cpt = 0;
	while (nb)
	{
		nb = nb / 16;
		cpt++;
	}
	return (cpt);
}

int		ft_count_hexa_ptr(unsigned long int nb)
{
	int cpt;

	cpt = 0;
	while (nb)
	{
		nb = nb / 16;
		cpt++;
	}
	return (cpt);
}

char	*ft_convert_str(char *str)
{
	if (!str)
		return (ft_strdup("(null)"));
	else
		return (ft_strdup(str));
}
