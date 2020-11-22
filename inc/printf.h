/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 13:19:00 by lsmit          #+#    #+#                */
/*   Updated: 2020/01/21 17:36:36 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_list
{
	int		spaces;
	int		precision;
	int		ogprecision;
	int		iszero;
	int		ret;
	int		width;
	int		origwidth;
	void	*input;
	int		negative;
	int		dotfound;
	int		left;
	int		minus;
	int		percent;
	int		printed;
	int		errorcheck;
	int		pointerdot;
}				t_list;

int				ft_printf(const char *input, ...);
int				ft_inputlen(int i, const char *input, void *arg, t_list *flags);
int				ft_intlen(int in, t_list *flags);
int				ft_xlen(unsigned long n);
int				ft_plen(unsigned long n, int dotpointer, t_list *flags);
int				ft_unsignedlen(long long in, t_list *flags);
int				ft_skipwidth(const char *input, int i);
int				ft_skipflags(const char *input, int i);
int				ft_precisionskip(int i, const char *input, t_list *flags);
int				ft_dotstar(int i, const char *input);
int				ft_checkconversion(int i, const char *input);
void			ft_percentwidth(t_list *flags);
unsigned int	ft_getwidth(int i, const char *input, t_list *flags);
void			ft_getconversion
				(int i, const char *input, t_list *flg);
void			ft_c(char c, t_list *flags);
void			ft_printint(int nb, t_list *flags);
void			ft_printstr(char *str, t_list *flags);
void			ft_printpointer(unsigned long ad, t_list *flags);
void			ft_printu(unsigned int n, t_list *flags);
void			ft_putnbrhex(unsigned long n, t_list *flags);
void			ft_printsmallx(unsigned int n, t_list *flags);
void			ft_printbigx(unsigned int n, t_list *flags);
void			ft_zerospaceprinter(int len, t_list *f);
void			ft_printminus(t_list *flags);
void			ft_printspaceatend(t_list *flags);
void			ft_structnull(t_list *flags);
void			ft_getprecision
				(int i, const char *input, t_list *flags);
void			ft_yesdotstar
				(int i, const char *input, va_list args, t_list *flags);
void			ft_nodotstar(
				int i, const char *input, va_list args, t_list *flags);
void			ft_widthzeroflag(int i, const char *input, t_list *flags);
void			ft_widthzeroflag2(int i, const char *input, t_list *flags);

void			ft_putchar(char c, t_list *flags);
void			ft_putnbr(int n, t_list *flags);
void			ft_putstr(char *s, t_list *flags);
int				ft_atoi(char *str);
int				ft_strlen(char *str);
char			*ft_itoa(long long n, t_list *flags);
int				ft_isdigit(int c);

#endif
