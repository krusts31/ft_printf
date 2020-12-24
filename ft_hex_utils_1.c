/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_do_hex_1.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 21:19:52 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/12/06 20:54:37 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_no_minuss_dot(t_print *p, t_list1 *f)
{
	long	l;

	l = (long)ft_strlen(p->arg);
	if (p->pad_amount > (long)ft_strlen(p->arg) && p->pad_amount > p->d)
		ft_memset(p->pad, ' ', p->s - p->n);
	if ((long)ft_strlen(p->arg) < p->d)
	{
		ft_memset(p->pad + (p->s - p->d), '0', (p->d - (l - p->n)) + p->n);
		if (p->n == 1 && p->s - p->d != 0)
			ft_memmove(p->pad + ((p->s - p->d) - p->n), "-", 1);
		if (p->n == 1 && p->s - p->d == 0)
			ft_memmove(p->pad + (p->s - p->d), "-", 1);
		if (p->n == 1 && p->pad_amount < p->d)
			ft_memmove(p->pad + (p->s - l - 1) + 1, p->arg + 1, l - 1);
		else
			ft_memmove(p->pad + (p->s - (l + p->n)), p->arg + p->n, l - p->n);
	}
	else
		ft_memmove(p->pad + (p->s - l), p->arg, l);
	ft_putstr(p->pad);
	f->total_chars_printed += ft_strlen(p->pad);
	ft_free_hex(p);
	return (1);
}

int		ft_minuss_no_dot(t_print *p, t_list1 *f)
{
	if (p->zero_present == 0)
		ft_memset(p->pad + p->n, ' ', p->pad_amount - p->n);
	else
		ft_memset(p->pad + p->n, '0', p->pad_amount - p->n);
	ft_memmove(p->pad + p->n, p->arg + p->n, ft_strlen(p->arg) - p->n);
	if (p->n == 1)
		ft_memmove(p->pad, "-", 1);
	ft_putstr(p->pad);
	f->total_chars_printed += ft_strlen(p->pad);
	ft_free_hex(p);
	return (1);
}

int		ft_minuss_dot(t_print *p, t_list1 *f, long l)
{
	if (p->pad_amount > (long)ft_strlen(p->arg) && p->pad_amount > p->d)
		ft_memset(p->pad + p->n, ' ', p->s - p->n);
	if ((long)ft_strlen(p->arg) < p->d)
	{
		ft_memset(p->pad + p->n, '0', (p->d));
		if (p->n == 1)
		{
			ft_memmove(p->pad, "-", 1);
			ft_memmove(p->pad + (p->d - (l + p->n)) + 1, p->arg + 1, l - 1);
		}
		else
			ft_memmove(p->pad + (p->d - l), p->arg, l);
	}
	else
	{
		ft_memmove(p->pad + p->n, p->arg + p->n, ft_strlen(p->arg) - p->n);
		if (p->n == 1)
			ft_memmove(p->pad, "-", 1);
	}
	ft_putstr(p->pad);
	f->total_chars_printed += ft_strlen(p->pad);
	ft_free_hex(p);
	return (1);
}

int		ft_no_minuss_no_dot(t_print *p, t_list1 *f)
{
	long	l;

	l = (long)ft_strlen(p->arg);
	if (p->zero_present == 0)
	{
		if ((long)p->pad_amount - l > 0)
			ft_memset(p->pad, ' ', (p->pad_amount - l));
		if (p->n == 1)
			ft_memmove(p->pad + (p->s - l), "-", 1);
	}
	else
	{
		if ((long)p->pad_amount - l > 0)
			ft_memset(p->pad + p->n, '0', (p->pad_amount - l));
		if (p->n == 1)
			ft_memmove(p->pad, "-", 1);
	}
	ft_memmove(p->pad + (p->s - l) + p->n, p->arg + p->n, l - p->n);
	ft_putstr(p->pad);
	f->total_chars_printed += ft_strlen(p->pad);
	ft_free_hex(p);
	return (1);
}

int	ft_free_hex(t_print *p)
{
	free(p->pad);
	free(p->arg);
	free(p);
	return (0);
}
