/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:39:40 by dsaada            #+#    #+#             */
/*   Updated: 2020/07/22 16:06:36 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_value	*ft_new_value(void)
{
	t_value	*new;

	if (!(new = malloc(sizeof(t_value))))
		return (NULL);
	new->toprint = NULL;
	new->size = 0;
	new->minus = 0;
	new->zero = 0;
	new->width = 0;
	new->dot = 0;
	new->precision = 0;
	new->type = 0;
	new->next = NULL;
	return (new);
}

void	ft_add_value_back(t_value **alst, t_value *new)
{
	t_value	*current;

	if (new != NULL)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			current = *alst;
			while (current->next != NULL)
				current = current->next;
			current->next = new;
		}
	}
}

int		ft_print_list(t_value **list)
{
	t_value	*current;
	int		i;

	i = 0;
	current = *list;
	while (current != NULL)
	{
		i += ft_printer(current);
		current = current->next;
	}
	return (i);
}

void	ft_clear_values(t_value **alst, void (*del)(t_value*))
{
	t_value	*tmp;

	while (*alst != NULL)
	{
		tmp = (*alst)->next;
		(*del)(*alst);
		*alst = tmp;
	}
	*alst = NULL;
}

void	ft_clear_struct(t_value *val)
{
	if (val->toprint)
	{
		free(val->toprint);
		val->toprint = 0;
	}
	val->size = 0;
	val->minus = 0;
	val->zero = 0;
	val->width = 0;
	val->dot = 0;
	val->precision = 0;
	val->type = 0;
	free(val);
	val = NULL;
}
