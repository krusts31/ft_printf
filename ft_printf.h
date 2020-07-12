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

typedef struct	s_list3
{
	int	print_lr;
	int	zero_present;
	int	pad_amount;
}				t_print;

typedef struct	s_list2
{
	int	total_chars_printed;
	int	length_of_cs_string;
	int	length_of_cs_find;
	char	*conversion_specifier;
}				t_list1;

typedef struct	s_list4
{
	char	c;
	int	(*f)(char	*, va_list	*, t_print *);
}				t_function;

char	*ft_find(const char     *s, t_list1 *info);
int		ft_printf(const char *str, ...);
char	*ft_chop(const char	*s);
int		find_my_purpuse(t_list1	*info, va_list *va, const char	*str);
int		ft_do_int(char	*conversion_specifayer, va_list	*va, t_print *print);
int		ft_do_char(char *conversion_specifayer, va_list *va, t_print *print);
int		ft_do_ptr(char	*conversion_specifayer, va_list	*va, t_print *print);
int		ft_do_uni(char	*conversion_specifayer, va_list	*va, t_print *print);
int		ft_do_hex(char	*conversion_specifayer, va_list *va, t_print *print);
int		ft_do_helx(char	*conversion_specifayer, va_list *va, t_print *print);
int		ft_do_str(char	*conversion_specifayer, va_list	*va, t_print *print);

#endif
