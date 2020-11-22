/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printx.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/14 17:39:04 by lsmit          #+#    #+#                */
/*   Updated: 2020/01/21 17:25:52 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

int		ft_xlen(unsigned long n)
{
	unsigned long long count;

	if (n == 0)
		return (0);
	count = 0;
	while (n / 16)
	{
		n /= 16;
		count++;
	}
	return (count);
}

void	ft_putnbrhexbig(unsigned long n, t_list *flags)
{
	char res;

	if (n > 15)
		ft_putnbrhexbig(n / 16, flags);
	if (n % 16 > 9)
		res = n % 16 + 55;
	else
		res = n % 16 + 48;
	ft_putchar(res, flags);
}

void	ft_printsmallx(unsigned int n, t_list *flags)
{
	int len;

	len = ft_xlen(n) + 1;
	if (n == 0 && flags->precision == -1 && flags->width == 0)
		return ;
	if (n == 0 && flags->precision == -1 && flags->width > 0)
	{
		while (flags->width > 0)
		{
			ft_putchar(' ', flags);
			flags->width--;
			return ;
		}
	}
	while (flags->precision > len)
	{
		ft_putchar('0', flags);
		flags->precision--;
	}
	ft_putnbrhex(n, flags);
}

void	ft_printbigx(unsigned int n, t_list *flags)
{
	int len;

	len = ft_xlen(n) + 1;
	if (n == 0 && flags->precision == -1 && flags->width == 0)
		return ;
	if (n == 0 && flags->precision == -1 && flags->width > 0)
	{
		while (flags->width > 0)
		{
			ft_putchar(' ', flags);
			flags->width--;
			return ;
		}
	}
	while (flags->precision > len)
	{
		ft_putchar('0', flags);
		flags->precision--;
	}
	ft_putnbrhexbig(n, flags);
}
