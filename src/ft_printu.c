/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printu.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/14 16:13:40 by lsmit          #+#    #+#                */
/*   Updated: 2020/01/18 16:39:36 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

void	ft_putunsignednbr(unsigned long n, t_list *flags)
{
	if (n > 9)
	{
		ft_putnbr(n / 10, flags);
		ft_putnbr(n % 10, flags);
	}
	else
		ft_putchar(n + '0', flags);
}

void	ft_printu(unsigned int n, t_list *flags)
{
	int	len;

	len = ft_unsignedlen((long long)n, flags);
	if (n == 0 && flags->precision == -1)
		return ;
	if (n == 0)
		len = 1;
	while (flags->precision > len)
	{
		ft_putchar('0', flags);
		flags->precision--;
	}
	ft_putunsignednbr(n, flags);
}
