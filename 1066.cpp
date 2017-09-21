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
const int N = 15;
char mp[N][N];
int d[N][N],n;
int dirx[] = {0,1,0,-1};
int diry[] = {1,0,-1,0};
struct Node
{
    int id;
    int x,y;
    Node(){}
    Node(int a, int b, int c){
        id = a, x = b, y = c;
    }
};
bool cmp(Node a, Node b)
{
    return a.id<b.id;
}
int t,kase=0;
int bfs(int i, int j, int ei, int ej)
{
    queue<P> Q;
    memset(d, -1, sizeof(d));
    Q.push(P(i,j));
    d[i][j] = 0;
    while(!Q.empty())
    {
        P tmp = Q.front(); Q.pop();
        int x = tmp.first, y = tmp.second;
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dirx[i], ny = y + diry[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(mp[nx][ny] != '.') continue;
            if(d[nx][ny] >= 0) continue;
            if(nx == ei && ny == ej) return d[x][y] + 1;
            d[nx][ny] = d[x][y] + 1;
            Q.push(make_pair(nx,ny));
        }
    }
    return -1;
}
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%s", mp[i]);
        }
        vector<Node> p;
        p.clear();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                if(isupper(mp[i][j]))
                    p.push_back(Node(mp[i][j]-'A',i,j));
        }
        sort(p.begin(),p.end(),cmp);
        int ans = 0, flag = 0;
        for(int i = 1; i < p.size(); i++)
        {
            mp[p[i].x][p[i].y] = '.';
            mp[p[i-1].x][p[i-1].y] = '.';
            int tm = bfs(p[i-1].x, p[i-1].y, p[i].x, p[i].y);
            if(tm == -1)
                flag = 1;
            ans += tm;
        }
        printf("Case %d: ", ++kase);
        if(flag)
            printf("Impossible\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}


