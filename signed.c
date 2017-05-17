/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:28:02 by iwithmor          #+#    #+#             */
/*   Updated: 2017/01/15 20:28:03 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

integer	get_signed_number(t_pf *stuff)
{
	integer num_data;

	/*
	if (stuff->long_int)
		num_data.l = va_arg(stuff->ap, long);
	else
	*/
	num_data.i = va_arg(stuff->ap, int);
	return (num_data);
}
