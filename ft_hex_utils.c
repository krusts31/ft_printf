/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hex_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 14:55:49 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/12/13 13:08:51 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_hexlen(long nr)
{
	int	ret;

	ret = 0;
	if (nr == 0)
		return (1);
	if (nr == -2147483648)
		return (0);
	if (nr < 0)
	{
		nr = -nr;
		ret++;
	}
	while (nr >= 1)
	{
		ret++;
		nr = nr / 16;
	}
	return (ret);
}

char	*ft_convert_str_hex(long integer)
{
	char		*ptr;
	int		length_of_integer;
	long	remainer;

	if (integer == 0)
		return (ft_strdup("0"));
	if (integer < 0)
		integer = UINT_MAX + (integer + 1);
	length_of_integer = ft_hexlen(integer);
	ptr = ft_calloc(length_of_integer + 1, sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (integer && length_of_integer >= 0)
	{
		length_of_integer--;
		remainer = integer % 16;
		if (remainer < 10)
			ptr[length_of_integer] = 48 + remainer;
		else
			ptr[length_of_integer] = 87 + remainer;
		integer = integer / 16;
	}
	return (ptr);
}

char	*ft_convert_str_helx(long integer)
{
	char		*helx;
	int		length_of_integer;
	long	remainer;

	if (integer == 0)
		return (ft_strdup("0"));
	if (integer < 0)
		integer = UINT_MAX + (integer + 1);
	length_of_integer = ft_hexlen(integer);
	helx = ft_calloc(length_of_integer + 1, sizeof(char));
	if (helx == NULL)
		return (NULL);
	while (integer && length_of_integer >= 0)
	{
		length_of_integer--;
		remainer = integer % 16;
		if (remainer < 10)
			helx[length_of_integer] = 48 + remainer;
		else
			helx[length_of_integer] = 55 + remainer;
		integer = integer / 16;
	}
	return (helx);
}

void	ft_get_pad(t_print *print)
{
	if (print->arg[0] == '-')
		print->n = 1;
	if (print->pad_amount < 0)
		print->pad_amount = -print->pad_amount;
	if (print->pad_amount >= print->d)
		print->s = print->pad_amount;
	if (print->pad_amount <= print->d)
		print->s = print->d;
	if (print->s <= ft_strlen(print->arg))
		print->s = ft_strlen(print->arg);
	if (print->n == 1)
		print->pad = ft_calloc(print->s + 2, sizeof(char));
	else
		print->pad = ft_calloc(print->s + 1, sizeof(char));
	if (print->pad == NULL)
		print->s = 0;
}

void	ft_get_pad_str(t_print *print)
{
	if (print->d < 0)
		print->d = ft_strlen(print->arg); 
	if (print->pad_amount < 0)
		print->pad_amount = -print->pad_amount;
	if (print->pad_amount >= print->d)
		print->s = print->pad_amount;
	if (print->pad_amount <= print->d)
		print->s = print->d;
	if (print->s <= ft_strlen(print->arg))
		print->s = ft_strlen(print->arg) + 1;
	if (print->n == 1)
		print->pad = ft_calloc(print->s + 2, sizeof(char));
	else
		print->pad = ft_calloc(print->s + 1, sizeof(char));
	if (print->pad == NULL)
		print->s = 0;
}
