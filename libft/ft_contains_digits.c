/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains_digits.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:26:54 by iwithmor          #+#    #+#             */
/*   Updated: 2016/12/08 17:26:55 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		contains_digits(char *str)
{
	int digits;

	digits = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
			++digits;
		++str;
	}
	return (digits);
}
