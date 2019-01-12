#include<iostream>
#include<cstdio>
using namespace std;
int a[1000002]={'\0'}, b[1000002]={'\0'};
int main()
{
	int n, c1=0, c2=0, c = 0;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d %d", &c1, &c2);
		for(int j=c1+1; j<=c2; j++){
			a[j] = 1;
		}
	}
	for(int i=0; i<n; i++){
		scanf("%d %d", &c1, &c2);
		for(int j=c1+1; j<=c2; j++){
			b[j] = 1;
		}
	}
	for(int i=0; i<=1000000; i++){
		if(a[i]==b[i]&&a[i]==1){
			c++;
		}
	}
	printf("%d\n", c);
	return 0;
}
