#include <stdio.h>

int	main()
{
	
	printf("\033[1mSome Rulles:\033[0m\n");
	printf("\033[1mIt must have some arguments in it or it does not work\033[0m\n");
	printf("\033[0;31mtoo few arguments to function ‘printf’ printf();\033[0m\n");
	printf("\033[1mint longs are printed with ld\033[0m\n");
	printf("\033[0;31mit expects the first argument to be a char so you can just print numbers or anything that is not a string\033[0m\n");
	printf("format ‘d’ expects argument of type ‘int’, but argument 2 has type ‘long int’");
	printf("format ‘d’ expects argument of type ‘int’, but argument 2 has type ‘double’");
	printf("%s\n\n", "		Starting to test printf!");
	printf("%s\n", "Testing with manual input");
	printf("%s%s\n", "Testing%s	", "string");
	printf("%s%s\n", "Testing%s	", "s");
	printf("%s%s\n", "Testing%s	", "~!@#$%^&*()_+QWERTYUIOP{}|:LKJHGFDSAZXCVBNM<>?");
	printf("%s%s\n", "Testing%s	", "	. .<");
	printf("%s", "");
	printf("%s%s\n", "Testing%s	", "");
	printf("%s%d\n", "Testing%d	", 11234);
	printf("%s%c\n", "Testing%c	", 'c');
	printf("%s% d\n", "TEstinf% +d", -42);

	printf("%s\n\n", "		rrina tests");
	printf("%10.5s\n", "testing %%10.5s");
	printf("%-10.5s\n", "testing %%-10.5s");
	printf("%10.5s\n", "testing %%010.5s");
//	printf("%010.5s\n", "Teting"); //producess warning
	printf("%-10d%s\n",10 , "%%-10d");
	printf("%010d%s\n",10 , "%%010d");
	printf("%*.*s\n", 10, 5, "Hello there");
	printf("%c\n", 65);
	printf("%10c\n", 65);
	printf("%.5s\n", "testing %%.5s");
	printf("%s\n\n", "		rrina tests over");

	printf("%s\n\n", "		All the possible args");
	printf("%s\n", "%s");
	printf("String, Testing");
	printf("Works with out flgs or specifayers\n");
	printf("It even works with numbers in a string 1234\n");
	printf("\n\t\v\f\r");
//	printf(1234); does not work

	printf("			Testing out varibles\n");
	printf("			int, int long, short int, float\n");
	int		x;
	int		y;
	int		z;
	int		p;
	int long	xl;
	int short	sy;
	float		f;
	float		nf;
	int		age;

	age = 25;
	x = 100;
	y = 200;
	z = -300;
	p = +499;
	xl = 214739841231313;
	sy = 213;
	f = 2.5;
	nf = -2.5;
	printf("I am %d years old\n", age);
	printf("%d\nint\t", x);
	printf("%d\nint\t", y);
	printf("%d\nnegative int\t", z);
	printf("%d\nint+\t", p);
	printf("%ld\nint long\t", xl);
	printf("%d\nint short\t", sy);
	printf("%f\nfloat\t", f);
	printf("%f\nnegative float\t", nf);
	printf("			printging ints as chars\n");
	printf("%c\nint char	", x);
	printf("%c\nint char\t", y);
	printf("%c\nnegative int to char\t", z);
	printf("%c\n\t", p);
	printf("			chars, arrays, strings, wchar_t,\n");
	char	*nul;
	char	*str;

	str = "Regular string";

	nul = NULL;

	printf("%s\n\a", nul);
	printf("%s\n",str);
	printf("			Misalenius edge cases\n");
	printf("\"");
	printf("%%\n");
	printf("			Where can the regular chars be?\n");
	printf("it can apper before the %% after it and as long as it dosnt mess with the flags or sepcifayers\n");
	printf("			Playing with flags \"-.*0\"\n");
	printf("			Playing with return value\n");
	int	ret;

	ret = printf("testing");
	printf("%d\n", ret);
	ret = printf("%s%s\n","Whats ","GOOD?");
	printf("%d\n", ret);
	ret = printf("this is ret with 0 in front of a number! %-15d\n", 1234567891);
	printf("%20d\n", ret);
	ret = printf("Testing\n");
	printf("%d\n", ret);
	ret = printf("Testing\n");
	printf("%d\n", ret);
	printf("			Looks like it the amount of chars we printed was the nr\n");
	printf("%-.*d\n", 20, 1234);

	//19.06
	printf("What does the \'-\' specifayer do?");
	printf("The \'-\' specifayer just changes the places we talk about like are we addinf 0 before the nre or after the same with sapces");
	printf("%d\n", -1234);
	printf("%.020d\n", 12345);
	printf("%d-\n", 1234);
	printf("%-d\n", 1234);
	printf("%-d\n", -1234);
	printf("%-d\n", +1234);

	printf("%10d\n", 1234);
	return (0);
}
