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
const int N = 30 + 5;
int t,n,m,len,kase = 0;
int dp1[N][N];
LL dp2[N][N][2*N];
char s1[N],s2[N];
int lcs()
{
    memset(dp1, 0, sizeof(dp1));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s1[i] == s2[j])
                dp1[i][j] = dp1[i-1][j-1] + 1;
            else
                dp1[i][j] = max(dp1[i-1][j], dp1[i][j-1]);
        }
    }
    return dp1[n][m];
}

LL dfs(int i, int j, int l)
{
    LL &ans = dp2[i][j][l];
    if(ans != -1) return ans;
    else if(l == 0) return i == 0 && j == 0;
    else if(i == 0) return ans = dfs(i, j-1, l-1);
    else if(j == 0) return ans = dfs(i-1, j, l-1);
    else if(s1[i] == s2[j]) return ans = dfs(i-1, j-1, l-1);
    else return ans = dfs(i-1, j, l-1) + dfs(i, j-1, l-1);
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s%s", s1+1, s2+1);
        n = strlen(s1+1);
        m = strlen(s2+1);
        len = n + m - lcs();
        memset(dp2, -1, sizeof(dp2));
        printf("Case %d: %d %lld\n", ++kase, len, dfs(n,m,len));
    }
    return 0;
}
