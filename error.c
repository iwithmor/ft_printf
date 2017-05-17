/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 17:21:35 by iwithmor          #+#    #+#             */
/*   Updated: 2017/01/29 17:21:36 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	sign_flag_warning(char specifier)
{
	ft_putstr_fd("warning: flag '+' results in undefined behavior with \'", 2);
	ft_putchar_fd(specifier, 2);
	ft_putstr_fd("\' conversion specifier\n", 2);
	exit(1);
}

void	ignore_flag_warning(char ignore, char override)
{
	ft_putstr_fd("warning: flag \'", 2);
	ft_putchar_fd(ignore, 2);
	ft_putstr_fd("\' is ignored when flag \'", 2);
	ft_putchar_fd(override, 2);
	ft_putstr_fd("\' is present\n", 2);
	exit(1);
}

void	incompatible_flag_warning(char flag, char specifier)
{
	ft_putstr_fd("warning: flag \'", 2);
	ft_putchar_fd(flag, 2);
	ft_putstr_fd("\' results in undefined behavior with \'", 2);
	ft_putchar_fd(specifier, 2);
	ft_putstr_fd("\' conversion specifier\n", 2);
	exit(1);
}

void	invalid_specifier_error(char specifier)
{
	ft_putstr_fd("Error: Invalid conversion specifier \'", 2);
	ft_putchar_fd(specifier, 2);
	ft_putstr_fd("\'\n", 2);
	exit(1);
}

void	type_error(char *expected_type, char *actual_type)
{
	ft_putstr_fd("error: format specifies type \'", 2);
	ft_putstr_fd(expected_type, 2);
	ft_putstr_fd("\' but the argument has type \'", 2);
	ft_putstr_fd(actual_type, 2);
	ft_putstr_fd("\'\n", 2);
	exit(1);
}
