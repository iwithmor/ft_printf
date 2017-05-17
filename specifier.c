/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 15:50:03 by iwithmor          #+#    #+#             */
/*   Updated: 2017/01/29 15:50:04 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		isformat(char c)
{
	if (c == 'c' || c == 'd' || c == 'i')
		return (1);
	if (c == 'e' || c == 'E' || c == 'f')
		return (1);
	if (c == 'g' || c == 'G' || c == 'o')
		return (1);
	if (c == 's' || c == 'u' || c == 'x')
		return (1);
	if (c == 'X' || c == 'p' || c == 'n')
		return (1);
	if (c == '%')
		return (1);
	return (0);
}

int		is_signed(char specifier)
{
	if (specifier == 'd' || specifier == 'i' || specifier == 'f')
		return (1);
	if (specifier == 'e' || specifier == 'E')
		return (1);
	if (specifier == 'g' || specifier == 'G')
		return (1);
	return (0);
}

int		is_hash_compatible(char specifier)
{
	if (specifier == 'o' || specifier == 'x' || specifier == 'X')
		return (1);
	if (specifier == 'e' || specifier == 'E' || specifier == 'f')
		return (1);
	if (specifier == 'g' || specifier == 'G')
		return (1);
	return (0);
}

int		is_integer(char specifier)
{
	if (specifier == 'd' || specifier == 'i')
		return (1);
	if (specifier == 'o' || specifier == 'u')
		return (1);
	if (specifier == 'x' || specifier == 'X')
		return (1);
	return (0);
}

void	check_specifier(t_pf *stuff)
{
	if (!isformat(stuff->format[stuff->i]))
		invalid_specifier_error(stuff->format[stuff->i]);
	stuff->specifier = stuff->format[stuff->i];
}
