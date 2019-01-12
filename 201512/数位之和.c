#include<stdio.h>
int main()
{
	int n, sum=0, k;
	scanf("%d", &n);
	while(n)
	{
		k = n%10;
		sum += k;
		n = n/10;
	}
	printf("%d", sum);
	return 0;
}
