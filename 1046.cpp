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
char mp[15][15];
int dirx[] = {1,1,2,2,-1,-1,-2,-2};
int diry[] = {2,-2,1,-1,2,-2,1,-1};
vector<P> p;
int t,n,m,kase = 0;
int d[15][15];

int bfs(int u, int v)
{
    P s(u,v);
    queue<P> Q;
    memset(d, -1, sizeof(d));
    Q.push(s);
    d[u][v] = 0;
    while(!Q.empty())
    {
        P tmp = Q.front(); Q.pop();
        int x = tmp.first, y = tmp.second;
        for(int i = 0; i < 8; i++)
        {
            int nx = x + dirx[i];
            int ny = y + diry[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(d[nx][ny] >= 0) continue;
            d[nx][ny] = d[x][y] + 1;
            Q.push(make_pair(nx,ny));
        }
    }
    int ans = 0;
    for(int i = 0; i < p.size(); i++)
    {
        int x = p[i].first, y = p[i].second;
        if(d[x][y] < 0) return -1;
        if(d[x][y] > 0)
            ans += (d[x][y] - 1) / (mp[x][y] - '0') + 1;
    }
    return ans;
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n,&m);
        for(int i = 0; i < n; i++)
            scanf("%s", mp[i]);
        p.clear();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(isdigit(mp[i][j]))
                {
                    p.push_back(make_pair(i,j));
                }
            }
        }

        int f = 0, ans = INF;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int success = bfs(i,j);
                if(success == -1)
                {
                    continue;
                }
                else
                {
                    ans = min(ans, success);
                }
            }
        }
        printf("Case %d: ", ++kase);
        if(ans == INF)
            printf("%d\n", -1);
        else
            printf("%d\n", ans);
    }
    return 0;
}
















