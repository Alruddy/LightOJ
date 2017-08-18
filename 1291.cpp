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
    int u,v;
    Edge(){}
    Edge(int a, int b):u(a),v(b){}
};
vector<int> G[N];
vector<Edge> edges;
int dfn[N],low[N],belong[N],scc_cnt,dfs_clock;
stack<int> s;
int deg[N];
void init(int n)
{
    for(int i = 0; i <= n; i++) G[i].clear();
    edges.clear();
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(belong, 0, sizeof(belong));
    memset(deg, 0, sizeof(deg));
    dfs_clock = scc_cnt = 0;
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
    s.push(u);
    for(int i = 0; i < G[u].size(); i++)
    {
        Edge &e = edges[G[u][i]];
        int v = e.v;
        if(v == fa) continue;
        if(!dfn[v])
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        }
        else
            low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u])
    {
        int c;
        scc_cnt++;
        do
        {
            c = s.top(); s.pop();
            belong[c] = scc_cnt;
        }while(c != u);
    }
}
int t,n,m,u,v,kase = 0;
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
        for(int i = 0; i < m*2; i += 2)
        {
             u = belong[edges[i].u];
             v = belong[edges[i].v];
             if(u == v) continue;
             deg[u]++;deg[v]++;
        }
        int ans = 0;
        for(int i = 1; i <= scc_cnt; i++)
        {
            if(deg[i] == 1) ans ++;
        }
        printf("Case %d: %d\n", ++kase, (ans+1)/2);
    }
    return 0;
}










