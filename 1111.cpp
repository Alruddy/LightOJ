#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <math.h>
#include <bitset>
#include <ctype.h>
#define CLR(a, b) memset(a, b, sizeof(a))
using namespace std;
typedef pair<int,int> P;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-9;
const int N = 1e3 + 5;
int t, kase = 0;
int k, n, m;
int p[N];
vector<int> G[N];
int vis[N];
int comeNum[N];
void init()
{
    CLR(vis, 0); CLR(comeNum, 0);
    for(int i = 0; i < n; i++) G[i].clear();
}
void dfs(int u)
{
    vis[u] = 1;
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if(!vis[v]) dfs(v);
    }
}
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        init();
        scanf("%d%d%d", &k, &n, &m);
        for(int i = 1; i <= k; i++)
            scanf("%d", &p[i]);
        for(int i = 0; i < m; i++)
        {
            int u,v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
        }
        for(int i = 1; i <= k; i++)
        {
            CLR(vis, 0);
            dfs(p[i]);
            for(int j = 0; j <= n; j++)
                if(vis[j]) comeNum[j]++;
        }
        int cnt = 0;
        for(int i = 0; i <= n; i++)
            if(comeNum[i] == k) cnt++;
        printf("Case %d: %d\n", ++kase, cnt);
    }
    return 0;
}









