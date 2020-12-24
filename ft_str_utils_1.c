#include "ft_printf.h"

static void	ft_con_dot_no_min(t_print *p, long s)
{
	if (p->pad_amount != 0 && p->d != 0)
	{
		if (p->pad_amount - s >= 0)
			ft_memmove(p->pad + (p->pad_amount - s), p->arg, s);
		else
			ft_memmove(p->pad, p->arg, s);
			
	}
	else
		ft_memmove(p->pad, p->arg, s);
}

int		ft_str_dot_no_minuss(t_print *p, t_list1 *i)
{
	long	s;

	s = (long)ft_strlen(p->arg);
	if (p->pad_amount - p->d >= 0)
	{
		if (p->d <= s)
			ft_memmove(p->pad + (p->pad_amount - p->d), p->arg, p->d);
		else
			ft_memmove(p->pad + (p->pad_amount - s), p->arg, s);
	}
	else
	{
		ft_memset(p->pad, ' ', p->pad_amount);
		if (p->d <= s)
			ft_memmove(p->pad, p->arg, p->d);
		else
			ft_con_dot_no_min(p, s);
	}
	ft_putstr(p->pad);
	i->total_chars_printed += ft_strlen(p->pad);
	ft_free_hex(p);
	return (1);
}
