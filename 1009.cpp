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
const int N = 4e4 + 50;
const int K = 2e4;
int fa[N],vis[N],sum[N];
void init()
{
    for(int i = 0; i < N; i++)
        fa[i] = i;
    for(int i = 0; i <= K; i++)
        sum[i] = 1;
    memset(vis, 0, sizeof(vis));
}
int find(int x)
{
    if(x == fa[x])
        return x;
    fa[x] = find(fa[x]);
    return fa[x];
}
bool unite(int a, int b)
{
    int x = find(a);
    int y = find(b);
    if(x == y)
        return false;
    fa[y] = x;
    sum[x] += sum[y];
    return true;
}
int t,n,u,v;
int kase = 0;
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        init();
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &u, &v);
            vis[u] = vis[v] = vis[u+K] = vis[v+K] = 1;
            unite(u, v+K);
            unite(v, u+K);
        }
        int ans = 0;
        for(int i = 1; i <= K; i++)
        {
            if(!vis[i]||fa[i] != i) continue;
            u = i, v = find(i+K);
            ans += max(sum[u], sum[v]);
            vis[u] = vis[v] = 0;
        }
        printf("Case %d: %d\n", ++kase, ans);
    }
    return 0;
}












