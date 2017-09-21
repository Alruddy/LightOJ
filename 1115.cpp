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
const int N = 50 + 5;
const int mod = 1e9 + 7;
int t, kase = 0;

int n,m;
char mp[N][N];
int vis[N][N];

int dirx[] = {0,1,0,-1};
int diry[] = {1,0,-1,0};
struct Point
{
    int x,y;
    Point(int a = 0, int b = 0): x(a), y(b){}
};
void bfs(char ch)
{
    queue<Point> Q;
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; i++)
    {
        if(mp[0][i] != ch)
        {
            vis[0][i] = 1;
            Q.push(Point(0,i));
        }
        if(mp[m-1][i] != ch)
        {
            vis[m-1][i] = 1;
            Q.push(Point(m-1,i));
        }
    }
    for(int i = 1; i < m-1; i++)
    {
        if(mp[i][0] != ch)
        {
            vis[i][0] = 1;
            Q.push(Point(i,0));
        }
        if(mp[i][n-1] != ch)
        {
            vis[i][n-1] = 1;
            Q.push(Point(i, n-1));
        }
    }

    while(!Q.empty())
    {
        Point p = Q.front(); Q.pop();
        int x = p.x, y = p.y;
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dirx[i];
            int ny = y + diry[i];
            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if(mp[nx][ny] == ch) continue;
            if(vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            Q.push(Point(nx,ny));
        }
    }
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(!vis[i][j]) mp[i][j] = ch;
}


int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &m, &n);
        for(int i = 0; i < m; i++)
        {
            scanf("%s", mp[i]);
        }
        for(int i = 0; i <= 25; i++)
        {
            char ch = 'A' + i;
            bfs(ch);
        }
        printf("Case %d:\n", ++kase);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                printf("%c", mp[i][j]);
            }
            putchar('\n');
        }
    }
    return 0;
}











