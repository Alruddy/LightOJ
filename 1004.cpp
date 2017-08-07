#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
using namespace std;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int N = 220 + 5;
int a[N][N],dp[N][N];
int t,n,kase = 0;
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        memset(a, 0, sizeof(a));
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
                scanf("%d", &a[i][j]);
        }
        for(int i = n + 1; i <= 2*n-1; i++)
        {
            for(int j = 1; j <= 2*n - i; j++)
                scanf("%d", &a[i][j]);
        }
        for(int i = 2*n - 1; i >= n; i--)
        {
            for(int j = 0; j <= n; j++)
                dp[i][j] = max(dp[i+1][j], dp[i+1][j-1]) + a[i][j];
        }
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = 0; j <= n; j++)
                dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + a[i][j];
        }
        printf("Case %d: %d\n", ++kase, dp[1][1]);
    }
}
