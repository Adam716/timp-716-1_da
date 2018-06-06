#include <stdio.h>

int main()
{
	int a;
	int b;
	int count=0;
	int i;
	scanf("%d",&a);
	for(i=0; i<a; i++)
	{
       		 scanf("%d", &b);
		 if(b>=0)
		 {
		 count++;
		 }
	}
	printf("%d", count);
	return 0;
}
