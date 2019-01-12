#include <cstdio>
#include <cstring>
long long a[1010][10];
const long long Mod = 1000000007;
//2
//20
//23
//230
//201
//2013
int main()
{
    int n;
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= n; i++)
    {
        a[i][0] = 1;
        a[i][1] = (a[i-1][0]+a[i-1][1]*2)%Mod;
        a[i][2] = (a[i-1][0]+a[i-1][2])%Mod;
        a[i][3] = (a[i-1][1]+a[i-1][2]+a[i-1][3]*2)%Mod;
        a[i][4] = (a[i-1][1]+a[i-1][4]*2)%Mod;
        a[i][5] = (a[i-1][3] + a[i-1][4] + a[i-1][5]*2)%Mod;
    }
    printf("%I64d\n", a[n][5]);
    return 0;
}
