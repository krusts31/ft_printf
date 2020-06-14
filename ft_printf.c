#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t  ft_strlen(const char *s) 
{
        size_t  retu;

        retu = 0;
        while (*s != '\0')
        {
                retu++;
                s++;
        }
        return (retu);
}

char    *ft_strdup(const char *s) 
{
        char    *ptr;
        size_t  x;  
        size_t  y;  

        y = 0;
        x = ft_strlen(s);
        ptr = malloc(x + 1); 
        if (ptr == NULL)
                return (NULL);
        while (s[y])
        {
                ptr[y] = s[y];
                y++;
        }
        ptr[y] = '\0';
        return (ptr);
}

char	*ft_find(const char	*s)
{
	if (s == NULL)
		return (NULL);
	printf("error");
	while (*s != '\0')
	{
		printf("error");
		if (*s == '%')
		{
			while (*s != 'c' || *s != 's' || *s != 'p'
			|| *s != 'd' || *s != 'i' || *s != 'u'
			|| *s != 'x' || *s != 'X' || *s != '%')
				s++;
			//we could increment a different varible hear and then copy that length and position 
			return (ft_strdup(s));
		}
		s++;
	}
	return (NULL);
}

int	ft_printf(const char *str, ...)
{
	char	*string;
		printf("error");
		string = ft_find(str);
		printf("error");
		printf("%s\n", string);
	return (0);
}

int     main()
{
	printf("Hello");
	const char	*pptr;
	pptr = "Hello World%d\nHello";
	printf("main");
        ft_printf(pptr);
        return(0);
}
