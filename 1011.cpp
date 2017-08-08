#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <math.h>
using namespace std;
typedef pair<int,int> P;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-9;
const int N = 17;

int dp[1<<N|1][N];
int cnt[1<<N|1];
int t,n,a[N][N],kase = 0;
int main()
{
    cnt[0] = 0;
    for(int i = 1; i < 1<<N; i++)
        cnt[i] = cnt[i - i&(-i)] + 1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            for(int j = 0; j < n; j++)
                scanf("%d", &a[i][j]);
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                for(int s = 0; s < (1<<n); s++)
                {
                    if((s & (1<<j)) == 0)
                        dp[s|(1<<j)][i] = max(dp[s|(1<<j)][i], a[i][j] + dp[s][i-1]);
                }
            }
        }
        printf("Case %d: %d\n", ++kase, dp[(1<<n)-1][n]);
    }
    return 0;
}
