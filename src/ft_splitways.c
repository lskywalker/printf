/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_splitways.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 10:26:16 by lsmit          #+#    #+#                */
/*   Updated: 2020/01/21 15:57:14 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

void	ft_negativecheck(int i, const char *input, t_list *flags)
{
	int			in;
	long long	u;

	i += ft_skipflags(input, i);
	if (input[i] == 'i' || input[i] == 'd')
	{
		in = (int)flags->input;
		if (in < 0)
			flags->negative = 1;
	}
	if (input[i] == 'u')
	{
		u = (long long)flags->input;
		if (u < 0)
			flags->negative = 1;
	}
}

int		ft_dotstar(int i, const char *input)
{
	while (ft_checkconversion(i, input) == 1)
	{
		if (input[i] == '.' && input[i + 1] == '*')
			return (1);
		i++;
	}
	return (0);
}

void	ft_nodotstar(int i, const char *input, va_list args, t_list *flags)
{
	int j;

	flags->input = va_arg(args, void*);
	ft_negativecheck(i, input, flags);
	if (input[i] == '-' || flags->left == 1)
	{
		flags->minus = 1;
		ft_widthzeroflag2(i + 1, input, flags);
		i += ft_skipwidth(input, i);
	}
	else if (ft_isdigit(input[i]) || flags->width > 0)
	{
		ft_widthzeroflag(i, input, flags);
		i += ft_skipwidth(input, i);
	}
	if (input[i] == '.')
	{
		while (input[i + 1] == '.')
			i++;
		j = i + ft_skipflags(input, i);
		if ((input[j] == 's' || input[j] == 'i' || input[j] == 'd' || \
		input[j] == 'u' || input[j] == 'x' || input[j] == 'X' \
		|| input[j] == 'p') && flags->dotfound == 0)
			ft_getprecision(i + 1, input, flags);
	}
}

void	ft_yesdotstar(int i, const char *input, va_list args, t_list *flags)
{
	flags->precision = va_arg(args, int);
	if (flags->precision == 0)
		flags->precision--;
	else if (flags->precision < 0)
		flags->precision = 0;
	flags->input = va_arg(args, void*);
	ft_negativecheck(i, input, flags);
	if (input[i] == '-' || flags->left == 1)
	{
		flags->minus = 1;
		ft_widthzeroflag2(i + 1, input, flags);
		i += ft_skipwidth(input, i);
	}
	else if (ft_isdigit(input[i]) || flags->width > 0)
	{
		ft_widthzeroflag(i, input, flags);
		i += ft_skipwidth(input, i);
	}
}
