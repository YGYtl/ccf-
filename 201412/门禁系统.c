#include<stdio.h>
int main()
{
	int n, i, j, c;
	int a[10000]={'\0'};
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		c = 0;
		scanf("%d", &a[i]);
		if(i) printf(" ");
		for(j=0; j<=i; j++)
		{
			if(a[j]==a[i]) c++;
		}
		printf("%d", c);
	}
	return 0;
}
