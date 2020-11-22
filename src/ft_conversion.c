/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conversion.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 16:51:28 by lsmit          #+#    #+#                */
/*   Updated: 2020/01/20 16:53:34 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

int		ft_checkconversion(int i, const char *input)
{
	if (input[i] != 'c' && \
		input[i] != 's' && \
		input[i] != 'd' && \
		input[i] != 'i' && \
		input[i] != 'x' && \
		input[i] != 'X' && \
		input[i] != 'u' && \
		input[i] != 'p')
		return (1);
	return (0);
}

void	ft_getconversion(int i, const char *input, t_list *flg)
{
	if (input[i] == 'c')
		ft_c((char)flg->input, flg);
	if (input[i] == 'i' || input[i] == 'd')
		ft_printint((int)flg->input, flg);
	if (input[i] == 's')
		ft_printstr((char*)flg->input, flg);
	if (input[i] == 'p')
		ft_printpointer((unsigned long)flg->input, flg);
	if (input[i] == 'u')
		ft_printu((unsigned int)flg->input, flg);
	if (input[i] == 'x')
		ft_printsmallx((unsigned int)flg->input, flg);
	if (input[i] == 'X')
		ft_printbigx((unsigned int)flg->input, flg);
	if (input[i] == '%')
	{
		ft_percentwidth(flg);
		flg->percent = 1;
		ft_putchar('%', flg);
	}
	if (flg->spaces > 0)
		ft_printspaceatend(flg);
}
