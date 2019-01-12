#include<stdio.h>
int main()
{
	int a[24][10] = {'\0'};
	int i, j, k=1;
	for(i=0; i<20; i++)
	{
		for(j=0; j<5; j++)
		{
			a[i][j] = k++;
		}
	}
	int n, m, o, kk;
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &m);
		o = 0;
		kk = m;
		for(j=0; j<20; j++)
		{
			for(k=0; k<5; k++)
			{
				if((a[j][k]!=-1&&5-k>=m)||o==1)
				{
					if(kk!=m) printf(" ");
					printf("%d", a[j][k]);
					a[j][k] = -1;
					o = 1;
					kk--;
				}
				if(kk==0) break;
			}
			if(kk==0) break;
		}
		if(kk==m)
		{
			for(j=0; j<20; j++)
			{
				for(k=0; k<5; k++)
				{
					if(a[j][k]!=-1)
					{
						if(kk!=m) printf(" ");
						printf("%d", a[j][k]);
						kk--;
					}
					if(kk==0) break;
				}
				if(kk==0) break;
			}
		}
		printf("\n");
	}
	return 0;
}
