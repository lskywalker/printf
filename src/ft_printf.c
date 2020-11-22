/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 13:17:01 by lsmit          #+#    #+#                */
/*   Updated: 2020/01/21 17:40:04 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

void	ft_getprecision(int i, const char *input, t_list *flags)
{
	if (input[i] == 'p')
	{
		flags->pointerdot = 1;
		return ;
	}
	if (input[i] == '-')
		flags->precision = 0;
	if (input[i] == 's' || input[i] == 'd' || input[i] == 'i' || \
	input[i] == 'u' || input[i] == 'x' || input[i] == 'X')
		flags->precision = -1;
	if (input[i] == '0')
	{
		flags->precision = -1;
		i++;
	}
	while (input[i] == '0')
		i++;
	if (ft_isdigit(input[i]))
		flags->precision = ft_getwidth(i, input, flags);
	flags->ogprecision = flags->precision;
	if (flags->ogprecision < 0)
		flags->ogprecision = 0;
}

void	ft_checkflag(int i, const char *input, va_list args, t_list *flags)
{
	while (input[i] == '0')
	{
		flags->iszero = 0;
		i++;
	}
	if (input[i] == '-' && input[i + 1] == '*')
	{
		i++;
		flags->left = 1;
	}
	while (input[i] == '*')
	{
		flags->width = va_arg(args, int);
		if (flags->width < 0)
		{
			flags->width *= -1;
			flags->left = 1;
		}
		i++;
	}
	if (ft_dotstar(i, input) == 0)
		ft_nodotstar(i, input, args, flags);
	else
		ft_yesdotstar(i, input, args, flags);
}

void	ft_readinput(int i, const char *input, va_list args, t_list *flags)
{
	while (input[i])
	{
		if (input[i] == '%' && input[i + 1] != '%')
		{
			ft_structnull(flags);
			ft_checkflag(i + 1, input, args, flags);
			i += ft_skipflags(input, i + 1);
			ft_getconversion(i + 1, input, flags);
			i += 2;
		}
		else
		{
			ft_putchar(input[i], flags);
			if (input[i] == '%' && input[i + 1] == '%')
				i += 2;
			else
				i++;
		}
	}
}

int		ft_printf(const char *input, ...)
{
	va_list		args;
	t_list		*flags;
	int			returnval;

	flags = malloc(sizeof(t_list));
	if (!flags)
		return (-1);
	flags->ret = 0;
	flags->errorcheck = 0;
	if (input == NULL)
	{
		ft_putchar('\0', flags);
		free(flags);
		return (0);
	}
	va_start(args, input);
	ft_readinput(0, input, args, flags);
	va_end(args);
	returnval = flags->ret;
	if (flags->errorcheck == 1)
		returnval = -1;
	free(flags);
	return (returnval);
}
