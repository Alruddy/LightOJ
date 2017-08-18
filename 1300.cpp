#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <math.h>
#include <bitset>
using namespace std;
typedef pair<int,int> P;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-9;
const int N = 1e4 + 5;
struct Edge
{
    int u,v,cut;
    Edge(){}
    Edge(int a, int b):u(a),v(b){
        cut = 0;
    }
};
vector<int> G[N];
vector<Edge> edges;
int dfn[N],low[N],dfs_clock;
int color[N];
void init(int n)
{
    for(int i = 0; i <= n; i++) G[i].clear();
    edges.clear();
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(color, 0, sizeof(color));
    dfs_clock = 0;
}

void addedge(int u, int v)
{
    edges.push_back(Edge(u,v));
    edges.push_back(Edge(v,u));
    int m = edges.size();
    G[u].push_back(m-2);
    G[v].push_back(m-1);
}

void dfs(int u, int fa)
{
    dfn[u] = low[u] = ++dfs_clock;
    for(int i = 0; i < G[u].size(); i++)
    {
        Edge &e = edges[G[u][i]];
        int v = e.v;
        if(v == fa) continue;
        if(!dfn[v])
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > dfn[u])
            {
                e.cut = 1;
                edges[G[u][i]^1].cut = 1;
            }
        }
        else
            low[u] = min(low[u], dfn[v]);
    }
}
int cnt, flag;
void dfs2(int u, int fa, int c)
{
    color[u] = c;
    cnt ++;
    for(int i = 0; i < G[u].size(); i++)
    {
        Edge &e = edges[G[u][i]];
        if(e.cut) continue;
        int v = e.v;
        if(v == fa) continue;
        if(color[v] == 0)
        {
            dfs2(v, u, 3-c);
        }
        else if(color[v] == color[u])
            flag = 1;
    }
}

int t,n,m,u,v,ans,kase = 0;
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n,&m);
        init(n);
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d", &u,&v);
            addedge(u,v);
        }

        for(int i = 0; i < n; i++)
            if(!dfn[i]) dfs(i,i);
        memset(color, 0, sizeof(color));
        ans = 0;
        for(int i = 0; i < n; i++)
        {
            flag = 0;
            cnt = 0;
            if(!color[i]) dfs2(i, i, 1);
            if(flag) ans += cnt;
        }

        printf("Case %d: %d\n", ++kase, ans);
    }
    return 0;
}
