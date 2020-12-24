#include "ft_printf.h"

int		ft_minuss_no_dot_int(t_print *p, t_list1 *f)
{
	if (p->pad_amount == 0 && p->n == 1)
		p->pad_amount = 1;
	if (p->zero_present == 0 || p->minuss_present)
		ft_memset(p->pad + p->n, ' ', p->pad_amount - p->n);
	else
		ft_memset(p->pad + p->n, '0', p->pad_amount - p->n);
	ft_memmove(p->pad + p->n, p->arg + p->n, ft_strlen(p->arg) - p->n);
	if (p->n == 1)
		ft_memmove(p->pad, "-", 1);
	ft_putstr(p->pad);
	f->total_chars_printed += ft_strlen(p->pad);
	ft_free_hex(p);
	return (1);
}

int		ft_minuss_dot_int(t_print *p, t_list1 *f, long l)
{
	if (p->pad_amount > (long)ft_strlen(p->arg) && p->pad_amount > p->d)
		ft_memset(p->pad, ' ', p->s);
	if ((long)ft_strlen(p->arg) <= p->d)
	{
		ft_memset(p->pad + p->n, '0', p->d - p->n);
		if (p->n == 1)
			ft_memset(p->pad, '-', 1);
		ft_memmove(p->pad + (p->d - (l - p->n)) + p->n, p->arg + p->n, l - p->n);
	}
	else
		ft_memmove(p->pad, p->arg, l);
	ft_putstr(p->pad);
	f->total_chars_printed += ft_strlen(p->pad);
	ft_free_hex(p);
	return (1);
}

int		ft_no_minuss_no_dot_int(t_print *p, t_list1 *f)
{
	long	l;

	l = (long)ft_strlen(p->arg);
	if (p->zero_present == 0)
	{
		if ((long)p->pad_amount - l > 0)
			ft_memset(p->pad, ' ', (p->pad_amount - l));
		if (p->n == 1)
			ft_memmove(p->pad + (p->s - l), "-", 1);
	}
	else
	{
		if ((long)p->pad_amount - l > 0)
			ft_memset(p->pad + p->n, '0', (p->pad_amount - l));
		if (p->n == 1)
			ft_memmove(p->pad, "-", 1);
	}
	ft_memmove(p->pad + (p->s - l)+ p->n, p->arg + p->n, l - p->n);
	ft_putstr(p->pad);
	f->total_chars_printed += ft_strlen(p->pad);
	ft_free_hex(p);
	return (1);
}
