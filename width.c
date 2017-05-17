/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 15:35:24 by iwithmor          #+#    #+#             */
/*   Updated: 2017/01/28 15:35:25 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_width(t_pf *stuff)
{
	if (stuff->format[stuff->i] == '*')
	{
		stuff->width = va_arg(stuff->ap, int);
		stuff->i++;
	}
	else
		while (ft_isdigit(stuff->format[stuff->i]))
		{
			stuff->width *= 10;
			stuff->width += stuff->format[stuff->i] - '0';
			stuff->i++;
		}
}

void	left_padding(t_pf *stuff, int digits)
{
	//printf("***\twidth = %d\tprecision = %d\tdigits = %d non-digits = %d\t***", stuff->width, stuff->precision, digits, stuff->sign + get_hashcount(stuff));
	stuff->width -= stuff->sign + get_hashcount(stuff);
	if (digits > stuff->precision)
	{
		stuff->width -= digits;
		//printf("\twidth = %d\t", stuff->width);
		while (stuff->width > 0)
		{
			ft_putchar(stuff->padchar);
			stuff->pcount++;
			stuff->width--;
		}
	}
	else
	{
		stuff->width -= stuff->precision;
		while (stuff->width > 0)
		{
			ft_putchar(' ');
			stuff->pcount++;
			stuff->width--;
		}
	}
}

void	right_padding(t_pf *stuff)
{
	while (stuff->pcount < stuff->width)
	{
		ft_putchar(stuff->padchar);
		stuff->pcount++;
	}
}
