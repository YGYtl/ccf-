#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int sum = 0;
	int n, c = 0;
	while(scanf("%d", &n)&&n!=0){
		if(n==1){
			sum++;
			c = 0;
		}
		else{
			c++;
			sum += 2*c;
		}
	}
	printf("%d", sum);
	return 0;
}
