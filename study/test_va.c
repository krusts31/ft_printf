#include <stdarh.h>
#include <stdio.h>

void	ft_function(char	*s, ...)
{
	va_list a;
	va_start(s, a);
	
}

int	main()
{
	printf("testing va_start");
	ft_function();
	return (0);
}
