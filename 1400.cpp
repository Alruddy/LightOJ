#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
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
const int N = 225 + 5;
const int mod = 1e9 + 7;
int t, kase = 0;
int n;
vector<int> G[N];
int match[N];
void init()
{
    for(int i = 0; i < N; i++) G[i].clear();
}

void solve()
{
    memset(match, 0, sizeof(match));
    queue<int> Q;
    for(int i = 1; i <= n; i++)
        Q.push(i);

    while(!Q.empty())
    {
        int u = Q.front(); Q.pop();
        if(match[u]) continue;
        int m = G[u].size();
        for(int i = 0; i < m; i++)
        {
            int v = G[u][i];
            if(!match[v])
            {
                match[v] = u;
                match[u] = v;
                break;
            }
            else
            {
                int pm = G[v].size();
                for(int j = 0; j < m; j++)
                {
                    int pu = G[v][j];
                    if(pu == match[v])
                        break;
                    if(pu == u)
                    {
                        match[u] = v;
                        int tu = match[v];
                        match[tu] = 0;
                        Q.push(tu);
                        match[v] = u;
                        break;
                    }
                }
                if(match[u]) break;
            }
        }
    }
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        init();
        scanf("%d", &n);
        for(int i = 1; i <= 2*n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                int tmp;
                scanf("%d", &tmp);
                G[i].push_back(tmp);
            }
        }
        solve();
        printf("Case %d: ", ++kase);
        for(int i = 1; i <= n; i++)
        {
            if(i != 1) printf(" ");
            printf("(%d %d)", i, match[i]);
        }
        printf("\n");
    }
    return 0;
}
