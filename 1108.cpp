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
using namespace std;
typedef pair<int,int> P;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-9;
const int N = 1000 + 5;
int t, kase = 0;
struct Edge
{
    int u,v,w;
    Edge(){}
    Edge(int a, int b, int c): u(a),v(b),w(c) {}
};
vector<Edge> edges;
vector<int> G[N];
int n,m;
void init(int n)
{
    edges.clear();
    for(int i = 0; i <= n; i++) G[i].clear();
}
void addedge(int u, int v, int w)
{
    edges.push_back(Edge(u,v,w));
    int m = edges.size();
    G[u].push_back(m-1);
}
int d[N], inque[N], cnt[N], circle[N];

void dfs(int u)
{
    circle[u] = 1;
    for(int i = 0; i < G[u].size(); i++)
    {
        Edge &e = edges[G[u][i]];
        int v = e.v;
        if(circle[v]) continue;
        dfs(v);
    }
}

bool Bellman_ford(int s)
{
    queue<int> Q;
    for(int i = 0; i < n; i++)
    {
        d[i] = cnt[i] = 0;
        inque[i] = 1;
        circle[i] = 0;
        Q.push(i);
    }
    while(!Q.empty())
    {
        int u = Q.front(); Q.pop(); inque[u] = 0;
        for(int i = 0; i < G[u].size(); i++)
        {
            Edge &e = edges[G[u][i]];
            int v = e.v;
            if(circle[v]) continue;
            if(d[v] > d[u] + e.w)
            {
                d[v] = d[u] + e.w;
                if(!inque[v])
                {
                    cnt[v]++;
                    Q.push(v);
                    inque[v] = 1;
                    if(cnt[v] > n) dfs(v);
                }
            }
        }
    }
    return true;
}
int u,v,w;
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        init(n);
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            addedge(v, u, w);
        }
        Bellman_ford(0);
        printf("Case %d:", ++kase);
        int f = 0;
        for(int i = 0; i < n; i++)
            if(circle[i])
            {
                printf(" %d", i);
                f = 1;
            }
        if(f == 0)
            printf(" impossible");
        printf("\n");
    }
    return 0;
}
