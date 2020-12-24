/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_int_utils_1.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/06 08:43:32 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/12/06 21:17:57 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_no_minuss_int(t_print *p, t_list1 *f)
{
	long	len;

	len = ft_strlen(p->arg);
	if (p->dot_present == 1)
		return (ft_no_minuss_dot_int(p, f));
	if (p->dot_present == 0)
		return (ft_no_minuss_no_dot_int(p, f));
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

int			ft_minuss_int(t_print *p, t_list1 *f)
{
	long	len;

	len = ft_strlen(p->arg);
	if (p->d != 0)
		return (ft_minuss_dot_int(p, f, len));
	if (p->d == 0)
		return (ft_minuss_no_dot_int(p, f));
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
	}
	return (1);
}

int		ft_no_minuss_dot_int(t_print *p, t_list1 *f)
{
	long	l;

	l = (long)ft_strlen(p->arg);
	if (p->pad_amount > (long)ft_strlen(p->arg) && p->pad_amount > p->d)
		ft_memset(p->pad, ' ', p->s);
	if ((long)ft_strlen(p->arg) <= p->d)
	{
		ft_memset(p->pad + (p->s - p->d), '0', (p->d));
		if (p->n == 1 && p->s - p->d != 0)
			ft_memmove(p->pad + ((p->s - p->d) - p->n), "-", 1);
		if (p->n == 1 && p->s - p->d == 0)
			ft_memmove(p->pad + (p->s - p->d), "-", 1);
		if (p->pad_amount <= p->d)
			ft_memmove(p->pad + (p->s - (l - p->n)) + p->n, p->arg + p->n, l - p->n);
		if (p->pad_amount > p->d)
			ft_memmove(p->pad + (p->s - (l - p->n)), p->arg + p->n, l - p->n);
	}
	else
		ft_memmove(p->pad + (p->s - l), p->arg, l);
	ft_putstr(p->pad);
	f->total_chars_printed += ft_strlen(p->pad);
	ft_free_hex(p);
	return (1);
}
