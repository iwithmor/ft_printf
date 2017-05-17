/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:28:02 by iwithmor          #+#    #+#             */
/*   Updated: 2017/01/15 20:28:03 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_unsigned_long(t_pf *stuff, integer n, int base, char a)
{
	char *str;

	str = unsigned_to_string(stuff, n, base, a);
	if (!stuff->l_justify && stuff->precision == 0 && n.ul == 0)
		left_padding(stuff, 0);
	if (!stuff->l_justify)
		left_padding(stuff, ft_strlen(str));
	if (!(n.ul == 0 && stuff->precision == 0))
	{
		if (n.ul != 0 && stuff->hashtag)
			print_hash(stuff);
		add_precision_zeros(stuff, ft_strlen(str));
		ft_putstr(str);
		stuff->pcount += ft_strlen(str);
	}
	if (stuff->l_justify)
		right_padding(stuff);
}

void	print_unsigned_short(t_pf *stuff, integer n, int base, char a)
{
	char *str;

	str = unsigned_to_string(stuff, n, base, a);
	print_space(stuff, n.i);
	if (!stuff->l_justify && stuff->precision == 0 && n.us == 0)
		left_padding(stuff, 0);
	if (!stuff->l_justify)
		left_padding(stuff, ft_strlen(str));
	if (!(n.us == 0 && stuff->precision == 0))
	{
		if (n.us != 0 && stuff->hashtag)
			print_hash(stuff);
		add_precision_zeros(stuff, ft_strlen(str));
		ft_putstr(str);
		stuff->pcount += ft_strlen(str);
	}
	if (stuff->l_justify)
		right_padding(stuff);
}

void	print_unsigned_int(t_pf *stuff, integer n, int base, char a)
{
	char *str;

	str = unsigned_to_string(stuff, n, base, a);
	if (!stuff->l_justify && stuff->precision == 0 && n.ui == 0)
		left_padding(stuff, 0);
	if (!stuff->l_justify)
		left_padding(stuff, ft_strlen(str));
	if (!(n.ui == 0 && stuff->precision == 0))
	{
		if (stuff->hashtag && n.ui != 0)
			print_hash(stuff);
		add_precision_zeros(stuff, ft_strlen(str));
		ft_putstr(str);
		stuff->pcount += ft_strlen(str);
	}
	if (stuff->l_justify)
		right_padding(stuff);
}

void	print_unsigned(t_pf *stuff, int base, char start_letter)
{
	integer	number;

	number = get_unsigned_number(stuff);
	if (stuff->hashtag && stuff->padchar == '0')
		print_hash(stuff);
	if (stuff->long_int)
		print_unsigned_long(stuff, number, base, start_letter);
	else if (stuff->short_int)
		print_unsigned_short(stuff, number, base, start_letter);
	else
		print_unsigned_int(stuff, number, base, start_letter);
}
