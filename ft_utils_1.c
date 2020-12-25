/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utils_1.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/25 13:48:06 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/12/25 13:48:18 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_free_c(t_print *print)
{
	free(print);
	return (0);
}

void	ft_con_ptr(t_print *print, char *tmp)
{
	free(print->arg);
	print->arg = tmp;
}

int		ft_free_in(t_list1 *info, va_list va)
{
	va_end(va);
	free(info->cs);
	free(info);
	return (-1);
}
