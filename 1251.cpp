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
const int maxn = 20000 + 5;
struct TwoSAT
{
    int n;
    vector<int> G[maxn*2];
    int S[maxn*2],c;
    bool mark[maxn*2];

    void init(int n)
    {
        this->n = n;
        for(int i = 0; i <= 2*n; i++) G[i].clear();
        memset(mark, 0, sizeof(mark));
    }

    bool dfs(int x)
    {
        if(mark[x^1]) return false;
        if(mark[x]) return true;
        mark[x] = 1;
        S[c++] = x;
        for(int i = 0; i < G[x].size(); i++)
        {
            if(!dfs(G[x][i])) return false;
        }
        return true;
    }

    void add_clause(int x, int xval, int y, int yval)
    {
        x = 2*x + xval;
        y = 2*y + yval;
        G[x^1].push_back(y);
        G[y^1].push_back(x);
    }

    bool solve()
    {
        for(int i = 0; i < n*2; i += 2)
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
TwoSAT twosat;
int t,n,m,kase=0;
char vote1[10],vote2[10];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        twosat.init(m);
        for(int i = 0; i < n; i++)
        {
            scanf("%s%s", vote1, vote2);
            int xval,x,yval,y,j;
            if(vote1[0] == '-') xval = 0;
            else xval = 1;
            x = 0;
            j = 1;
            while(vote1[j] != '\0')
            {
                x = x*10+vote1[j]-'0';
                j++;
            }

            if(vote2[0] == '-') yval = 0;
            else yval = 1;
            y = 0;
            j = 1;
            while(vote2[j] != '\0')
            {
                y = y*10 + vote2[j]-'0';
                j++;
            }
            twosat.add_clause(x-1, xval, y-1, yval);
        }
        printf("Case %d: ", ++kase);
        if(!twosat.solve())
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
            int cnt = 0;
            vector<int> ans;
            for(int i = 0; i < 2*m; i+=2)
            {
                if(!twosat.mark[i])
                {
                    cnt++;
                    ans.push_back(i/2+1);
                }
            }
            printf("%d", cnt);
            for(int i = 0; i < cnt; i++)
                printf(" %d", ans[i]);
            printf("\n");
        }
    }
    return 0;

}





