/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 15:08:48 by iwithmor          #+#    #+#             */
/*   Updated: 2017/01/29 15:08:49 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_length(t_pf *stuff)
{
	if (stuff->format[stuff->i] == 'h')
	{

		stuff->short_int++;
		stuff->i++;
		if (stuff->format[stuff->i] == 'h')
		{
			stuff->short_int++;
			stuff->i++;
		}
	}
	else if (stuff->format[stuff->i] == 'l')
	{
		stuff->long_int = 1;
		stuff->i++;
		if (stuff->format[stuff->i] == 'l')
		{
			stuff->long_int++;
			stuff->i++;
		}
	}
	else if (stuff->format[stuff->i] == 'L')
	{
		stuff->long_double = 1;
		stuff->i++;
	}
	else if (stuff->format[stuff->i] == 'j')
	{
		// TODO
		stuff->i++;
	}
	else if (stuff->format[stuff->i] == 'z')
	{
		// TODO
		stuff->i++;
	}
}
