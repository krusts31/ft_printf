/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_do_char.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 12:58:29 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/12/06 20:33:34 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_res(char *pad, char *c, t_list1 *info, t_print *print)
{
	if (ft_strlen(pad))
	{
		ft_putstr(pad);
		info->total_chars_printed += ft_strlen(pad);
	}
	else if (c)
	{
		ft_putstr(c);
		info->total_chars_printed += ft_strlen(c);
	}
	else
	{
		ft_putstr(c);
		info->total_chars_printed += 2;
	}
	free(pad);
	free(print);
	free(c);
	return (1);
}

static int	ft_arg_memset(t_print *print, char **pad, char **c)
{
	if (print->dot_present == 1 && print->pad_amount != 0)
		ft_memset(*pad, ' ', print->pad_amount - ft_strlen(*c));
	if (print->zero_present == 1 && print->minuss_present != 1)
		ft_memset(*pad, '0', print->pad_amount - ft_strlen(*c));
	if (print->minuss_present == 1)
		*pad = ft_strjoin(*c, *pad);
	else
		*pad = ft_strjoin(*pad, *c);
	if (*pad == NULL)
	{
		free(*c);
		return (ft_free_c(print));
	}
	return (1);
}

static int	ft_arg(t_print *print, int value, char **pad, char **c)
{
	*c = ft_calloc(2, sizeof(char));
	if (*c == NULL)
		return (ft_free_c(print));
	*c[0] = (char)value;
	if (print->pad_amount != 0)
	{
		*pad = ft_calloc(print->pad_amount + 1, sizeof(char));
		if (*pad == NULL)
		{
			free(*c);
			return (ft_free_c(print));
		}
		if (print->pad_amount > (long)ft_strlen(*c))
			ft_memset(*pad, ' ', print->pad_amount - ft_strlen(*c));
	}
	return (ft_arg_memset(print, pad, c));
}

static int	ft_continue_char(t_list1 *info, va_list va, t_print *p)
{
	int		arg;
	char	*c;
	char	*pad;

	c = NULL;
	pad = "\0";
	if (p->pad_amount >= INT_MAX - 1 || p->pad_amount < INT_MIN + 2)
		return (ft_free_c(p));
	if (p->pad_amount < 0)
		p->pad_amount = -p->pad_amount;
	arg = va_arg(va, int);
	if (arg == 0)
	{
		write(1, "", 1);
		info->total_chars_printed += 1;
		return (1);
	}
	if (arg)
	{
		if (!ft_arg(p, arg, &pad, &c))
			return (0);
	}
	return (ft_print_res(pad, c, info, p));
}

int			ft_do_char(t_list1 *info, va_list va, t_print *print)
{
	size_t	index;

	ft_init_print(print);
	index = 0;
	while (info->cs[index] != '\0')
	{
		if (info->cs[index] == '-')
			print->minuss_present = 1;
		if (info->cs[index] == '0')
			print->zero_present = 1;
		if (info->cs[index] == '*')
			ft_cs_st(print, va);
		if (info->cs[index] > '0' && info->cs[index] <= '9')
		{
			print->pad_amount = ft_atoi(info->cs + index);
			break ;
		}
		index++;
	}
	if (!ft_continue_char(info, va, print))
		return (0);
	return (1);
}
