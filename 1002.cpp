#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;

const int N = 500 + 5;
struct Edge
{
    int u,v,w;
    Edge(){}
    Edge(int a, int b, int c):u(a), v(b), w(c) {}
};
int t,n,m,s,kase = 0;
vector<Edge> edges;
vector<int> G[N];
int d[N];
void init()
{
    edges.clear();
    for(int i = 0; i < N ; i++) G[i].clear();
}
void addedge(int u, int v, int w)
{
    edges.push_back(Edge(u, v, w));
    edges.push_back(Edge(v, u, w));
    int m = edges.size();
    G[u].push_back(m-2);
    G[v].push_back(m-1);
}
void Djistra(int s)
{
    priority_queue<P, vector<P>, greater<P> > pq; while(!pq.empty()) pq.pop();
    for(int i = 0; i < n; i++) d[i] = INF;
    d[s] = 0;
    pq.push(P(0,s));
    while(!pq.empty())
    {
        P p = pq.top(); pq.pop();
        int dis = p.first, u = p.second;
        if(dis > d[u]) continue;
        for(int i = 0; i < G[u].size(); i++)
        {
            Edge &e = edges[G[u][i]];
            int v = e.v;
            if(d[v] > max(d[u],e.w))
            {
                d[v] = max(d[u], e.w);
                pq.push(P(d[v],v));
            }
        }
    }
}
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        printf("Case %d:\n", ++kase);
        init();
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; i++)
        {
            int u,v,w;
            scanf("%d%d%d", &u,&v,&w);
            addedge(u,v,w);
        }
        scanf("%d", &s);
        Djistra(s);
        for(int i = 0; i < n; i++)
        {
            if(d[i] == INF)
                printf("Impossible\n");
            else
                printf("%d\n", d[i]);
        }
    }
    return 0;
}
