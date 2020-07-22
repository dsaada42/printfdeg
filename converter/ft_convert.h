/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:35:13 by dsaada            #+#    #+#             */
/*   Updated: 2020/07/16 20:20:51 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERT_H
# define FT_CONVERT_H

# include "../ft_printf.h"

char	*ft_convert_char(char c);
char	*ft_convert_uint(unsigned int nb);
char	*ft_convert_hexa(int select, unsigned int nb);
char	*ft_convert_ptr(void *ptr);
char	*ft_convert(t_value *val, va_list a_list);
int		ft_count_hexa(unsigned int nb);
int		ft_count_hexa_ptr(unsigned long int nb);

#endif
