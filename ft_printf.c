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

void    *ft_memset(void *s, int c, size_t n)
{
        size_t  i;

        i = 0;
        while (n > i)
        {
                ((char *)s)[i] = (unsigned char)c;
                i++;
        }
        return (s);
}

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
        char    *d; 
        char    *s; 

        d = (char *)dest;
        s = (char *)src;
        while (n > 0)
        {
                if (d == NULL && s == NULL)
                        return (NULL);
                *d = *s; 
                d++;
                s++;
                n--;
        }
        if (d == NULL && s == NULL)
                return (NULL);
        return ((void *)dest);
}

char    *ft_memrcpy(char *dest, const char *src, size_t x)
{
        while (x > 0)
        {
                *dest = *src;
                dest--;
                src--;
                x--;
        }
        return (dest);
}

void    *ft_memmove(void *dest, const void *src, size_t n)
{
        int                     x;
        char            *desa;
        const char      *gala;

        x = n - 1;
        desa = dest;
        gala = src;
        if (dest < src)
                ft_memcpy(dest, src, n); 
        else if (dest > src)
        {
                while (x > 0)
                {
                        desa++;
                        gala++;
                        x--;
                }
                ft_memrcpy(desa, gala, n); 
        }
        else if (dest == NULL || src == NULL)
                return (NULL);
        return ((void *)dest);
}

void    *ft_calloc(size_t nmemb, size_t size)
{
        void    *ptr;

        ptr = malloc(nmemb * size);
        if (ptr == 0)
                return (NULL);
        ptr = ft_memset(ptr, 0, nmemb * size);
        return (ptr);
}

char	*ft_chop(const char	*s)
{
	int		x;
	char	*conversion_specifier;

	x = 0;
	while (s[x] != '\0')
	{
		if (s[x] == 'c' || s[x] == 's' || s[x] == 'p'|| s[x] == 'd' || s[x] == 'i' || s[x] == 'u' || s[x] == 'x' || s[x] == 'X')
		{
			conversion_specifier = ft_calloc(x + 1, sizeof(char));
			conversion_specifier = ft_memmove(conversion_specifier, s, x + 1);
			return (conversion_specifier);
		}
		x++;
	}
	return (NULL);
}

char	*ft_find(const char	*s)
{
	char	*conversion_specifier;

	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == '%')
		{
			conversion_specifier = ft_chop(s);
			printf("%s\n", conversion_specifier);
		}
		s++;
	}
	return (NULL);
}

int	ft_printf(const char *str, ...)
{
		ft_find(str);
		printf("%s\n", "Done");
	return (0);
}

int     main()
{
	const char	pptr[] = "Hello World%010.5d\nHello%s.5\n%x       %0.10X        %lx    ";
        ft_printf(pptr);
        return(0);
}
