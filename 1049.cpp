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
#include <ctype.h>
using namespace std;
typedef pair<int,int> P;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-9;
const int N = 100 + 5;
int t,n,kase = 0;
struct Edge
{
    int u, v, f, w;
    Edge(){}
    Edge(int a, int b, int c, int d)
    {
        u = a; v = b;
        f = c; w = d;
    }
};
vector<Edge> edges;
vector<int> G[N];
void init(int n)
{
    edges.clear();
    for(int i = 0; i <= n; i++)
        G[i].clear();
}
void addedge(int u, int v, int w)
{
    edges.push_back(Edge(u,v,1,w));
    edges.push_back(Edge(v,u,-1,w));
    int m = edges.size();
    G[u].push_back(m-2);
    G[v].push_back(m-1);
}
int ans = 0;
int vis[N];
void dfs(int u, int fa)
{
    for(int i = 0; i < G[u].size(); i++)
    {
        Edge &e = edges[G[u][i]];
        int v = e.v;
        if(fa == v) continue;
        if(vis[v]) continue;
        vis[v] = 1;
        if(e.f == 1)
        {
            ans += e.w;
        }
        dfs(v,u);
    }
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        init(n);
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            int u,v,w;
            scanf("%d%d%d", &u, &v, &w);
            sum += w;
            addedge(u,v,w);
        }
        ans = 0;
        memset(vis, 0, sizeof(vis));
        dfs(1,-1);
        ans = min(ans, sum-ans);
        printf("Case %d: %d\n", ++kase, ans);
    }
    return 0;
}


















