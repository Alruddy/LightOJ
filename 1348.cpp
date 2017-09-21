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
#include <ctype.h>
#define CLR(n,b) memset(n, b, sizeof(n))
using namespace std;

typedef pair<int,int> P;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-9;
const int N = 3e4 + 5;
const int mod = 1e9 + 7;
struct Edge
{
    int u,v;
    Edge(){}
    Edge(int _u, int _v):u(_u),v(_v) {}
    Edge(int _u, int _v){
        u = _u; v = _v;
    }
};
int fa[N],son[N], sz[N],dep[N], top[N],p[N],fp[N];
int pos,n;
int t, kase = 0;
vector<Edge> edges;
vector<int> G[N];
void init(int n)
{
    pos = 0;
    CLR(fa,0); CLR(son,-1); CLR(dep,0);
    CLR(sz,0); CLR(top,0); CLR(p,0);  CLR(fp,0);
    for(int i = 0; i <= n; i++) G[i].clear();
    edges.clear();
}
void addedge(int u, int v)
{
    edges.push_back(Edge(u,v));
    edges.push_back(Edge(v,u));
    int m = edges.size();
    G[u].push_back(m-2);
    G[v].push_back(m-1);
}

// 树链剖分

void dfs(int u, int pre, int d)
{
    fa[u] = pre; son[u] = -1;
    sz[u] = 1; dep[u] = d;
    for(int i = 0; i < G[u].size(); i++)
    {
        Edge &e = edges[G[u][i]];
        int v = e.v;
        if(v == pre) continue;
        dfs(v, u, d+1);
        sz[u] += sz[v];
        if(son[u] == -1 || sz[son[u]] < sz[v])
            son[u] = v;
    }
}

void getpos(int u, int sp)
{
    top[u] = sp;
    p[u] = ++pos;
    fp[p[u]] = u;
    if(son[u] == -1) return;
    getpos(son[u], sp);
    for(int i = 0; i < G[u].size(); i++)
    {
        Edge &e = edges[G[u][i]];
        int v = e.v;
        if(v == son[u] || v == fa[u]) continue;
        getpos(v,v);
    }
}

// 树状数组
int c[N];
inline int lowbit(int x)
{
    return x&(-x);
}

void add(int x, int val)
{
    while(x <= n)
    {
        c[x] += val;
        x += lowbit(x);
    }
}

int sum(int x)
{
    int ans = 0;
    while(x)
    {
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
}

// change & query

void change(int x, int v)
{
    int ans = sum(x)-sum(x-1);
    add(x, -ans);
    add(x, v);
}

int query(int x, int y)
{
    int u = x, v = y;
    int f1 = top[u], f2 = top[v];
    int ans = 0;
    while(f1 != f2)
    {
        if(dep[f1] < dep[f2])
        {
            swap(f1,f2);
            swap(u,v);
        }
        ans += sum(p[u]) - sum(p[f1]-1);
        u = fa[f1];
        f1 = top[u];
    }

    if(dep[u] > dep[v]) swap(u,v);
    ans += sum(p[v]) - sum(p[u]-1);
    return ans;
}
int a[N],q;
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        printf("Case %d:\n", ++kase);
        scanf("%d", &n);
        init(n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < n-1; i++)
        {
            int u,v;
            scanf("%d%d", &u, &v);
            addedge(u,v);
        }
        dfs(1,1,0);
        getpos(1,1);
        memset(c, 0, sizeof(c));
        for(int i = 0; i < n; i++)
            add(p[i], a[i]);

        scanf("%d", &q);
        while(q--)
        {
            int type, x,y;
            scanf("%d%d%d", &type, &x,&y);
            if(type == 0)
            {
                printf("%d\n", query(x,y));
            }
            else
                change(p[x],y);
        }
    }
    return 0;
}
