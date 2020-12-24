#include "ft_printf.h"

int	ft_free_c(t_print *print)
{
	free(print);
	return (0);
}

void	ft_con_ptr(t_print *print, char *tmp)
{
	free(print->arg);
	print->arg = tmp;
}
