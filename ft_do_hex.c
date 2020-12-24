/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_do_hex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 14:08:40 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/12/07 17:33:08 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_hex_zero(t_print *print, t_list1 *info)
{
	if (print->pad_amount > 0)
		ft_memset(print->pad, ' ', print->pad_amount);
	ft_putstr(print->pad);
	info->total_chars_printed += ft_strlen(print->pad);
	ft_free_hex(print);
	return (1);
}

int			ft_no_minuss(t_print *p, t_list1 *f)
{
	long	len;

	len = ft_strlen(p->arg);
	if (p->dot_present == 1)
		return (ft_no_minuss_dot(p, f));
	if (p->dot_present == 0)
		return (ft_no_minuss_no_dot(p, f));
	if (len > p->pad_amount)
	{
		ft_putstr(p->arg);
		f->total_chars_printed += len;
		ft_free_hex(p);
		return (1);
	}
	if (p->zero_present == 1 && p->pad_amount > len)
	{
		ft_memset(p->pad, '0', p->s - len);
		ft_memmove(p->pad + (p->s - len), p->arg, len);
		ft_putstr(p->pad);
		f->total_chars_printed += len;
	}
	ft_free_hex(p);
	return (1);
}

int			ft_minuss(t_print *p, t_list1 *f)
{
	long	len;

	len = ft_strlen(p->arg);
	if (p->d != 0)
		return (ft_minuss_dot(p, f, len));
	if (p->d == 0)
		return (ft_minuss_no_dot(p, f));
	if ((long)len > p->pad_amount)
	{
		ft_putstr(p->arg);
		f->total_chars_printed += len;
		ft_free_hex(p);
		return (1);
	}
	if (p->zero_present == 1 && p->pad_amount > (long)len)
	{
		ft_memset(p->pad + (p->s - len), '0', p->s - len);
		ft_memmove(p->pad, p->arg, len);
		ft_putstr(p->pad);
		f->total_chars_printed += ft_strlen(p->pad);
		ft_free_hex(p);
		return (1);
	}
	return (1);
}

static int	ft_continue_hex(t_list1 *info, va_list va, t_print *p)
{
	long	num;

	if (p->pad_amount >= INT_MAX - 1 || p->pad_amount < INT_MIN + 2)
		return (ft_free_c(p));
	if (p->d >= INT_MAX - 1 || p->d < INT_MIN + 2)
		return (ft_free_c(p));
	num = va_arg(va, int);
	p->arg = ft_convert_str_hex(num);
	if (p->arg == NULL)
		return (ft_free_hex(p));
	ft_get_pad(p);
	if (p->s == 0)
		return (0);
	if (p->arg[0] == '0' && p->d == 0 && p->dot_present)
		return (ft_hex_zero(p, info));
	if (p->minuss_present == 0)
		return (ft_no_minuss(p, info));
	else
		return (ft_minuss(p, info));
	return (0);
}

int			ft_do_hex(t_list1 *info, va_list va, t_print *print)
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
	if (!ft_continue_hex(info, va, print))
		return (0);
	return (1);
}
