/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incompatible.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:32:03 by iwithmor          #+#    #+#             */
/*   Updated: 2017/01/31 17:32:04 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_incompatibilities(t_pf *stuff)
{
	if (stuff->sign && !is_signed(stuff->specifier))
		sign_flag_warning(stuff->specifier);
	if (stuff->hashtag && !is_hash_compatible(stuff->specifier))
		incompatible_flag_warning('#', stuff->specifier);
	if (stuff->addspace && stuff->specifier == 'n')
		incompatible_flag_warning(' ', 'n');
	if (stuff->padchar == '0' && stuff->specifier == 'n')
		incompatible_flag_warning('0', 'n');
}
