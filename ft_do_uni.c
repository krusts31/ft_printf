/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_do_uni.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 13:56:21 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/12/06 20:59:41 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_continue_uni(t_list1 *info, va_list va, t_print *p)
{
	size_t	num;

	if (p->pad_amount >= INT_MAX - 1 || p->pad_amount < INT_MIN + 2)
		return (0);
	if (p->d >= INT_MAX - 1 || p->d < INT_MIN + 2)
		return (0);
	num = va_arg(va, int);
	p->a = ft_uitoa(num);
	if (p->a == NULL)
		return (0);
	ft_get_pad(p);
	if (p->s == 0)
		return (0);
	if (p->a[0] == '0' && p->d == 0 && p->dot_present)
		return (ft_hex_zero(p, info));
	if (p->minuss_present == 0)
		return (ft_no_minuss_int(p, info));
	else
		return (ft_minuss_int(p, info));
	return (0);
}

int			ft_do_uni(t_list1 *info, va_list va, t_print *p)
{
	size_t	index;

	index = 0;
	ft_init_print(p);
	while (info->cs[index] != '\0')
	{
		if (info->cs[index] == '-')
			p->minuss_present = 1;
		if (info->cs[index] == '0')
			p->zero_present = 1;
		if (info->cs[index] == '.')
			index = ft_cs_dot(info, p, index, va);
		if (info->cs[index] == '*')
			ft_cs_st(p, va);
		if (info->cs[index] > '0' && info->cs[index] <= '9')
		{
			p->pad_amount = ft_atoi(info->cs + index);
			index += (ft_intlen(p->pad_amount) - 1);
		}
		index++;
	}
	if (!ft_continue_uni(info, va, p))
		return (0);
	return (1);
}
