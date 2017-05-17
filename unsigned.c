/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:28:02 by iwithmor          #+#    #+#             */
/*   Updated: 2017/01/15 20:28:03 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ul_overflow_to_string(long value, int base, const char *s)
{
	char	*str;
	int		power;
	int		i;

	str = ft_strdup(s);
	power = get_power(value, base);
	i = ft_strlen(str) - power;
	while (value > 1)
	{
		if (i < 0)
			type_error("long", "long long");
		while (value > ft_exp(10, power))
		{
			str[i] += 1;
			value -= ft_exp(10, power);
		}
		--power;
		++i;
	}
	return (str);
}

char	*unsigned_to_string(t_pf *stuff, integer number, int base, char letter)
{
	char *str;
	char *str_cpy;
	char spec;

	spec = stuff->specifier;
	if (stuff->long_int || (!stuff->short_int && spec != 'x' && spec != 'X'))
	{
		//printf("***\t%lu\t***", number.ul);
		if (number.ul > 4294967295 && base == 16)
			str = ul_overflow_to_string(number.ul - 4294967295, base, "100000000");
		//else if (number.ul > 4294967295 && base == 10)
		//	str = ul_overflow_to_string(number.ul - 4294967295, base, "4294967296");
		else
			str = ft_ultoa_base(number.ul, base, letter);
		return (str);
	}
	else if (number.i < 0 && (spec == 'x' || spec == 'X'))
	{
		str = neg_hex_to_string(0 - number.i, stuff->specifier);
		return (str);
	}
	str = ft_itoa_base(number.i, base, letter);
	str_cpy = ft_strdup(str + 1);
	free(str);
	return (str_cpy);
}

integer	get_unsigned_number(t_pf *stuff)
{
	integer num_data;

	if (stuff->long_int)
		num_data.ul = va_arg(stuff->ap, unsigned long);
	else
		num_data.i = va_arg(stuff->ap, int);
	return (num_data);
}
