/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 13:22:02 by iwithmor          #+#    #+#             */
/*   Updated: 2017/01/27 13:22:03 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_sign(t_pf *stuff, char sign)
{
	ft_putchar(sign);
	stuff->pcount++;
}

void	print_char(char c, t_pf *stuff)
{
	if (!stuff->l_justify)
		left_padding(stuff, 1);
	ft_putchar(c);
	stuff->pcount++;
	if (stuff->l_justify)
		right_padding(stuff);
}

void	print_int(t_pf *stuff, int base, char start_letter, int signed_int)
{
	if (signed_int)
		print_signed(stuff, base, start_letter);
	else
		print_unsigned(stuff, base, start_letter);
}

void	print_string(char *str, t_pf *stuff)
{
	char	*final_str;
	int		len;

	if (!str)
	{
		ft_putstr("(null)");
		stuff->pcount += 6;
		return ;
	}
	final_str = get_final_str(stuff, str);
	len = (int)ft_strlen(final_str);
	ft_putstr(final_str);
	stuff->pcount += len;
}
