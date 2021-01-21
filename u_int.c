/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_int.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:11:06 by jaehchoi          #+#    #+#             */
/*   Updated: 2021/01/21 23:30:15 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_neg_pre_un(t_contents *f, unsigned long long n, int digit)
{
	int	i;
	int	minus;

	minus = (n < 0) ? 1 : 0;
	i = (f->width > digit + minus) ? f->width : (digit - minus);
	if (f->minus)
	{
		itoa_free_u(n);
		while (i--)
			ret_with_write(' ');
	}
	if (f->zero)
	{
		while (i--)
			ret_with_write('0');
		itoa_free_u(n);
	}
	else
	{
		while (i--)
			ret_with_write(' ');
		itoa_free_u(n);
	}
	return ((f->width > digit + minus) ? f->width : digit + minus);
}

static void	print_with_pad(t_contents *f, unsigned long long n, int d, int m)
{
	int	i;

	i = f->precision - d;
	if (m == 1)
		ret_with_write('-');
	fill_space(i, '0');
	itoa_nosign_free_u(n);
}

static int	biggerpre(t_contents *f, unsigned long long n, int digit, int m)
{
	int	i;

	i = (f->width > f->precision + m) ? f->width : 0;
	if (f->minus)
	{
		print_with_pad(f, n, digit, m);
		fill_space(i, ' ');
	}
	else if (f->zero)
	{
		fill_space(i, '0');
		print_with_pad(f, n, digit, m);
	}
	else
	{
		fill_space(i, ' ');
		print_with_pad(f, n, digit, m);
	}
	return ((f->width > f->precision + m) ? f->width : f->precision + m);
}

int			print_pos_pre_un(t_contents *f, unsigned long long n, int digit)
{
	int	minus;

	minus = (n < 0) ? 1 : 0;
	if (f->precision > digit)
		return (biggerpre(f, n, digit, minus));
	else
		return (print_neg_pre_un(f, n, digit));
}

int			unint_parse(t_contents *f, unsigned long long n, int digit)
{
	if (f->precision <= 0)
	{
		if (f->precision == 0 && n == 0)
			--digit;
		return (print_neg_pre_un(f, n, digit));
	}
	return (print_pos_pre_un(f, n, digit));
}