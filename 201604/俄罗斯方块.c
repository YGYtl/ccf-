#include<stdio.h>
int main()
{
	int f[20][20]={'\0'};
	int m[4][4]={'\0'};
	int i, j, k, n, o;
	for(j=0; j<15; j++)
		for(k=0; k<10; k++)
			scanf("%d", &f[j][k]);

	for(j=0; j<4; j++)
		for(k=0; k<4; k++)
			scanf("%d", &m[j][k]);

	o = 3;
	for(j=3; j>=0; j--)
		if(m[j][0]==0&&m[j][1]==0&&m[j][2]==0&&m[j][3]==0)
			o--;
		else break;
		
	scanf("%d", &n);//3
	int x, y, c;
	x = n-1;
	y = x+4;
	int m1 = 14;
	int m2;
	for(j=4; j<15; j++)
	{
		m2 = o;
		for(i=j; i>=j-o; i--)
		{
			if((f[i][x]==1&&m[m2][0]==1)||(f[i][x+1]==1&&m[m2][1]==1)||(f[i][x+2]==1&&m[m2][2]==1)||(f[i][x+3]==1&&m[m2][3]==1))
			{
				m1 = j-1;
				break;
			}
			m2--;
		}
		if(m1!=14) break;
	}
	m2 = o;
	for(j=m1; j>=m1-o; j--)//往上修改数组的值 
	{
		c = 0;
		for(k=x; k<y; k++)
		{
			if(m[m2][c++]==0)
				continue;
			f[j][k] = 1;
		}
		m2--;
	}
	for(j=0; j<15; j++)//打印数组 
	{
		for(k=0; k<10; k++)
		{
			if(k!=0) printf(" ");
			printf("%d", f[j][k]);
		}
		printf("\n");
	}
	return 0;
}
