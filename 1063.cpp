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
const int N = 1e4 + 5;
struct Edge
{
    int u,v;
    Edge(){}
    Edge(int a, int b):u(a),v(b) {}
};
vector<Edge> edges;
vector<int> G[N];
int cut[N];
int dfn[N], low[N], dfs_clock;
int n,m;
int ans = 0;
void init()
{
    edges.clear();
    for(int i = 0; i < N; i++) G[i].clear();
    memset(cut, 0, sizeof(cut));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
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
    dfn[u] = low[u] = ++dfs_clock;
    int son = 0;
    for(int i = 0; i < G[u].size(); i++)
    {
        Edge &e = edges[G[u][i]];
        int v = e.v;
        if(v == fa) continue;
        if(!dfn[v])
        {
            son++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(u != fa && low[v] >= dfn[u])
            {
                cut[u] = 1;
            }
        }
        else
            low[u] = min(low[u], dfn[v]);
    }
    if(u == fa && son > 1)
    {
        cut[u] = 1;
    }

}
int t,kase=0;
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        init();
        scanf("%d%d", &n,&m);
        for(int i = 0; i < m; i++)
        {
            int u,v;
            scanf("%d%d", &u,&v);
            addedge(u,v);
        }
        ans = 0;
        for(int i = 1; i <= n; i++)
            if(!dfn[i]) dfs(i, i);
        for(int i = 1; i <= n; i++)
            if(cut[i]) ans++;
        printf("Case %d: %d\n", ++kase, ans);
    }
    return 0;
}










