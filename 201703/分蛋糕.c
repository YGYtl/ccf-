#include<stdio.h>
int main()
{
	int n, k, i, m=0, c=0, o;
	scanf("%d %d", &n, &k);
	for(i=0; i<n; i++)
	{
		scanf("%d", &o);
		m += o;
		if(m>=k||i==n-1)
		{
			c++;
			m = 0;
		}
	}
	printf("%d", c);
	return 0;
}
