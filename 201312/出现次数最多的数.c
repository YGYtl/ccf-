#include<stdio.h>
int main()
{
	int n, i, a[2000]={'\0'};
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", &a[i]);
	int j, k, o;
	for(j=1; j<n; j++)
	{
		for(k=0; k<n-j; k++)
		{
			if(a[k]>a[k+1])
			{
				o = a[k];
				a[k] = a[k+1];
				a[k+1] = o;
			}
		}
	}
	int c = 1;
	int max = 1, mark = a[0];
	for(i=0; i<n; i++)
	{
		if(i==0)
		{
			o = a[i];
			continue;
		}
		if(a[i]==o)
		{
			c++;
		}
		else{
			if(c>max)
			{
				max = c;
				mark = a[i-1];
			}
			else if(c==max&&mark>a[i-1])
			{
				mark = a[i];
			}
			o = a[i];
			c = 1;
		}
	}
	printf("%d", mark);
	return 0;
}
