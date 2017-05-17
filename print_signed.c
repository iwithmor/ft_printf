/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:28:02 by iwithmor          #+#    #+#             */
/*   Updated: 2017/01/15 20:28:03 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_signed_long(t_pf *stuff, integer n, int base, char a)
{
	char *str;

	stuff->sign = (n.l < 0) ? 1 : stuff->sign;
	str = ft_itoa_base(n.l, base, a);
	print_space(stuff, n.l);
	if (stuff->sign && (stuff->l_justify || stuff->padchar == '0'))
		print_sign(stuff, str[0]);
	if (!stuff->l_justify && stuff->precision == 0 && n.l == 0)
		left_padding(stuff, 0);
	if (!stuff->l_justify)
		left_padding(stuff, ft_strlen(str + 1));
	if (stuff->hashtag)
	{
		if (stuff->specifier == 'o')
			print_hash(stuff);
		else if (stuff->precision != 0 && n.l != 0)
			print_hash(stuff);
	}
	if (!(n.l == 0 && stuff->precision == 0))
	{
		if (stuff->sign && !(stuff->l_justify || stuff->padchar == '0'))
			print_sign(stuff, str[0]);
		add_precision_zeros(stuff, ft_strlen(str + 1));
		ft_putstr(str + 1);
		stuff->pcount += ft_strlen(str + 1);
	}
	if (stuff->l_justify)
		right_padding(stuff);
}

void	print_signed_short(t_pf *stuff, integer n, int base, char a)
{
	char *str;

	stuff->sign = (n.s < 0) ? 1 : stuff->sign;
	str = ft_itoa_base(n.s, base, a);
	print_space(stuff, n.s);
	if (stuff->sign && (stuff->l_justify || stuff->padchar == '0'))
		print_sign(stuff, str[0]);
	if (!stuff->l_justify && stuff->precision == 0 && n.s == 0)
		left_padding(stuff, 0);
	if (!stuff->l_justify)
		left_padding(stuff, ft_strlen(str + 1));
	if (stuff->hashtag)
	{
		if (stuff->specifier == 'o')
			print_hash(stuff);
		else if (stuff->precision != 0 && n.s != 0)
			print_hash(stuff);
	}
	if (!(n.s == 0 && stuff->precision == 0))
	{
		if (stuff->sign && !(stuff->l_justify || stuff->padchar == '0'))
			print_sign(stuff, str[0]);
		add_precision_zeros(stuff, ft_strlen(str + 1));
		ft_putstr(str + 1);
		stuff->pcount += ft_strlen(str + 1);
	}
	if (stuff->l_justify)
		right_padding(stuff);
}

void	print_signed_int(t_pf *stuff, integer n, int base, char a)
{
	char *str;

	stuff->sign = (n.i < 0) ? 1 : stuff->sign;
	str = ft_itoa_base(n.i, base, a);
	print_space(stuff, n.i);
	if (stuff->sign && (stuff->l_justify || stuff->padchar == '0'))
		print_sign(stuff, str[0]);
	if (!stuff->l_justify && stuff->precision == 0 && n.i == 0)
		left_padding(stuff, 0);
	if (!stuff->l_justify)
		left_padding(stuff, ft_strlen(str + 1));
	if (stuff->hashtag)
	{
		if (stuff->specifier == 'o')
			print_hash(stuff);
		else if (stuff->precision != 0 && n.i != 0)
			print_hash(stuff);
	}
	if (!(n.i == 0 && stuff->precision == 0))
	{
		if (stuff->sign && !(stuff->l_justify || stuff->padchar == '0'))
			print_sign(stuff, str[0]);
		add_precision_zeros(stuff, ft_strlen(str + 1));
		ft_putstr(str + 1);
		stuff->pcount += ft_strlen(str + 1);
	}
	if (stuff->l_justify)
		right_padding(stuff);
}

void	print_signed(t_pf *stuff, int base, char start_letter)
{
	integer	number;

	number = get_signed_number(stuff);
	if (stuff->long_int)
		print_signed_long(stuff, number, base, start_letter);
	else if (stuff->short_int)
		print_signed_short(stuff, number, base, start_letter);
	else
		print_signed_int(stuff, number, base, start_letter);
}
