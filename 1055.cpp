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
const int N = 100 + 5;
int t,n,kase = 0;
int dirx[] = {1,0,0,-1};
int diry[] = {0,-1,1,0};
char mp[15][15];
int stx[3],sty[3];
int edx[3],edy[3],edp;
int d[12][12][12][12][12][12];
struct Node
{
    int ax,ay;
    int bx,by;
    int cx,cy;
    Node(){}
    Node(int a, int b, int c, int d, int e, int f)
    {
        ax = a; ay = b;
        bx = c; by = d;
        cx = e; cy = f;
    }
};

int bfs(int ax, int ay, int bx, int by, int cx, int cy)
{
    queue<Node> Q;
    memset(d, -1, sizeof(d));
    Node s(ax,ay,bx,by,cx,cy);
    Q.push(s);
    d[ax][ay][bx][by][cx][cy] = 0;
    while(!Q.empty())
    {
        Node tmp = Q.front(); Q.pop();
        int ax = tmp.ax, ay = tmp.ay;
        int bx = tmp.bx, by = tmp.by;
        int cx = tmp.cx, cy = tmp.cy;
        for(int i = 0; i < 4; i++)
        {
            int nax = ax + dirx[i], nay = ay + diry[i];
            int fa = 0,fb = 0,fc = 0;
            if(nax < 0 || nay < 0 || nax >= n || nay >= n || mp[nax][nay] == '#')
            {
                nax = ax, nay = ay; fa = 1;
            }
            int nbx = bx + dirx[i], nby = by + diry[i];
            if(nbx < 0 || nby < 0 || nbx >= n || nby >= n || mp[nbx][nby] == '#' )
            {
                nbx = bx, nby = by; fb = 1;
            }
            int ncx = cx + dirx[i], ncy = cy + diry[i];
            if(ncx < 0 || ncy < 0 || ncx >= n || ncy >= n || mp[ncx][ncy] == '#' )
            {
                 ncx = cx, ncy = cy; fc = 1;
            }
            if(fa && nbx == nax && nby == nay) nbx = bx, nby = by, fb = 1;
            if(fa && ncx == nax && ncy == nay) ncx = cx, ncy = cy, fc = 1;
            if(fb && nax == nbx && nay == nby) nax = ax, nay = ay, fa = 1;
            if(fb && ncx == nbx && ncy == nby) ncx = cx, ncy = cy, fc = 1;
            if(fc && nbx == ncx && nby == ncy) nbx = bx, nby = by, fb = 1;
            if(fc && nax == ncx && nay == ncy) nax = ax, nay = ay, fa = 1;
            if(fa && nbx == nax && nby == nay) nbx = bx, nby = by, fb = 1;
            if(fa && ncx == nax && ncy == nay) ncx = cx, ncy = cy, fc = 1;
            if(fb && nax == nbx && nay == nby) nax = ax, nay = ay, fa = 1;
            if(fb && ncx == nbx && ncy == nby) ncx = cx, ncy = cy, fc = 1;
            if(fc && nbx == ncx && nby == ncy) nbx = bx, nby = by, fb = 1;
            if(fc && nax == ncx && nay == ncy) nax = ax, nay = ay, fa = 1;
            if(d[nax][nay][nbx][nby][ncx][ncy] >= 0) continue;

            int ans = d[ax][ay][bx][by][cx][cy] + 1;
            d[nax][nay][nbx][nby][ncx][ncy] = ans;
            if(mp[nax][nay] == 'X' && mp[nbx][nby] == 'X' && mp[ncx][ncy] == 'X')
                return ans;
            Q.push(Node(nax,nay,nbx,nby,ncx,ncy));
        }
    }
    return -1;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%s", mp[i]);
        edp=0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mp[i][j] == 'A')
                {
                    mp[i][j] = '.';
                    stx[0] = i; sty[0] = j;
                }
                else if(mp[i][j] == 'B')
                {
                    mp[i][j] = '.';
                    stx[1] = i; sty[1] = j;
                }
                else if(mp[i][j] == 'C')
                {
                    mp[i][j] = '.';
                    stx[2] = i; sty[2] = j;
                }
            }
        }
        int ans = bfs(stx[0],sty[0],stx[1],sty[1],stx[2],sty[2]);
        printf("Case %d: ", ++kase);
        if(ans == -1)
            printf("trapped\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}


















