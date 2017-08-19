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
int n,m,p;
struct Edge
{
    int u,v,w;
    Edge(){}
    Edge(int a, int b, int c): u(a), v(b), w(c) {}
};
vector<Edge> edges;
vector<int> G[N];
void init(int n)
{
    edges.clear();
    for(int i = 0; i <= n; i++) G[i].clear();
}
void addedge(int u, int v, int w)
{
    edges.push_back(Edge(u, v, w));
    int m = edges.size();
    G[u].push_back(m-1);
}
int cnt[N], inque[N], d[N];
bool Bellman_ford()
{
    queue<int> Q;
    for(int i = 0; i < n; i++)
    {
        inque[i]= 1;
        d[i] = 0;
        cnt[i] = 0;
        Q.push(i);
    }
    while(!Q.empty())
    {
        int u = Q.front(); Q.pop(); inque[u] = 0;
        for(int i = 0; i < G[u].size(); i++)
        {
            Edge &e = edges[G[u][i]];
            int v = e.v;
            if(d[v] > d[u] + e.w)
            {
                d[v] = d[u] + e.w;
                if(!inque[v])
                {
                    inque[v] = 1;
                    cnt[v]++;
                    Q.push(v);
                    if(cnt[v] > n)
                        return false;
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
        scanf("%d%d%d", &n, &m, &p);
        init(n);
        for(int i = 0; i < m; i++)
        {
            int u,v,in,out,w;
            scanf("%d%d%d%d", &u, &v, &in, &out);
            w = p*out - in;
            addedge(u, v, w);
        }
        printf("Case %d: ", ++kase);
        if(!Bellman_ford())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}








