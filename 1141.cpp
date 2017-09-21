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
using namespace std;
typedef pair<int,int> P;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-9;
const int N = 1000 + 5;
const int mod = 1e9 + 7;
int t, kase = 0;
int S,T;
int ans;
int prime[N], cnt_prime, vis[N];
int getprime()
{
    cnt_prime = 0;
    memset(vis, 0, sizeof(vis));
    for(int i = 2; i < N; i++)
    {
        if(!vis[i]) prime[cnt_prime++] = i;
        vis[i] = 1;
        for(int j = 0; j < cnt_prime && i*prime[j] < N; j++)
        {
            vis[i*prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}

int bfs(int s, int t)
{
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(s);
    vis[s] = 1;
    while(!Q.empty())
    {
        int u = Q.front(); Q.pop();
        if(u == t) return vis[u]-1;
        for(int i = 0; i < cnt_prime && u+prime[i] <= t && prime[i] < u; i++)
        {
            int tmp = u + prime[i];
            if(u % prime[i] == 0 && vis[tmp] == 0)
            {
                vis[tmp] = vis[u]+1;
                Q.push(tmp);
            }
        }
    }
    return -1;
}

int main()
{
    scanf("%d", &t);
    getprime();
    while(t--)
    {
        scanf("%d%d", &S,&T);
        ans = bfs(S,T);
        printf("Case %d: %d\n", ++kase,  ans);
    }
    return 0;
}

