#include<stdio.h>
int main()
{
	int n, i, k, max=0, m=0, o;
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &o);
		if(i!=0)
		{
			m = o - k;
			if(m<0) m = -m;
			if(m>max) max = m;
		}
		k = o;
	}
	printf("%d", max);
	return 0;
}
