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
const double PI = acos(-1.0);
const double eps = 1e-9;

const int N = 20 + 5;
int t,n,m,sx,sy,kase=0;;
char mp[N][N];
bool vis[N][N];
int dirx[] = {0,1,-1,0};
int diry[] = {1,0,0,-1};
int bfs()
{
    memset(vis, 0, sizeof(vis));
    queue<int> Q; while(!Q.empty()) Q.pop();
    Q.push(sx*100+sy);
    vis[sx][sy]=1;
    int ans = 0;
    while(!Q.empty())
    {
        int tmp = Q.front();
        int x = tmp/100, y = tmp % 100;
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dirx[i], ny = y + diry[i];
            if(nx < 0 || ny < 0 || nx >= m || ny >= n || vis[nx][ny] || mp[nx][ny] == '#') continue;
            vis[nx][ny] = 1;
            Q.push(nx*100+ny);
        }
        Q.pop();
        ans++;
    }
    return ans;
}
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        getchar();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                scanf("%c", &mp[i][j]);
                if(mp[i][j] == '@')
                    sx = i, sy = j;
            }
            getchar();
        }
        printf("Case %d: %d\n", ++kase, bfs());
    }
    return 0;
}





