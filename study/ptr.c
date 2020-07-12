#include <stdio.h>

int	main()
{
	int	*a, b;

	b = 4;
	a = &b;

	printf("%d\n%d\n", *a, b);
	return (0);
}
