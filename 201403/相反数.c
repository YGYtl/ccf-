#include<stdio.h>
int main()
{
	int n, i, j, a[1000]={'\0'}, c=0;
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
		for(j=0; j<i; j++)
		{
			if(a[i]== -a[j])
			{
				a[i] = 0;
				a[j] = 0;
				c++;
				break;
			}
		}
	}
	printf("%d", c);
	return 0;
}
