#include <stdio.h>
#include <math.h>

int main()
{
	float x, y;
	scanf("%f %f", &x, &y);
	printf("%f", powf(x, y));
	getchar();
	return 0;
}
