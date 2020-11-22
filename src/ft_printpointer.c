/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printpointer.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 15:48:49 by lsmit          #+#    #+#                */
/*   Updated: 2020/01/21 15:58:06 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

void	ft_putnbrhex(unsigned long n, t_list *flags)
{
	char res;

	if (n > 15)
		ft_putnbrhex(n / 16, flags);
	if (n % 16 > 9)
		res = n % 16 + 87;
	else
		res = n % 16 + 48;
	ft_putchar(res, flags);
}

void	ft_printpointer(unsigned long ad, t_list *flags)
{
	ft_putstr("0x", flags);
	if (flags->pointerdot == 1 && flags->input == NULL)
		return ;
	ft_putnbrhex(ad, flags);
}
