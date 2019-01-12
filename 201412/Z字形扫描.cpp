#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int a[510][510];
int main()
{
    int n, x, y;
    cin >> n;// 输入数据
    for(int i=0; i<n; i++)
    	for(int j=0; j<n; j++)
    		cin >> a[i][j];
    x = 0;
    y = 0;
    for(int i=0; i<n; i++) // 输出左上三角
    {
	    if(i&1)//i是奇数时 
	    {
	        for(int j=0; j<i; j++)
	        	cout << a[x++][y--] << " ";
	        cout << a[x++][y] << " ";
	    }
	    else
	    {
	        for(int j=0; j<i; j++)
	        	cout << a[x--][y++] << " ";
	        cout<< a[x][y++] << " ";
	    }
	}
    if(n&1) //奇数 输出右下三角  
   		y--, x++;
    else
    	y++, x--;
    for(int i=n-2; i>0; i--)
    {
	    if(i & 1)//奇数 
	    {
	        for(int j=0; j<i; j++)
	        	cout << a[x++][y--] << " ";
	        cout << a[x][y++] << " ";
	    }
	    else
	    {
	        for(int j=0; j<i; j++)
				cout << a[x--][y++] << " ";
	        cout << a[x++][y] << " ";
	    }
	}
    if(n!=1)
    	cout << a[n-1][n-1] << endl;
    return 0;
}
