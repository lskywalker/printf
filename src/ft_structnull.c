/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_structnull.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 10:29:32 by lsmit          #+#    #+#                */
/*   Updated: 2020/01/21 15:55:32 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

void		ft_structnull(t_list *flags)
{
	flags->precision = 0;
	flags->spaces = 0;
	flags->iszero = 1;
	flags->width = 0;
	flags->negative = 0;
	flags->dotfound = 0;
	flags->left = 0;
	flags->ogprecision = 0;
	flags->minus = 0;
	flags->origwidth = 0;
	flags->percent = 0;
	flags->printed = 0;
	flags->pointerdot = 0;
}
