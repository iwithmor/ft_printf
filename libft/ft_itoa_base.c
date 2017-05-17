/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 09:03:29 by exam              #+#    #+#             */
/*   Updated: 2016/12/06 09:21:26 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_power(int value, int base)
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

int		ft_exp(int base, int power)
{
	return ((power == 0) ? 1 : base * ft_exp(base, --power));
}

char	convert(int value, int start_letter)
{
	if (value >= 0 && value <= 9)
		return (value + '0');
	else
		return (value - 10 + start_letter);
}

char	*ft_itoa_base(int value, int base, int start_letter)
{
	int		neg;
	int		i;
	int		power;
	int		size;
	char	*str;

	neg = (base == 10 && value < 0) ? 1 : 0;
	i = 0;
	if (value == -2147483648 || value == 2147483647)
	{
		if (value == -2147483648)
			str = ft_strdup("-2147483648");
		else
			str = ft_strdup("+2147483647");
		return (str);
	}
	value = (value < 0) ? -value : value;
	power = get_power(value, base);
	size = power + 2;
	str = ft_strnew(size);
	if (neg == 1)
		str[i++] = '-';
	else
		str[i++] = '+';
	while (i < size)
	{
		str[i++] = convert(value / ft_exp(base, power), start_letter);
		value = value % ft_exp(base, power--);
	}
	return (str);
}
