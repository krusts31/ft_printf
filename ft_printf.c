#include "ft_printf.h"

/*
 *Started 16.06
 *
 *		!! Free conversion_specifier (created in ft_chop) afeter it no longer needed
 *		!! Look for all calloc failurs nad see how the flow in returned
 *		!! Meory managament needs fixing !!
 *		!! FOCUS on undestaning what is happening in memortty and what do you need to free
 *		!!  and what to keep !!
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

int	ft_continue(t_list1 *info, va_list *va, t_print *print)
{
	char	*integer;
	char	*pad;

	integer = ft_itoa(va_arg(*va, int));
	if (print->pad_amount != 0)
		pad = ft_calloc(print->pad_amount, sizeof(char));
	if (print->dot_present == 0)
		ft_memset(pad, ' ', print->pad_amount);
	else if (print->dot_present == 1)
		ft_memset(pad, '0', print->pad_amount);
	if (print->minuss_present == 0)
		ft_strlcat(pad, integer, 10);
	if (pad)
		write(1, pad, ft_strlen(pad));
	else if (integer)
		write(1, pad, ft_strlen(integer));
	info->total_chars_printed += ft_strlen(integer);
	return (0);
}

int	ft_do_int(t_list1 *info, va_list *va, t_print *print)
{
	int	t;

	t = 0;
	while (info->conversion_specifier[t] != '\0')
	{
		if (info->conversion_specifier[t] == '-')
			print->minuss_present = 1;
		if (info->conversion_specifier[t] == '0')
			print->zero_present = 1;
		if (info->conversion_specifier[t] == '.')
			print->dot_present = 1;
		if (info->conversion_specifier[t] == '*')
			print->pad_amount = va_arg(*va, int);
		if (info->conversion_specifier[t] > 0 && info->conversion_specifier[t] <= 9)
			print->pad_amount = print->pad_amount * 10 + ft_atoi(info->conversion_specifier + t);
		t++;
	}
	ft_continue(info, va, print);
	return (1);
}

/*
**	this place probablly has a bug because it goes over the src string and if it finds on of the chars in g_var
**	then it will go to the specific function but we would like to do it from the cs specifier no need to use
**	the src string
**	this is the place ehre the while loop gets incermented 
*/

int	find_my_purpuse(t_list1	*info, va_list *va, const char	*str)
{
	int		i;
	t_print *print;

	info->length_of_cs = 0;
	print = ft_calloc(sizeof(t_print), 1);
	if (print == NULL)
		return (0);
	while(info->conversion_specifier[info->length_of_cs] != '\0')
	{
		i = 0;
		while (g_var[i].c != '\0')
		{
			if (g_var[i].c == info->conversion_specifier[info->length_of_cs])
				g_var[i].f(info, va, print);
			i++;
		}
		info->length_of_cs++;
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

/*	ft_chop returns a conversion specifayer
**	we store the lebgth of a conversion specifayer
**	if we dont find a % we are printing chars
**	and adding the amount of chars printed
**	and incremeing the src string to find all the cs in source stringi
**	return the source string to
**	!do I need to increment the src string in the if statement?!
**	!optimaiz the ft_putchar not to put call 1 char at a time but to do ot for the ehole buffer!
*/

char	*ft_find(const char	*s, t_list1 *info)
{
	while (s[info->length_of_cs_string] != '\0')
	{
		if (s[info->length_of_cs_string] == '%')
		{
			info->conversion_specifier = ft_chop(&s[info->length_of_cs_string]);
			info->length_of_cs_string = info->length_of_cs_string + ft_strlen(info->conversion_specifier);
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

//	finds the conversion specifier and stores it into info->conversion_specifier
//	passed va_list, t_list1 struct and the specifayer string to a processing function
//	return the total amount of chars printed

int	ft_printf(const char *str, ...)
{
	t_list1 *info;
	va_list	va;

	info = ft_calloc(sizeof(t_list1), 1);
	if (info == NULL)
		return (0);
	info->length_of_cs_string = 0;
	while (str[info->length_of_cs_string] != '\0')
	{
		info->conversion_specifier = ft_find(str, info);
		va_start(va, str);
		find_my_purpuse(info, &va, str);
		free(info->conversion_specifier);
	}
	return (info->total_chars_printed);
}

int     main()
{
		const char	pptr[] = "Hello World%*dHello%.5s%d  %d     %d        %lx    ";
		//the va does not work
		//the full string is not printed out
	printf("This is the arguments: 69, Hello World, 42, 21, 100, 1\n");
	printf("This is the pointer : %s\n", pptr);
        ft_printf(pptr, 69, "Hello world", 42, 21, 100, 1);
	printf("\n\n\nthis is a the same out put from printf\n\n\n");
	printf(pptr, 20, 69, "Hello world", 42, 21, 100, 1000000000000000000);
        return(0);
}
