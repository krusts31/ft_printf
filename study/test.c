#include <stdarg.h>
#include <stdio.h>

           void foo(char *fmt, ...)
           {
                   va_list ap, ap2;
                   int d;
                   char c, *s;

                   va_start(ap, fmt);
                   va_copy(ap2, ap);
                   while (*fmt)
                           switch(*fmt++) {
                           case 's':                       /* string */
                                   s = va_arg(ap, char *);
                                   printf("string %s\n", s);
                                   break;
                           case 'd':                       /* int */
                                   d = va_arg(ap, int);
                                   printf("int %d\n", d);
                                   break;
                           case 'c':                       /* char */
                                   /* Note: char is promoted to int. */
                                   c = va_arg(ap, int);
                                   printf("char %c\n", c);
                                   break;
                           }
                   va_end(ap);
                   va_end(ap2);
           }
int	main()
{
	char	s[] = "10000dd23d:323d14dd55ssc";

	foo(s, 1, 2, 3, 4, 5, 6, "tests", "all goo in the hood", 'b');
	return (0);
}
