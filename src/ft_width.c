/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_width.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 16:43:55 by lsmit          #+#    #+#                */
/*   Updated: 2020/01/21 16:24:25 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

unsigned int	ft_getwidth(int i, const char *input, t_list *flags)
{
	char			*numb;
	int				flag;
	int				j;

	j = 0;
	flag = 0;
	numb = malloc(2147483647);
	if (!numb)
		flags->errorcheck = 1;
	while (numb[j])
	{
		numb[j] = '\0';
		j++;
	}
	j = 0;
	while (ft_isdigit(input[i]))
	{
		numb[j] = input[i];
		i++;
		j++;
	}
	if (numb)
		flag = ft_atoi(numb);
	free(numb);
	return (flag);
}

void			ft_widthzeroflag2(int i, const char *input, t_list *flags)
{
	int		len;

	len = 0;
	if (flags->left == 1)
		i--;
	if (ft_isdigit(input[i]) || flags->width >= 0)
	{
		while (input[i] == '0')
			i++;
		if (flags->width == 0)
		{
			flags->width = ft_getwidth(i, input, flags);
			i += ft_intlen(flags->width, flags);
		}
		i += ft_precisionskip(i, input, flags);
		i += ft_skipflags(input, i);
		len = ft_inputlen(i, input, flags->input, flags);
	}
	flags->iszero = 2;
	ft_zerospaceprinter(len, flags);
}

void			ft_widthzeroflag(int i, const char *input, t_list *flags)
{
	int		len;

	len = 0;
	if (ft_isdigit(input[i]) || flags->width > 0)
	{
		while (input[i] == '0')
		{
			flags->iszero = 0;
			i++;
		}
		if (flags->width == 0)
		{
			flags->width = ft_getwidth(i, input, flags);
			i += ft_intlen(flags->width, flags);
		}
		i += ft_precisionskip(i, input, flags);
		len = ft_inputlen(i, input, flags->input, flags);
	}
	ft_zerospaceprinter(len, flags);
}

void			ft_percentwidth(t_list *flags)
{
	flags->width = flags->origwidth;
	flags->spaces = 0;
	while (flags->width > 1 && flags->minus == 0)
	{
		if (flags->iszero == 1)
			ft_putchar(' ', flags);
		if (flags->iszero == 0)
			ft_putchar('0', flags);
		flags->width--;
	}
	while (flags->width > 1 && flags->minus == 1)
	{
		flags->spaces++;
		flags->width--;
	}
}
