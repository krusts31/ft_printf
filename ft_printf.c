/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 17:41:03 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/12/25 13:48:42 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_function g_var[10] = {
	{'d', &ft_do_int},
	{'c', &ft_do_char},
	{'s', &ft_do_str},
	{'p', &ft_do_ptr},
	{'i', &ft_do_int},
	{'u', &ft_do_uni},
	{'x', &ft_do_hex},
	{'X', &ft_do_helx},
	{'%', &ft_do_precentage},
	{'\0', NULL}
};

static int	find_my_purpuse(t_list1 *info, va_list va)
{
	int		i;
	t_print *print;

	info->length_of_cs = 0;
	print = ft_calloc(sizeof(t_print), 1);
	if (print == NULL)
		return (0);
	while (info->cs[info->length_of_cs] != '\0')
	{
		info->length_of_cs++;
		i = 0;
		while (g_var[i].c != '\0')
		{
			if (g_var[i].c == info->cs[info->length_of_cs])
			{
				if (!g_var[i].f(info, va, print))
					return (0);
				else
					return (1);
			}
			i++;
		}
	}
	return (1);
}

static char	*ft_chop(const char *s)
{
	int		x;
	char	*cs;

	x = 0;
	while (s[x] != '\0')
	{
		x++;
		if (ft_strchr("cspdiuxX%", s[x]))
		{
			cs = ft_calloc(x + 2, sizeof(char));
			if (cs == NULL)
				return (NULL);
			cs = ft_memmove(cs, s, x + 1);
			return (cs);
		}
	}
	return (NULL);
}

static char	*ft_find(const char *s, t_list1 *info)
{
	while (s[info->length_of_cs_string] != '\0')
	{
		if (s[info->length_of_cs_string] == '%')
		{
			info->cs = ft_chop(&s[info->length_of_cs_string]);
			if (info->cs == NULL)
				return (NULL);
			info->length_of_cs_string = info->length_of_cs_string +
				ft_strlen(info->cs);
			return (info->cs);
		}
		else
		{
			ft_putchar(s[info->length_of_cs_string]);
			info->total_chars_printed = info->total_chars_printed + 1;
			info->length_of_cs_string = info->length_of_cs_string + 1;
		}
	}
	if (s[info->length_of_cs_string] == '\0')
		return (NULL);
	return (info->cs);
}

int			ft_printf(const char *str, ...)
{
	t_list1 *info;
	va_list	va;

	va_start(va, str);
	info = ft_calloc(sizeof(t_list1), 1);
	if (info == NULL)
		return (ft_free_in(info, va));
	info->length_of_cs_string = 0;
	while (str[info->length_of_cs_string] != '\0')
	{
		info->cs = ft_find(str, info);
		if (info->cs == NULL)
			return (info->total_chars_printed);
		if (!find_my_purpuse(info, va))
			return (ft_free_in(info, va));
	}
	ft_free_in(info, va);
	return (info->total_chars_printed);
}
