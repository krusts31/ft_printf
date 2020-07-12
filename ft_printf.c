#include "ft_printf.h"

/*
 *
 *
 * Got to make the va_list to work
 * I think I got it 16.06 moving to makinf a struct and making the struct work with the code
 * using a struct because it an easy way to keep track of some of the varibles used by printf_f like the length
 * It compails and the previus functionalit is still working with a struct
 * ??? whts the difference between using -> and . opertator when accsesing varibles from a struct ???
 * prints out the cahrs which are not asociated with %
 * After that make a Makefile
 * Clean up and make it work with libft
 *? Ask how do it?
 *
 */
//dspciuxX
t_function g_var[9] = {
	{'d', &ft_do_int},
	{'c', &ft_do_char},
	{'s', &ft_do_str},
	{'p', &ft_do_ptr},
	{'i', &ft_do_int},
	{'u', &ft_do_uni},
	{'x', &ft_do_hex},
	{'X', &ft_do_helx},
	{'\0', NULL}
};

int	ft_pad_amount(char	*conversion_specifier)
{
	int x;
	int	pad_amount;

	x = 0;
	while (ft_isdigit(conversion_specifier[x]))
	{
		pad_amount = pad_amount * 10 + ft_atoi((const char *)conversion_specifier[x]);
		x++;
	}
	return (0);
}

int	ft_do_int(char	*conversion_specifier, va_list	*va, t_print *print)
{
	int	t;
	int	d;

	d = va_arg(*va, int);
	printf("this is d for function ft_do_int: %d\n", d);
	t = 0;
	while (conversion_specifier[t] != '\0')
	{
		if (conversion_specifier[t] == '-')
			print->print_lr = 1;
		if (conversion_specifier[t] == '0')
			print->zero_present = 1;
		if (conversion_specifier[t] == '.')
			print->zero_present = 1;
		if (conversion_specifier[t] == '*')
			//* is used for dynamic input, for example if there is a string with more than 8 byts then only print 4 and to specifay 4 yu have to pass an argument before that
		if (conversion_specifier[t] > 0 && conversion_specifier[t] <= 9)
			print->pad_amount = ft_pad_amount(conversion_specifier + t);
		t++;
	}
	return (1);
}

int	find_my_purpuse(t_list1	*info, va_list *va, const char	*str)
{
	int		i;
	t_print *print;

	print = ft_calloc(sizeof(t_print), 1);
	if (print == NULL)
		return (0);
	while(str[info->length_of_cs_find] != '\0')
	{
		i = 0;
		while (g_var[i].c != '\0')
		{
			if (g_var[i].c == str[info->length_of_cs_find])
				g_var[i].f(info->conversion_specifier, va, print);
			i++;
		}
		info->length_of_cs_find++;
	}
	return (0);
}

char	*ft_chop(const char	*s)
{
	int		x;
	char	*conversion_specifier;

	x = 0;
	while (s[x] != '\0')
	{
		if (s[x] == 'c' || s[x] == 's' || s[x] == 'p'|| s[x] == 'd' || s[x] == 'i' || s[x] == 'u' || s[x] == 'x' || s[x] == 'X')
		{
			conversion_specifier = ft_calloc(x + 1, sizeof(char));
			if (conversion_specifier == NULL)
				return (NULL);
			conversion_specifier = ft_memmove(conversion_specifier, s, x + 1);
			return (conversion_specifier);
		}
		x++;
	}
	return (NULL);
}

char	*ft_find(const char	*s, t_list1 *info)
{
	if (s == NULL)
		return (0);
	while (s[info->length_of_cs_string] != '\0')
	{
		if (s[info->length_of_cs_string] == '%')
		{
			info->conversion_specifier = ft_chop(&s[info->length_of_cs_string]);
			info->length_of_cs_string = info->length_of_cs_string + ft_strlen(info->conversion_specifier);
			info->length_of_cs_string = info->length_of_cs_string;
			return (info->conversion_specifier);
		}
		else
		{
			ft_putchar(s[info->length_of_cs_string]);
			info->total_chars_printed = info->total_chars_printed + 1;
			info->length_of_cs_string = info->length_of_cs_string + 1;
		}
	}
	return (info->conversion_specifier);
}

void	ft_how_many_cs(char	*snakes)
{
	(void)snakes;
}

int	ft_printf(const char *str, ...)
{
	t_list1 *info;
	va_list	va;

	info = ft_calloc(sizeof(t_list1), 1);
	if (info == NULL)
		return (0);
	info->length_of_cs_find = 0;
	info->length_of_cs_string = 0;
	while (str[info->length_of_cs_string] != '\0')
	{
		info->conversion_specifier = ft_find(str, info);
		va_start(va, str);
		find_my_purpuse(info, &va, str);
	}
	return (info->total_chars_printed);
}

int     main()
{
		const char	pptr[] = "Hello World%010.5dHello%.5s%x  %DX     %0.10X        %lx    \0";
		//the va does not work
		//the full string is not printed out
        ft_printf(pptr, 69, "Hello world", 42, 21, 100, 1);
        return(0);
}
