#include<iostream>
using namespace std;
int main()
{
	double t, sum, a;
	scanf("%lf", &t);
	for(double i=100; i<t*2; i+=100)
	{
		sum = 0;
		a = i - 3500;
		if(a>0)
		{
			if(a<1500) sum += a*0.03;
			else sum += 45;
		}
		if(a>1500)
		{
			if(a<4500) sum += (a-1500)*0.1;
			else sum += 300;
		}
		if(a>4500)
		{
			if(a<9000) sum += (a-4500)*0.2;
			else sum += 4500*0.2;
		}
		if(a>9000)
		{
			if(a<35000) sum += (a-9000)*0.25;
			else sum += (35000-9000)*0.25;
		}
		if(a>35000)
		{
			if(a<55000) sum += (a-35000)*0.3;
			else sum += (55000-35000)*0.3;
		}
		if(a>55000)
		{
			if(a<80000) sum += (a-55000)*0.35;
			else sum += (80000-55000)*0.35;
		}
		if(a>80000)
		{
			sum += (a-80000)*0.45;
		}
		if(a - sum + 3500 == t)
		{
			printf("%.0f", i);
			break;
		}
	}
	return 0;
}
