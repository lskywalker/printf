/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_skip.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 16:38:25 by lsmit          #+#    #+#                */
/*   Updated: 2020/01/20 16:57:20 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

int		ft_skipflags(const char *input, int i)
{
	int count;

	count = 0;
	while (ft_isdigit(input[i]) || input[i] == '-' || \
	input[i] == '.' || input[i] == '*')
	{
		i++;
		count++;
	}
	return (count);
}

int		ft_skipwidth(const char *input, int i)
{
	int count;

	count = 0;
	while (ft_isdigit(input[i]) || input[i] == '-')
	{
		i++;
		count++;
	}
	return (count);
}

int		ft_precisionskip(int i, const char *input, t_list *flags)
{
	int	count;

	count = 0;
	if (input[i] == '.')
	{
		i++;
		count++;
		flags->dotfound = 1;
		ft_getprecision(i, input, flags);
		while (ft_isdigit(input[i]))
		{
			i++;
			count++;
		}
	}
	return (count);
}
