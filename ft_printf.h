#ifndef FT_PRINT_H
# define FT_PRINT_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

//why am I ussing 3 different lists?
//well becuase different values are initizailzed in different places 
//so It also saves time for iteraiting throw the list:q:qq

/*	What are all the possible flags?
 *	Mandatory 	"-0.*"		total of: 4
 *	Bonus		"# +"		total of: 3
 *	Combain		"-0.*# +"	total of: 7
 *
 *	What are all the possible combinations for flags?
 */

typedef struct	s_list3
{
	int	minuss_present;
	int	zero_present;
	int	dot_present;
	int	pad_amount;
}				t_print;

typedef struct	s_list2
{
	int	total_chars_printed;
	int	length_of_cs_string;
	int	length_of_cs;
	char	*conversion_specifier;
}				t_list1;

typedef struct	s_list4
{
	char	c;
	int	(*f)(t_list1	*, va_list	*, t_print *);
}				t_function;

char	*ft_find(const char     *s, t_list1 *info);
int		ft_printf(const char *str, ...);
char	*ft_chop(const char	*s);
int		find_my_purpuse(t_list1	*info, va_list *va, const char	*str);
int		ft_do_int(t_list1 *info, va_list *va, t_print *print);
int		ft_do_char(t_list1 *info, va_list *va, t_print *print);
int		ft_do_ptr(t_list1 *info, va_list *va, t_print *print);
int		ft_do_uni(t_list1 *info, va_list *va, t_print *print);
int		ft_do_hex(t_list1 *info, va_list *va, t_print *print);
int		ft_do_helx(t_list1 *info, va_list *va, t_print *print);
int		ft_do_str(t_list1 *info, va_list *va, t_print *print);

#endif
