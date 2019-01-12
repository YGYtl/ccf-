#include<stdio.h>
int main()
{
	int que[1001]={'\0'};//最后排序 
	int a[1020]={'\0'};//记得是序号 
	int n, p, q, m;
	int i, j, k;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++)
	{
		que[i] = i;
		a[i] = i;
	}
	int o;
	for(i=0; i<m; i++)
	{
		scanf("%d %d", &p, &q);
		o = a[p];
		if(q > 0)
		{
			for(j=o; j<o+q; j++)
			{
				que[j] = que[j+1];
				a[que[j]]--;
			}
		}
		else{
			for(j=o; j>o+q; j--)
			{
				que[j] = que[j-1];
				a[que[j]]++;
			}
		}
		que[o+q] = p;
		a[p] = o + q;
	}
	for(i=1; i<n; i++)
	{
		printf("%d ", que[i]);
	}
	printf("%d\n", que[n]);
	return 0;
}
