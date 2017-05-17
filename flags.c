/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 13:58:44 by iwithmor          #+#    #+#             */
/*   Updated: 2017/01/27 13:58:46 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		isflag(char c)
{
	if (c == '#' || c == '-' || c == '+' || c == ' ' || c == '0')
		return (1);
	return (0);
}

void	check_flags(t_pf *stuff)
{
	while (isflag(stuff->format[stuff->i]))
	{
		if (stuff->format[stuff->i] == '-')
			stuff->l_justify = 1;
		else if (stuff->format[stuff->i] == '+')
			stuff->sign = 1;
		else if (stuff->format[stuff->i] == '0')
			stuff->padchar = '0';
		else if (stuff->format[stuff->i] == ' ')
			stuff->addspace = 1;
		else if (stuff->format[stuff->i] == '#')
			stuff->hashtag = 1;
		stuff->i++;
	}
	if (stuff->sign && stuff->addspace)
		ignore_flag_warning(' ', '+');
	if (stuff->l_justify && stuff->padchar == '0')
		ignore_flag_warning('0', '-');
}

int		get_hashcount(t_pf *stuff)
{
	if (stuff->hashtag)
	{
		if (stuff->specifier == 'o')
			return (1);
		else if (stuff->specifier == 'x' || stuff->specifier == 'X')
			return (2);
	}
	return (0);
}

void	print_hash(t_pf *stuff)
{
	if (stuff->specifier == 'o')
	{
		ft_putchar('0');
		stuff->pcount += 1;
		if (!stuff->l_justify)
			stuff->width -= 1;
	}
	else if (stuff->specifier == 'x' || stuff->specifier == 'X')
	{
		if (stuff->specifier == 'x')
			ft_putstr("0x");
		else
			ft_putstr("0X");
		stuff->pcount += 2;
		if (!stuff->l_justify)
			stuff->width -= 2;
	}
	stuff->hashtag = 0;
}

void	print_space(t_pf *stuff, int n)
{
	if (stuff->addspace && !stuff->sign && n >= 0)
	{
		ft_putchar(' ');
		stuff->pcount++;
		if (!stuff->l_justify)
			stuff->width--;
	}
}
