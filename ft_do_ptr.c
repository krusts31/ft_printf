/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_do_ptr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 13:55:53 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/12/25 13:50:21 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_continue_ptr(t_list1 *info, va_list va, t_print *print)
{
	unsigned long	num;
	char			*tmp;

	tmp = NULL;
	num = va_arg(va, unsigned long);
	print->arg = ft_convert_str_ptr(num);
	if (print->arg == NULL)
		return (ft_free_hex(print));
	if (num != 0)
		tmp = ft_strjoin("0x", print->arg);
	if (tmp == NULL && num != 0)
		return (ft_free_hex(print));
	if (tmp != NULL)
		ft_con_ptr(print, tmp);
	ft_get_pad(print);
	if (print->s == 0)
		return (ft_free_hex(print));
	if (print->arg[0] == '0' && print->d == 0 && print->dot_present)
		return (ft_hex_zero(print, info));
	if (print->minuss_present == 0)
		return (ft_no_minuss(print, info));
	else
		return (ft_minuss(print, info));
	return (ft_free_hex(print));
}

static int	ft_mid(t_list1 *info, va_list va, t_print *p)
{
	if (p->pad_amount >= INT_MAX - 1 || p->pad_amount < INT_MIN + 2)
		return (ft_free_c(p));
	if (p->d >= INT_MAX - 1 || p->d < INT_MIN + 2)
		return (ft_free_c(p));
	return (ft_continue_ptr(info, va, p));
}

int			ft_do_ptr(t_list1 *info, va_list va, t_print *print)
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
	if (!ft_mid(info, va, print))
		return (0);
	return (1);
}
