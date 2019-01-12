#include<stdio.h>
struct data{
	int x1, y1;
	int x2, y2;
}a[20];
int main()
{
	int n, m, b[20];
	scanf("%d %d", &n, &m);
	int i, j, k;
	int x1, y1, x2, y2;
	for(i=0; i<n; i++)//n=3-----2-1-0
	{
		b[i] = n-i-1;//层次改变 
		scanf("%d %d %d %d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
	}
	int x, y, f, v;
	for(i=0; i<m; i++)
	{
		f = 1;
		scanf("%d %d", &x, &y);
		for(j=0; j<n; j++)//从最上层开始判断 
		{
			if(x>=a[b[j]].x1&&x<=a[b[j]].x2&&y>=a[b[j]].y1&&y<=a[b[j]].y2)
			{
				printf("%d\n", b[j]+1);
				v = b[j];
				for(k=j; k>0; k--) b[k] = b[k-1];
				b[0] = v;
				f = 0;
				break;
			} 
		}
		if(f==1) printf("IGNORED\n");
	}
	return 0;
}
