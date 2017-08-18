#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <math.h>
#include <bitset>
using namespace std;
typedef pair<int,int> P;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-9;
const int N = 1e4 + 5;
struct Edge
{
    int u,v;
    Edge() {}
    Edge(int a, int b):u(a), v(b) {}
};
vector<Edge> edges;
vector<int> G[N];
int dfn[N],low[N],cut[N],vis[N],dfs_clock,num;
void init(int n)
{
    edges.clear();
    for(int i = 0; i <= n; i++) G[i].clear();
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(cut, 0, sizeof(cut));
    memset(vis, 0, sizeof(vis));
    dfs_clock = 0;
}

void addedge(int u, int v)
{
    edges.push_back(Edge(u, v));
    edges.push_back(Edge(v, u));
    int m = edges.size();
    G[u].push_back(m-2);
    G[v].push_back(m-1);
}

void dfs(int u, int fa)
{
    int son = 0;
    dfn[u] = low[u] = ++dfs_clock;
    for(int i = 0; i < G[u].size(); i++)
    {
        Edge &e = edges[G[u][i]];
        int v = e.v;
        if(v == fa) continue;
        son++;
        if(!dfn[v])
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(u != fa && low[v] >= dfn[u]) cut[u] = 1;
            if(u == fa && son > 1) cut[u] = 1;
        }
        else
            low[u] = min(low[u], dfn[v]);
    }
}
set<int> s;
void dfs2(int u)
{
    vis[u] = 1;
    num++;
    for(int i = 0; i < G[u].size(); i++)
    {
        Edge &e = edges[G[u][i]];
        int v = e.v;
        if(cut[v])
        {
            s.insert(v);
            continue;
        }
        if(cut[v] || vis[v]) continue;
        dfs2(v);
    }
}

int t,m,n,u,v,kase = 0;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        init(n);
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d", &u, &v);
            addedge(u,v);
        }
        dfs(0,0);
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(cut[i]) cnt++;
        }
        int ans = 0;
        ULL ans2 = 1;
        if(!cnt)
        {
            ans = 2; ans2 = (n-1)*n/2;
        }
        else
        {
            memset(vis, 0, sizeof(vis));
            for(int i = 0; i < n; i++)
            {
                if(cut[i] || vis[i]) continue;
                s.clear();
                num = 0;
                dfs2(i);
                if(s.size() <= 1)
                {
                    ans++;
                    ans2 *= num;
                }
            }
        }
        printf("Case %d: %d %llu\n", ++kase, ans, ans2);
    }
    return 0;
}
