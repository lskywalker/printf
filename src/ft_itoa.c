/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 13:50:12 by lsmit          #+#    #+#                */
/*   Updated: 2020/01/20 16:15:01 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

static int		ft_count(long long n)
{
	long long i;
	long long n2;

	i = 1;
	n2 = n;
	if (n2 < 0)
	{
		n2 = n2 * -1;
		i++;
	}
	i++;
	while (n2 > 9)
	{
		i++;
		n2 = n2 / 10;
	}
	return (i);
}

static char		*ft_whileloop(long long i, long long n2, long long m, char *r)
{
	long long old;

	old = n2;
	while (old != n2 || m == 1)
	{
		if (old != n2 / 10 && old > 9)
			old = n2 / 10;
		else
			old = n2;
		m = m * 10;
		while (old >= m)
			old = old / 10;
		r[i] = old % 10 + '0';
		i++;
	}
	r[i] = '\0';
	return (r);
}

char			*ft_itoa(long long n2, t_list *flags)
{
	long long	i;
	long long	mult;
	char		*res;

	i = 0;
	mult = 1;
	res = malloc(sizeof(char) * ft_count(n2));
	if (!res)
	{
		flags->errorcheck = 1;
		return (0);
	}
	if (n2 < 0)
	{
		res[i] = 45;
		i++;
		n2 = n2 * -1;
	}
	res = ft_whileloop(i, n2, mult, res);
	return (res);
}
