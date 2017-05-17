/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 18:24:58 by iwithmor          #+#    #+#             */
/*   Updated: 2017/01/28 18:25:00 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_precision(t_pf *stuff)
{
	if (stuff->format[stuff->i] == '.')
	{
		stuff->precision_specified = 1;
		stuff->precision = 0;
		stuff->i++;
		if (stuff->format[stuff->i] == '*')
		{
			stuff->precision = va_arg(stuff->ap, int);
			stuff->i++;
		}
		else
			while (ft_isdigit(stuff->format[stuff->i]))
			{
				stuff->precision *= 10;
				stuff->precision += stuff->format[stuff->i] - '0';
				stuff->i++;
			}
	}
}

void	add_precision_zeros(t_pf *stuff, int size)
{
	while (stuff->precision > size)
	{
		ft_putchar('0');
		stuff->pcount++;
		stuff->precision--;
	}
}
