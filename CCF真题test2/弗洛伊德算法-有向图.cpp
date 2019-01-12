#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct data{
	int d;
	bool flag;
	data(){
		flag = false;
		d = 32767;
	}
};
int main()
{
	int n, m, l1, l2, g;
	data a[100][100];
	int b[100][100];
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			b[i][j] = j;
			if(i==j) a[i][j].d = 0;
		}
	}
	for(int i=0; i<m; i++){
		scanf("%d %d %d", &l1, &l2, &g);
		a[l1][l2].d = a[l2][l1].d = g;
	}
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(k!=i&&k!=j){
					int s = a[i][k].d + a[k][j].d;
					if(s < a[i][j].d){
						a[i][j].d = s;
						b[i][k] = b[i][j];
					}
				}
			}
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			printf(" %5d", a[i][j].d);
		}
		printf("\n");
	}
	printf("\n");
	
	return 0;
}
