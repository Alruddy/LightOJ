#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <math.h>
#include <bitset>
#include <ctype.h>
using namespace std;
typedef pair<int,int> P;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-9;
const int N = 125 + 5;
const int mod = 1e9 + 7;
int t, kase = 0;
int n,m;
int S,T;
int vis[N];
vector<int> G[N];
void init()
{
    for(int i = 0; i < N; i++) G[i].clear();
}

int bfs(int s, int t1, int t2)
{
    memset(vis, -1, sizeof(vis));
    queue<int> Q;
    Q.push(s);
    vis[s] = 0;
    while(!Q.empty())
    {
        int u = Q.front(); Q.pop();
        if(vis[t1] != -1 && vis[t2] != -1) return vis[t1]+vis[t2];
        for(int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            if(vis[v] != -1) continue;
            vis[v] = vis[u] + 1;
            Q.push(v);
        }
    }
    return -1;
}


int main()
{
    scanf("%d", &t);
    while(t--)
    {
        init();
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; i++)
        {
            int u,v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        scanf("%d%d", &S, &T);
        int ans = -1;
        for(int i = 0; i < n; i++)
            ans = max(ans, bfs(i, S, T));

        printf("Case %d: %d\n", ++kase, ans);
    }


    return 0;
}





