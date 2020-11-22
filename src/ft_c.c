/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_c.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 15:44:57 by lsmit          #+#    #+#                */
/*   Updated: 2020/01/20 16:42:07 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

void	ft_c(char c, t_list *flags)
{
	ft_putchar(c, flags);
}

void	ft_printminus(t_list *flags)
{
	ft_putchar('-', flags);
	flags->printed = 1;
}
