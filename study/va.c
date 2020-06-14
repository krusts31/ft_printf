#include <stdio.h>
#include <stdarg.h>

void	print_ints(int num, ...)
{
	va_list	args;
	int	value;

	va_start(args, num);
	for (int i = 0; i < num; i++)
	{
		value = va_arg(args, int);
		printf("%s%d:\n %s%d\n","This is i:, ", i,"this is value:", value);
	}
	va_end(args);
}

int	main()
{
	print_ints(1, 2, 3, 4, 5);
	printf("%s\n\n", "Seccond run:");
	print_ints(5, 6, 7, 8, 10);
	return (0);
}
