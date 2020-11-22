/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_len.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 16:29:20 by lsmit          #+#    #+#                */
/*   Updated: 2020/01/21 17:22:40 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (6);
	while (str[i])
		i++;
	return (i);
}

int		ft_plen(unsigned long n, int dotpointer, t_list *flags)
{
	unsigned long long count;

	if (flags->input == NULL)
	{
		if (dotpointer == 1)
			return (0);
		else
			return (1);
	}
	if (n == 0)
		return (0);
	count = 0;
	while (n)
	{
		n /= 16;
		count++;
	}
	return (count);
}

int		ft_intlen(int in, t_list *flags)
{
	char	*str;
	int		n;

	if (in == 0 && flags->precision != 0)
		return (0);
	str = ft_itoa(in, flags);
	n = ft_strlen(str);
	free(str);
	return (n);
}

int		ft_unsignedlen(long long in, t_list *flags)
{
	char		*str;
	long long	n;

	if (in == 0 && flags->precision != 0)
		return (0);
	str = ft_itoa(in, flags);
	n = ft_strlen(str);
	free(str);
	return (n);
}

int		ft_inputlen(int i, const char *input, void *arg, t_list *flags)
{
	if (input[i] == 'c')
		return (1);
	if (input[i] == 'd' || input[i] == 'i')
		return (ft_intlen((int)arg, flags));
	if (input[i] == 'u')
		return (ft_unsignedlen((long long)arg, flags));
	if (input[i] == 's')
		return (ft_strlen((char*)arg));
	if (input[i] == 'p' && input[i - 1] != '.')
		return (ft_plen((unsigned long)arg, 0, flags) + 2);
	if (input[i] == 'p' && input[i - 1] == '.')
		return (ft_plen((unsigned long)arg, 1, flags) + 2);
	if (input[i] == 'X' || input[i] == 'x')
		return (ft_xlen((unsigned long)arg) + 1);
	if (input[i] == '%')
	{
		flags->percent = 1;
		return (1);
	}
	return (0);
}
