#include<iostream>
#include<cstdio>
using namespace std;
struct data{
	int weight;
	int father;
	bool flag;
	data(){
		weight = 32767;
		flag = false;
	}
};
int main()
{
	int n, m, k1, k2, num;
	data a[100][100];
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i==j) a[i][j].weight = 0;
		}
	}
	for(int i=0; i<m; i++){
		scanf("%d %d %d", &k1, &k2, &num);
		a[k1][k2].weight = a[k2][k1].weight = num;
		if(k1==1||k2==1) a[k1][k2].father = a[k2][k1].father = 1;
	}
	a[1][1].flag = true;
	for(int i=2; i<=n; i++){
		int min=32767, index;
		for(int j=2; j<=n; j++){
			if(a[1][j].flag==false&&a[1][j].weight<min){
				min = a[1][j].weight;
				index = j;
			}
		}
		for(int j=2; j<=n; j++){
			if(a[index][j].weight+min<a[1][j].weight){
				a[1][j].weight = a[index][j].weight+min;
				a[1][j].father = index;
			}
		}
		a[1][index].flag = true;
	}
	
	a[2][2].flag = true;
	for(int i=2; i<=n; i++){//执行的次数 
		int min = 32767, index;
		for(int j=1; j<=n; j++){
			if(j==2) continue;
			if(a[2][j].flag==false&&a[2][j].weight<min){
				min = a[2][j].weight;
				index = j;
			}
		}
		for(int j=1; j<=n; j++){
			if(j==2) continue;
			if(a[index][j].weight+min<a[2][j].weight){
				a[2][j].weight = a[index][j].weight+min;
				a[2][j].father = index;
			}
		}
		a[2][index].flag = true;
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			printf(" %5d", a[i][j].weight);
		}
		printf("\n");
	}
	return 0;
}
