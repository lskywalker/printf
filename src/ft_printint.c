/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printint.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 13:58:39 by lsmit          #+#    #+#                */
/*   Updated: 2020/01/20 14:23:34 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

void	ft_printint(int nb, t_list *flags)
{
	int		len;

	if (nb == 0 && flags->precision == -1)
		return ;
	len = ft_intlen(nb, flags);
	if (flags->negative == 1)
	{
		len--;
		if ((flags->origwidth == 1 || flags->origwidth == 0) && \
		flags->printed == 0)
			ft_putchar('-', flags);
	}
	if (len >= flags->precision)
		ft_putnbr(nb, flags);
	else
	{
		if (len == 0)
			len++;
		while (flags->precision - len > 0)
		{
			ft_putchar('0', flags);
			flags->precision--;
		}
		ft_putnbr(nb, flags);
	}
}
