/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_do_str.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 13:56:05 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/12/07 21:25:38 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_continue_str(t_list1 *info, va_list va, t_print *print)
{
	print->arg = va_arg(va, char *);
	if (print->arg == NULL)
		print->arg = ft_strdup("(null)");
	else
		print->arg = ft_strdup(print->arg);
	if (print->arg == NULL)
	{
		free (print);
		return (0);
	}
	ft_get_pad_str(print);
	if (print->s == 0 || print->arg == NULL)
		return (ft_free_hex(print));
	if (print->dot_present == 0)
		return (ft_str_no_dot(print, info));
	else 
		return (ft_str_dot(print, info));
}

int			ft_do_str(t_list1 *info, va_list va, t_print *print)
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
	if (!ft_continue_str(info, va, print))
		return (0);
	return (1);
}
