/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negative_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 13:22:02 by iwithmor          #+#    #+#             */
/*   Updated: 2017/01/27 13:22:03 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_lpower(long value, int base)
{
	int count;

	count = 0;
	while (base <= value)
	{
		++count;
		value = value / base;
	}
	return (count);
}

char	*neg_hex_to_string(int value, char specifier)
{
	char *str;
	int i;
	int a;
	int f;
	int power;

	a = specifier - 23;
	f = specifier - 18;
	str = ft_strnew(8);
	i = 0;
	while (i < 8)
	{
		str[i] = f;
		++i;
	}
	--i;
	power = get_power(value, 16);
	i -= power;
	while (value > 1)
	{
		while (value > ft_exp(16, power))
		{
			if (str[i] == a)
				str[i] = '9';
			else
				str[i] -= 1;
			value -= ft_exp(16, power);
		}
		--power;
		++i;
	}
	return (str);
}

char	*neg_lhex_to_string(long value, char specifier)
{
	char *str;
	int i;
	int a_A;
	int f_F;
	int power;

	a_A = specifier - 23;
	f_F = specifier - 18;
	str = ft_strnew(16);
	i = 0;
	while (i < 16)
	{
		str[i] = f_F;
		++i;
	}
	--i;
	power = get_power(value, 16);
	i -= power;
	while (value > 1)
	{
		while (value > ft_exp(16, power))
		{
			if (str[i] == a_A)
				str[i] = '9';
			else
				str[i] -= 1;
			value -= ft_exp(16, power);
		}
		--power;
		++i;
	}
	return (str);
}
