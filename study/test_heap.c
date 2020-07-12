#include <stdio.h>
#include <stdlib.h>
// does not work as I planed will switch to uing structs
void	foo(char	*s)
{
	int	x;

	x = (int)malloc(sizeof(int));
	x = 0;
	while (*s)
	{
		x++;
	}
}

void	print()
{
	printf("%d\n", &x);
}

int	main()
{
	char	test[] = "I am 5";
	foo(test);
	print();
	return (0);
}
