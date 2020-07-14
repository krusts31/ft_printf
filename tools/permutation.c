#include <stdio.h>
#include <string.h>

void swap(char *x, char *y) 
{ 
    char temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
} 

int factorial(int n)
{
	if(n<0)
		return -1;
	if(n==0)
		return 1;
	return (n*factorial(n-1));
}

void permute(char *a, int l, int r) 
{ 
   int i;

   if (l == r) 
     printf("%s\n", a);
   else
   { 
       for (i = l; i <= r; i++) 
       { 
          swap((a+l), (a+i)); 
          permute(a, l+1, r); 
          swap((a+l), (a+i)); //backtrack 
       } 
   } 
} 
  
/* Driver program to test above functions */
int main() 
{
	char str[] = "-0.*# +";
	int n = strlen(str);
	permute(str, 0, n-1);
	printf("This is the number of possible flags: %d\n",factorial(n));
	return (0);
} 
