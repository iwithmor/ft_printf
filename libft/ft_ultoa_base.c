/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 09:03:29 by exam              #+#    #+#             */
/*   Updated: 2016/12/06 09:21:26 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		get_ulpower(unsigned long value, int base)
{
	int count;

	count = 0;
	while ((unsigned int)base <= value)
	{
		++count;
		value = value / base;
	}
	return (count);
}

char	*ft_ultoa_base(unsigned long value, int base, int start_letter)
{
	int		i;
	int		power;
	int		size;
	char	*str;

	i = 0;
	if (value == 4294967295)
	{
		str = ft_strdup("4294967295");
		return (str);
	}
	power = get_power(value, base);
	size = power + 1;
	str = ft_strnew(size);
	while (i < size)
	{
		str[i++] = convert(value / ft_exp(base, power), start_letter);
		value = value % ft_exp(base, power--);
	}
	return (str);
}
