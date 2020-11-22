/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printstr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 14:08:42 by lsmit          #+#    #+#                */
/*   Updated: 2020/01/20 18:53:31 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

void	ft_emptystring(t_list *flags)
{
	while (flags->precision >= 1 && flags->width != 0 && \
	flags->ogprecision != 1)
	{
		ft_putchar(' ', flags);
		flags->precision--;
		flags->width--;
	}
	if (flags->ogprecision == 1 && flags->origwidth == 1)
		ft_putchar(' ', flags);
	if (flags->ogprecision == 1 && flags->origwidth > flags->ogprecision)
		flags->spaces++;
}

void	ft_widthprecision(char *str, t_list *flags)
{
	if (flags->width > flags->ogprecision)
	{
		while (flags->width - flags->ogprecision > 0 && \
		(flags->ogprecision != 0 || flags->precision == -1))
		{
			if (flags->minus == 0)
				ft_putchar(' ', flags);
			else
				flags->spaces++;
			flags->width--;
		}
	}
	else
	{
		while (flags->width > ft_strlen(str))
		{
			if (flags->minus == 0)
				ft_putchar(' ', flags);
			else
				flags->spaces++;
			flags->width--;
		}
	}
}

void	ft_printstr2(char *str, int i, t_list *flags)
{
	char	*sub;

	sub = malloc(ft_strlen(str) + 1);
	if (!sub)
	{
		flags->errorcheck = 1;
		return ;
	}
	while (flags->precision > 0 && str[i])
	{
		sub[i] = str[i];
		i++;
		flags->precision -= 1;
	}
	sub[i] = '\0';
	ft_putstr(sub, flags);
	free(sub);
}

void	ft_printstr(char *str, t_list *flags)
{
	int		i;

	i = 0;
	if (str == NULL)
		str = "(null)";
	else
	{
		if (str[i] == '\0')
		{
			ft_emptystring(flags);
			return ;
		}
	}
	ft_widthprecision(str, flags);
	if (flags->precision <= -1)
		return ;
	if (flags->precision == 0)
	{
		ft_putstr(str, flags);
		return ;
	}
	ft_printstr2(str, i, flags);
}
