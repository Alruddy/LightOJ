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
int n,m;
char mp[N][N];
int vis[N][N];
int dirx[] = {0,1,0,-1};
int diry[] = {1,0,-1,0};
struct Node
{
    int x,y;
    int t;
    Node(int a, int b, int c):x(a),y(b),t(c) {}
};
void updatemap()
{
    char mmp[N][N];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            mmp[i][j] = mp[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(mp[i][j] == 'F')
            {
                int x =i, y = j;
                for(int k = 0; k < 4; k++)
                {
                    int nx = x + dirx[k], ny = y + diry[k];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m || mmp[nx][ny] != '.') continue;
                    mmp[nx][ny] = 'F';
                }
            }
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            mp[i][j] = mmp[i][j];
}
int bfs(int x, int y)
{
    queue<Node> Q;
    memset(vis, 0, sizeof(vis));
    vis[x][y] = 1;
    int curtime = 0;
    Q.push(Node(x,y,0));
    while(!Q.empty())
    {
        Node node = Q.front(); Q.pop();
        int x = node.x, y = node.y, t = node.t;
        if(t == curtime)
        {
            updatemap();
            curtime++;
        }
        if(x == n-1 || y == m-1 || x == 0 || y == 0) return t+1;
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dirx[i], ny = y + diry[i], nt = t + 1;
            if(nx < 0 || ny < 0 || nx >= n || ny >= m || mp[nx][ny] != '.') continue;
            if(vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            Q.push(Node(nx,ny,nt));
        }
    }
    return -1;
}

int sx,sy;
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        getchar();
        for(int i = 0; i < n; i++)
            gets(mp[i]);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                if(mp[i][j] == 'J')
                    sx = i, sy = j;
        }
        int ans = bfs(sx,sy);
        printf("Case %d: ", ++kase);
        if(ans == -1)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}




