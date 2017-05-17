/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 13:22:02 by iwithmor          #+#    #+#             */
/*   Updated: 2017/01/27 13:22:03 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_final_str(t_pf *stuff, char *s)
{
	char	*str;
	char	*final;
	int		free_str;
	int		i;

	final = NULL;
	free_str = 0;
	i = 0;
	if (stuff->precision_specified)
	{
		str = ft_strsub(s, 0, stuff->precision);
		free_str = 1;
	}
	else
		str = s;
	if (stuff->width > (int)ft_strlen(str))
	{
		stuff->width -= ft_strlen(str);
		final = ft_strnew(stuff->width + ft_strlen(str) + 1);
		ft_memset(final, stuff->padchar, stuff->width + ft_strlen(str));
		if (stuff->l_justify)
		{
			while (i < (int)ft_strlen(str))
			{
				final[i] = str[i];
				++i;
			}
		}
		else
		{
			i = 0;
			while (i + stuff->width < (int)ft_strlen(final))
			{
				final[i + stuff->width] = str[i];
				++i;
			}
		}
		if (free_str)
			free(str);
	}
	else
		return (str);
	return (final);
}
