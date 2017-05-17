/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 15:46:21 by iwithmor          #+#    #+#             */
/*   Updated: 2017/01/29 15:46:22 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_stuff(t_pf *stuff)
{
	stuff->l_justify = 0;
	stuff->sign = 0;
	stuff->padchar = ' ';
	stuff->addspace = 0;
	stuff->hashtag = 0;
	stuff->width = 0;
	stuff->precision = 1;
	stuff->precision_specified = 0;
	stuff->length = 0;
	stuff->specifier = 0;
	stuff->sign = 0;
	stuff->short_int = 0;
	stuff->long_int = 0;
	stuff->long_double = 0;
}

t_pf	*stuff_init(const char *format)
{
	t_pf	*stuff;

	if (!(stuff = (t_pf *)malloc(sizeof(t_pf))))
		return (NULL);
	stuff->i = 0;
	stuff->pcount = 0;
	stuff->format = (char *)format;
	reset_stuff(stuff);
	return (stuff);
}
