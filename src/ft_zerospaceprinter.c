/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_zerospaceprinter.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 16:50:34 by lsmit          #+#    #+#                */
/*   Updated: 2020/01/21 15:43:44 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

void	ft_zerospaceprinter(int len, t_list *f)
{
	f->origwidth = f->width;
	f->iszero = (f->precision != 0 && f->iszero == 0) ? 1 : f->iszero;
	if (f->negative == 1 && f->width > f->precision && f->precision > 1)
	{
		f->width--;
		f->origwidth--;
		len--;
	}
	if (f->negative == 1 && f->origwidth != 1 && \
	(f->iszero == 0 || f->iszero == 2))
		ft_printminus(f);
	while (f->width > len && f->width > f->precision && f->percent == 0)
	{
		if (f->iszero == 1)
			ft_putchar(' ', f);
		if (f->iszero == 0)
			ft_putchar('0', f);
		f->width -= 1;
	}
	if (f->negative == 1 && f->iszero == 1 && f->origwidth != 1)
		ft_printminus(f);
	f->spaces = (f->iszero == 2) ? f->origwidth - f->width : 0;
}

void	ft_printspaceatend(t_list *flags)
{
	if (flags->ogprecision > flags->spaces || flags->percent == 1 || \
	flags->minus == 1)
	{
		while (flags->spaces > 0)
		{
			ft_putchar(' ', flags);
			flags->spaces -= 1;
		}
	}
	else
	{
		while (flags->spaces - flags->ogprecision > 0)
		{
			ft_putchar(' ', flags);
			flags->spaces -= 1;
		}
	}
}
