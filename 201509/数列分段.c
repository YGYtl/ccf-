#include<stdio.h>
int main()
{
	int n, i, k, o, c=1;
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &k);
		if(i==0)
		{
			o = k;
			continue;
		}
		if(o!=k)
		{
			c++;
			o = k;
		}
	}
	printf("%d", c);
	return 0;
}
