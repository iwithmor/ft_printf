/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:27:39 by iwithmor          #+#    #+#             */
/*   Updated: 2017/01/15 20:27:41 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_the_stuff(t_pf *stuff)
{
	check_incompatibilities(stuff);
	if (stuff->specifier == '%')
		print_char('%', stuff);
	else if (stuff->specifier == 'n')
		va_arg(stuff->ap, int *);
	else if (stuff->specifier == 'i' || stuff->specifier == 'd')
		print_int(stuff, 10, 'a', SIGNED);
	else if (stuff->specifier == 'u')
		print_int(stuff, 10, 'a', UNSIGNED);
	else if (stuff->specifier == 'x' || stuff->specifier == 'X')
		print_int(stuff, 16, stuff->specifier - 23, UNSIGNED);
	else if (stuff->specifier == 'o')
		print_int(stuff, 8, 'a', SIGNED);
	else if (stuff->specifier == 'c')
		print_char(va_arg(stuff->ap, int), stuff);
	else if (stuff->specifier == 's')
		print_string(va_arg(stuff->ap, char *), stuff);
}

void	format_args(t_pf *stuff)
{
	if (stuff->format[stuff->i] == '\0')
	{
		ft_putstr_fd("warning: incomplete format specifier\n", 2);
		exit(0);
	}
	check_flags(stuff);
	check_width(stuff);
	check_precision(stuff);
	check_length(stuff);
	check_specifier(stuff);
	print_the_stuff(stuff);
}

void	do_it(t_pf *stuff)
{
	while (stuff->format[stuff->i] != '\0')
	{
		if (stuff->format[stuff->i] == '%')
		{
			stuff->i++;
			format_args(stuff);
			reset_stuff(stuff);
		}
		else
		{
			ft_putchar(stuff->format[stuff->i]);
			stuff->pcount++;
		}
		stuff->i++;
	}
}

int		ft_printf(const char *format, ...)
{
	t_pf	*stuff;
	int		count;

	if (!(stuff = stuff_init(format)))
		return (0);
	va_start(stuff->ap, format);
	do_it(stuff);
	va_end(stuff->ap);
	count = stuff->pcount;
	free(stuff);
	return (stuff->pcount);
}
