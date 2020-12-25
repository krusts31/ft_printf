/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 13:54:52 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/12/25 13:49:22 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str_no_dot_minuss(t_print *p, t_list1 *i)
{
	long	s;

	s = (long)ft_strlen(p->arg);
	ft_memmove(p->pad, p->arg, s);
	ft_putstr(p->pad);
	i->total_chars_printed += ft_strlen(p->pad);
	ft_free_hex(p);
	return (1);
}

int	ft_str_dot(t_print *p, t_list1 *i)
{
	if (p->pad_amount != 0)
		ft_memset(p->pad, ' ', p->pad_amount);
	if (p->minuss_present == 1)
		return (ft_str_dot_minuss(p, i));
	return (ft_str_dot_no_minuss(p, i));
}

int	ft_str_no_dot(t_print *p, t_list1 *i)
{
	if (p->pad_amount != 0)
		ft_memset(p->pad, ' ', p->pad_amount);
	if (p->minuss_present == 1)
		return (ft_str_no_dot_minuss(p, i));
	return (ft_str_no_dot_no_minuss(p, i));
}

int	ft_str_dot_minuss(t_print *p, t_list1 *i)
{
	long	s;

	if (((long)ft_strlen(p->arg) - p->d) >= 0)
		s = p->d;
	else
		s = (long)ft_strlen(p->arg);
	ft_memmove(p->pad, p->arg, s);
	ft_putstr(p->pad);
	i->total_chars_printed += ft_strlen(p->pad);
	ft_free_hex(p);
	return (1);
}

int	ft_str_no_dot_no_minuss(t_print *p, t_list1 *i)
{
	long	s;

	s = (long)ft_strlen(p->arg);
	if (p->pad_amount - s > 0)
		ft_memmove(p->pad + (p->pad_amount - s), p->arg, s);
	else
		ft_memmove(p->pad, p->arg, s);
	ft_putstr(p->pad);
	i->total_chars_printed += ft_strlen(p->pad);
	ft_free_hex(p);
	return (1);
}
