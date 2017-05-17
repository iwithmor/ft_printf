/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:28:02 by iwithmor          #+#    #+#             */
/*   Updated: 2017/01/15 20:28:03 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "./libft/libft.h"

/*
**	For 32-bit integer
*/
# define MAX_INT_LEN	12
# define SIGNED			1
# define UNSIGNED		0

typedef union			union_integer
{
	int					i;
	short				s;
	long				l;
	long long			ll;
	unsigned int		ui;
	unsigned short		us;
	unsigned long		ul;
	unsigned long long	ull;
}						integer;

typedef	struct	s_pf
{
	char	*format;
	int		i;
	int		pcount;
	int		width;
	int		l_justify;
	char	padchar;
	int		sign;
	int		addspace;
	int		hashtag;
	int		short_int;
	int		long_int;
	int		long_double;
	char	specifier;
	int		precision_specified;
	int		precision;
	int		length;
	va_list	ap;
}				t_pf;

int				ft_printf(const char *format, ...);
void			print_char(char c, t_pf *stuff);
void			print_string(char *str, t_pf *stuff);
void			print_int(t_pf *stuff, int base, char start_letter, int signed_int);
void			check_sc(t_pf *stuff);
void			check_dxxu(t_pf *stuff);
void			adjust_padding(t_pf *stuff);
void			adjust_width(t_pf *stuff);
void			check_flags(t_pf *stuff);
void			check_width(t_pf *stuff);
void			check_precision(t_pf *stuff);
void			check_length(t_pf *stuff);
void			check_specifier(t_pf *stuff);
t_pf			*stuff_init(const char *format);
void			reset_stuff(t_pf *stuff);
void			print_c(t_pf *stuff);
void			print_s(t_pf *stuff);
int				is_signed(char specifier);
void			sign_flag_warning(char specifier);
void			invalid_specifier_error(char specifier);
void			ignore_flag_warning(char ignore, char override);
void			incompatible_flag_warning(char flag, char specifier);
int				is_hash_compatible(char specifier);
void			check_incompatibilities(t_pf *stuff);
void			print_padding(t_pf *stuff, int size);
void			print_hash(t_pf *stuff);
void			print_space(t_pf *stuff, int n);
void			add_precision_zeros(t_pf *stuff, int size);
void			left_padding(t_pf *stuff, int size);
void			right_padding(t_pf *stuff);
int				get_hashcount(t_pf *stuff);
char			*neg_hex_to_string(int value, char specifier);
char			*neg_lhex_to_string(long value, char specifier);
int				get_lpower(long value, int base);
char			*unsigned_to_string(t_pf *stuff, integer n, int b, char a);
integer			get_unsigned_number(t_pf *stuff);
char			*ulong_to_string(unsigned long number, int base, char letter);
void			print_signed(t_pf *stuff, int base, char start_letter);
void			print_unsigned(t_pf *stuff, int base, char start_letter);
void			print_unsigned_long(t_pf *s, integer n, int b, char a);
void			print_unsigned_short(t_pf *s, integer n, int b, char a);
void			print_unsigned_int(t_pf *stuff, integer n, int b, char a);
void			print_signed_long(t_pf *stuff, integer number, int base, char a);
void			print_signed_short(t_pf *stuff, integer number, int base, char a);
void			print_signed_int(t_pf *stuff, integer number, int base, char a);
integer			get_signed_number(t_pf *stuff);
void			print_sign(t_pf *stuff, char sign);
char			*get_final_str(t_pf *stuff, char *s);
void			type_error(char *expected_type, char *actual_type);

#endif
