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

const int N = 100 + 5;
int t,kase = 0;
int x,y[N];
int n,w,k;
int dp[N][N],a[N];
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d", &n, &w, &k);
        for(int i = 0; i < n; i++)
            scanf("%d%d", &x,&y[i]);
        sort(y, y+n);
        memset(a, 0, sizeof(a));
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++)
        {
            int h = i, l = i;
            while(y[h] - y[l] <= w && l >= 0)
                l--;
            a[h] = h-l;
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j <= k; j++)
            {
                if(i >= a[i])
                    dp[i][j] = max(dp[i-1][j], dp[i-a[i]][j-1] + a[i]);
                else
                    dp[i][j] = a[i];
            }
        }
        printf("Case %d: %d\n", ++kase, dp[n-1][k]);
    }
    return 0;



}



