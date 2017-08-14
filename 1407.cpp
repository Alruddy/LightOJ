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
const int maxn = 2005;
struct Node
{
    int type;
    int x,y,z;
}node[10];
int n,m,k;
struct TwoSAT
{
    int n;
    vector<int> G[maxn*2];
    bool mark[maxn*2];
    int S[maxn*2],c;

    void init(int n)
    {
        this->n = n;
        for(int i = 0; i <= 2*n; i++)
            G[i].clear();
        memset(mark, false, sizeof(mark));
    }

    bool judge()
    {
        for(int i = 0; i < k; i++)
        {
            if(node[i].type == 2)
            {
                int x = 2*node[i].x;
                int y = 2*node[i].y;
                int z = 2*node[i].z;
                if(mark[x] && mark[y] && mark[z]) return false;
            }
            else
            {
                int x = 2*node[i].x + 1;
                int y = 2*node[i].y + 1;
                int z = 2*node[i].z + 1;
                if(mark[x] && mark[y] && mark[z]) return false;
            }
        }
        return true;
    }
    bool dfs(int x)
    {
        if(mark[x^1]) return false;
        if(mark[x]) return true;
        S[c++] = x;
        mark[x] = 1;
        if(!judge()) return false;
        for(int i = 0; i < G[x].size(); i++)
        {
            if(!dfs(G[x][i])) return false;
        }
        return true;
    }
    // x = xval || y = yval
    void add_clause(int x, int xval, int y, int yval)
    {
        x = 2*x + xval;
        y = 2*y + yval;
        G[x^1].push_back(y);
        G[y^1].push_back(x);
    }
    // x = xval --> y = yval
    void add_limit(int x, int xval, int y, int yval)
    {
        x = 2*x + xval;
        y = 2*y + yval;
        G[x].push_back(y);
    }

    bool solve()
    {
        for(int i = 0; i < 2*n; i += 2)
        {
            if(!mark[i] && !mark[i+1])
            {
                c = 0;
                if(!dfs(i))
                {
                    while(c) mark[S[--c]] = false;
                    if(!dfs(i+1)) return false;
                }
            }
        }
        return true;
    }
};
TwoSAT sat;
int t, kase = 0;
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d", &n,&m,&k);
        sat.init(n);
        // 0-present  1-absent
        for(int i = 0; i < m; i++)
        {
            int type,x,y;
            scanf("%d%d%d", &type, &x, &y);
            if(type == 1)
            {
                sat.add_clause(x-1, 0, y-1, 0);
            }
            else if(type == 2)
            {
                sat.add_limit(x-1, 1, y-1, 1);
                sat.add_limit(y-1, 0, x-1, 0);
            }
            else if(type == 3)
            {
                sat.add_clause(x-1, 1, y-1, 1);
            }
            else if(type == 4)
            {
                sat.add_limit(x-1, 0, y-1, 1);
                sat.add_limit(x-1, 1, y-1, 0);
                sat.add_limit(y-1, 0, x-1, 1);
                sat.add_limit(y-1, 1, x-1, 0);
            }
        }

        for(int i = 0; i < k; i++)
        {
            int type,x,y,z;
            scanf("%d%d%d%d", &type, &x, &y, &z);
            node[i].type = type; node[i].x = x-1;
            node[i].y = y-1; node[i].z = z-1;
        }
        printf("Case %d: ", ++kase);
        if(sat.solve())
        {
            printf("Possible");
            int cnt = 0;
            vector<int> ans;
            for(int i = 0; i < 2*n; i += 2)
            {
                if(sat.mark[i])
                {
                    cnt++;
                    ans.push_back(i/2+1);
                }
            }
            printf(" %d", cnt);
            for(int i = 0; i < cnt; i++)
                printf(" %d", ans[i]);
            printf(".\n");
        }
        else
            printf("Impossible.\n");
    }
    return 0;
}























