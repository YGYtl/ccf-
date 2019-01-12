#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int a[1001], b[1001];
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for(int i=0; i<n; i++){
		if(i==0){
			b[i] = (a[i]+a[i+1])/2;
		}
		else if(i==n-1){
			b[i] = (a[i]+a[i-1])/2;
		}
		else{
			b[i] = (a[i-1]+a[i]+a[i+1])/3;
		}
	}
	for(int i=0; i<n; i++){
		if(i) printf(" ");
		printf("%d", b[i]);
	}
	return 0;
}


























