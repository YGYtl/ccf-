#include<stdio.h>
int main()
{
	int n, i, a[1004]={'\0'}, o;
	scanf("%d", &n);
	for(i=1; i<=n; i++)
	{
		scanf("%d", &a[i]);
	}
	int j, k;
	for(j=1; j<n; j++)
	{
		for(k=1; k<=n-j; k++)
		{
			if(a[k]>a[k+1])
			{
				o = a[k];
				a[k] = a[k+1];
				a[k+1] = o;
			}
		}
	}
	int min=0, max=0;
	o = n;
	if(n%2!=0) o = n+1;
	for(i=1; i<=n; i++)
	{
		if(a[i]>a[o/2])
		{
			max++; 
		}
		if(a[i]<a[o/2])
		{
			min++;
		}
	}
	if(min==max) printf("%d", a[o/2]);
	else printf("%d", -1);
	return 0;
}
