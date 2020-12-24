/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_do_%.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/15 10:29:53 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/12/06 08:24:40 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_continue_precentage1(t_print *print)
{
	char	*tmp;

	if (print->pad == NULL)
		return (ft_free_c(print));
	if (print->dot_present == 1 && print->pad_amount != 0)
		ft_memset(print->pad, ' ', print->pad_amount - 1);
	if (print->zero_present == 1 && print->minuss_present != 1)
		ft_memset(print->pad, '0', print->pad_amount - 1);
	if (print->minuss_present == 1)
		tmp = ft_strjoin("%", print->pad);
	else
		tmp = ft_strjoin(print->pad, "%");
	if (tmp == NULL)
		return (ft_free_hex(print));
	free(print->pad);
	print->pad = tmp;
	return (1);
}

static int	ft_continue_precentage(t_list1 *info, t_print *print)
{
	print->pad = ft_strdup("");
	if (print->pad_amount != 0)
	{
		free(print->pad);
		print->pad = ft_calloc(print->pad_amount + 1, sizeof(char));
		if (print->pad == NULL)
			return (ft_free_hex(print));
		if (print->pad_amount > 1)
			ft_memset(print->pad, ' ', print->pad_amount - 1);
	}
	if (!ft_continue_precentage1(print))
		return (0);
	if (ft_strlen(print->pad))
	{
		ft_putstr(print->pad);
		info->total_chars_printed += ft_strlen(print->pad);
	}
	else
	{
		write(1, "%", 1);
		info->total_chars_printed += 1;
	}
	free(print);
	return (1);
}

int			ft_do_precentage(t_list1 *info, va_list va, t_print *print)
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
			print->dot_present = 1;
		if (info->cs[index] == '*')
			ft_cs_st(print, va);
		if (info->cs[index] > '0' && info->cs[index] <= '9')
		{
			print->pad_amount = ft_atoi(info->cs + index);
			break ;
		}
		index++;
	}
	if (!ft_continue_precentage(info, print))
		return (0);
	return (1);
}
