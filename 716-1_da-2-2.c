#include <stdio.h>
#include <math.h>

int main()
{
	int a;
	int b;
	int c;
	int i;
	int p=0;
	scanf("%d", &a);
	for (i=0; i<a; i++)
		{
		scanf("%d", &b);
		if(b>1)
		{
		c++;
		}
			if (b%2==0)
			{
				p+=pow(b,2);
		  	}
		}
	printf("%d", p);
	return 0;
}
	
 
