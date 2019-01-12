#include<iostream>
#include<cstdio>
using namespace std;
struct data{
	int w1, w2, k;
	data(){
		k = 1;
	}
};
int main()
{
	int n, l, t;
	scanf("%d %d %d", &n, &l, &t);
	data a[n];
	for(int i=0; i<n; i++){
		scanf("%d", &a[i].w1);
	}
	while(t--){
		for(int i=0; i<n; i++){
			a[i].w1 += a[i].k;
		}
		for(int i=0; i<n; i++){
			bool flag = false;
			a[i].w2 = a[i].w1;
			if(a[i].w1==0||a[i].w1==l){
				flag = true;
			}
			for(int j=0; j<n&&!flag; j++){
				if(i==j) continue;
				if(a[i].w1==a[j].w1){
					flag = true;
				}
			}
			if(flag){
				if(a[i].k==1) a[i].k=-1;
				else a[i].k = 1;
			}
		}
		for(int i=0; i<n; i++) a[i].w1 = a[i].w2;
	}
	for(int i=0; i<n; i++){
		if(i) printf(" ");
		printf("%d", a[i].w1);
	}
	return 0;
}
