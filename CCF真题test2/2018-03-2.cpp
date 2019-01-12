#include<iostream>
using namespace std;
struct data{
	int number;//¼¸ºÅÇò 
	int f;
	int s;
	data(){
		f = 0;
	}
}a[101];
int main()
{
	int n, L, t;
	scanf("%d %d %d", &n, &L, &t);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &a[i].s);
		a[i].number = i+1;
	}
	for(int i=0; i<t; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(a[j].f==0) a[j].s++;//ÏòÓÒ
			else a[j].s--; 
		}
		for(int j=0; j<n; j++)
		{
			for(int k=0; k<n; k++)
			{
				if(a[j].s==a[k].s&&j!=k)
				{
					a[j].f = (a[j].f == 0 ? 1 : 0);
				}
			}
			if(a[j].s==L) a[j].f = 1;//Ïò×ó
			if(a[j].s==0) a[j].f = 0; 
		}
	}
	for(int i=0; i<n; i++)
	{
		if(i) printf(" ");
		printf("%d", a[i].s);
	}
	return 0;
}
