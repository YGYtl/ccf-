#include<stdio.h>
int main()
{
	int n, i;
	int j, k;
	int x1, y1, x2, y2;
	int sum = 0, count = 0;
	int a[200][200]={'\0'};
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for(j=x1; j<x2; j++)
		{
			for(k=y1; k<y2; k++)
			{
				if(a[j][k]=='\0')
				{
					a[j][k] = 1;
				}
				else{
					count++;
				}
			}
		}
		sum += (x2-x1)*(y2-y1);
	}
	printf("%d", sum-count);
	return 0;
}
