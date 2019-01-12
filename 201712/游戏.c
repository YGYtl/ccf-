#include<stdio.h>
int main()
{
	int n, k, j, i, count=1, num=0;
	int a[1004]={'\0'};
	scanf("%d %d", &n, &k);
	while(num!=n-1)
	{
		for(i=1; i<=n; i++)
		{
			if(a[i]==-1) continue;
			if(count%k==0||count%10==k){
				a[i] = -1;
				num++;
				count++;
			}
			else
			{
				a[i] = count++;
			}
			if(num==n-1)
			{
				break;
			}
		}
	}
	for(i=1; i<=n; i++)
	{
		if(a[i]!=-1)
		{
			printf("%d", i);
			break;
		}
	}
	return 0;
}

