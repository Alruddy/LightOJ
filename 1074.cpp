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
const int N = 200 + 5;
int t, kase = 0;
int a[N];
struct Edge
{
    int u,v,w;
    Edge(){}
    Edge(int a, int b, int c): u(a),v(b),w(c) {}
};
vector<Edge> edges;
vector<int> G[N];
int n,m,q,p;
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
    memset(d, 0x3f, sizeof(d));
    memset(cnt, 0, sizeof(cnt));
    memset(inque, 0, sizeof(inque));
    memset(circle, 0, sizeof(circle));
    d[s] = 0; inque[s] = 1;
    queue<int> Q;
    Q.push(s);
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

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        init(n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        scanf("%d", &m);
        for(int i = 0; i < m; i++)
        {
            int u, v, w;
            scanf("%d%d", &u, &v);
            w = (a[v]- a[u]);
            w = w*w*w;
            addedge(u,v,w);
        }
        Bellman_ford(1);
        scanf("%d", &q);
        printf("Case %d:\n", ++kase);
        for(int i = 0; i < q; i++)
        {
            scanf("%d", &p);
            if(circle[p] || d[p] == INF || d[p] < 3)
                printf("?\n");
            else
                printf("%d\n", d[p]);
        }
    }
    return 0;
}
