/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 17:40:07 by lsmit          #+#    #+#                */
/*   Updated: 2020/01/20 16:30:26 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

void	ft_putchar(char c, t_list *flags)
{
	write(1, &c, 1);
	flags->ret += 1;
}

void	ft_putnbr(int n, t_list *flags)
{
	if (n > 2147483647)
		return ;
	if (n == -2147483648)
	{
		ft_putnbr(-214748364, flags);
		ft_putchar('8', flags);
	}
	else
	{
		if (n < 0)
			n = -n;
		if (n > 9)
		{
			ft_putnbr(n / 10, flags);
			ft_putnbr(n % 10, flags);
		}
		else
			ft_putchar(n + '0', flags);
	}
}

void	ft_putstr(char *s, t_list *flags)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar(s[i], flags);
		i++;
	}
}

int		ft_atoi(char *str)
{
	int			i;
	long long	res;
	long long	n;

	i = 0;
	n = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		n = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((res * 10 + (str[i] - '0')) < res)
			return (((-1 * n) - 1) / 2);
		res = res * 10 + str[i] - '0';
		i++;
	}
	return ((int)res * n);
}

int		ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
