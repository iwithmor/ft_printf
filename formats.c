/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:39:23 by iwithmor          #+#    #+#             */
/*   Updated: 2017/01/18 18:39:24 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_s(t_pf *stuff)
{
	char *s_str;

	s_str = (char *)va_arg(stuff->ap, char *);
	print_string(s_str, stuff);
}

void	print_c(t_pf *stuff)
{
	char c_str[2];

	c_str[0] = (char)va_arg(stuff->ap, int);
	c_str[1] = '\0';
	print_string(c_str, stuff);
}
