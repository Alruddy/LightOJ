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
const int N = 26;
bool vis[N][N][N];
int dirx[] ={1,-1,0,0,0,0};
int diry[] ={0,0,1,-1,0,0};
int dirz[] ={0,0,0,0,1,-1};
int T;
char s1[5],s2[5],a[50],b[50],c[50];
int n,kase=0;
int edx,edy,edz;
struct Node
{
    int x;
    int y;
    int z;
    int t;
    Node(){x=y=z=t=0;}
    Node(int a, int b, int c, int d):x(a),y(b),z(c),t(d){}
};
Node st,ed;
int bfs()
{
    int x=st.x, y=st.y, z=st.z;
    if(vis[x][y][z]) return -1;
    queue<Node> Q;
    Q.push(st);
    while(!Q.empty())
    {
        Node tmp = Q.front(); Q.pop();
        int x=tmp.x, y=tmp.y, z=tmp.z, t = tmp.t;
        if(x==edx && y == edy && z == edz)
        {
            return t;
        }
        for(int i = 0; i < 6; i++)
        {
            int nx = (x + dirx[i] + 26)%26;
            int ny = (y + diry[i] + 26)%26;
            int nz = (z + dirz[i] + 26)%26;
            int nt = t + 1;
            if(vis[nx][ny][nz]) continue;
            Q.push(Node(nx,ny,nz,nt));
            vis[nx][ny][nz] = 1;
        }
    }
    return -1;
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s%s", s1, s2);
        st.x= s1[0]-'a', st.y= s1[1]-'a', st.z= s1[2]-'a', st.t = 0;
        edx = s2[0]-'a', edy = s2[1]-'a', edz = s2[2]-'a';
        scanf("%d", &n);
        memset(vis, false, sizeof(vis));
        while(n--)
        {
            scanf("%s%s%s", a,b,c);
            int l1 = strlen(a), l2=strlen(b), l3=strlen(c);
            for(int i = 0; i < l1; i++)
                for(int j = 0; j < l2; j++)
                    for(int k = 0; k < l3; k++)
                        vis[a[i]-'a'][b[j]-'a'][c[k]-'a'] = 1;
        }
        printf("Case %d: %d\n", ++kase, bfs());
    }
    return 0;
}












