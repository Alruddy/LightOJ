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
map<int,int> mp;
struct Edge
{
    int u,v;
    int cut;
    Edge(){}
    Edge(int _u, int _v):u(_u), v(_v) {cut = 0;}
};
vector<Edge> edges;
vector<int> G[N];
int bridges;
int dfn[N],low[N],dfs_clock;

void init()
{
    for(int i = 0; i < N; i++)
        G[i].clear();
    edges.clear();
    mp.clear();
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    bridges = 0;
    dfs_clock = 0;
}

bool Hash(int u, int v)
{
    int tmp = u*10000 + v;
    if(mp.count(tmp)) return true;
    mp[tmp] = 1;
    mp[v*10000+u] = 1;
    return false;
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
            dfs(v,u);
            low[u] = min(low[u], low[v]);
        }
        else
        {
            low[u] = min(low[u], dfn[v]);
        }
        if(low[v] > dfn[u])
        {
            bridges++;
            e.cut = 1;
            edges[G[u][i]^1].cut = 1;
        }
    }
}

int t,kase = 0;
int u,v,m,n;
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        init();
        for(int i = 0; i < n; i++)
        {
            scanf("%d (%d)", &u, &m);
            for(int j = 0; j < m; j++)
            {
                scanf("%d", &v);
                if(!Hash(u,v))
                    addedge(u,v);
            }
        }
        for(int i = 0; i < n; i++)
            if(!dfn[i])
                dfs(i,-1);
        printf("Case %d:\n", ++kase);
        printf("%d critical links\n", bridges);
        vector<P> ans;
        for(int i = 0; i < edges.size(); i++)
        {
            if(edges[i].cut && edges[i].u < edges[i].v)
            {
                ans.push_back(make_pair(edges[i].u,edges[i].v));
            }
        }
        sort(ans.begin(),ans.end());
        for(int i = 0; i < ans.size(); i++)
        {
            printf("%d - %d\n", ans[i].first, ans[i].second);
        }
    }
    return 0;
}



















