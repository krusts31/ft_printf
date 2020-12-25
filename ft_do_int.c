/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_do_int.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 19:22:09 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/12/25 13:37:00 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_continue_int(t_list1 *info, va_list va, t_print *p)
{
	size_t	num;

	if (p->pad_amount >= INT_MAX - 1 || p->pad_amount < INT_MIN + 2)
		return (ft_free_c(p));
	if (p->d >= INT_MAX - 1 || p->d < INT_MIN + 2)
		return (ft_free_c(p));
	num = va_arg(va, int);
	p->arg = ft_itoa(num);
	if (p->arg == NULL)
		return (ft_free_hex(p));
	ft_get_pad(p);
	if (p->s == 0)
	{
		ft_free_hex(p);
		return (0);
	}
	if (p->arg[0] == '0' && p->d == 0 && p->dot_present)
		return (ft_hex_zero(p, info));
	if (p->minuss_present == 0)
		return (ft_no_minuss_int(p, info));
	else
		return (ft_minuss_int(p, info));
	return (0);
}

int			ft_do_int(t_list1 *info, va_list va, t_print *print)
{
	size_t	index;

	index = 0;
	ft_init_print(print);
	while (info->cs[index] != '\0')
	{
		if (info->cs[index] == '-')
			print->minuss_present = 1;
		if (info->cs[index] == '0')
			print->zero_present = 1;
		if (info->cs[index] == '.')
			index = ft_cs_dot(info, print, index, va);
		if (info->cs[index] == '*')
			ft_cs_st(print, va);
		if (info->cs[index] > '0' && info->cs[index] <= '9')
		{
			print->pad_amount = ft_atoi(info->cs + index);
			index += (ft_intlen(print->pad_amount) - 1);
		}
		index++;
	}
	if (!ft_continue_int(info, va, print))
		return (0);
	return (1);
}
