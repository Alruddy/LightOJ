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
//#include <math.h>
#include <bitset>
#include <ctype.h>
using namespace std;
typedef pair<int,int> P;
typedef long long LL;
const int INF = 0x3f3f3f3f;
//const double PI = acos(-1.0);
const double eps = 1e-9;
const int N = 1200 + 5;
const int mod = 1e9 + 7;
int t, kase = 0;
int c[N][N];
int n;
void init()
{
    memset(c, 0, sizeof(c));
}
inline int lowbit(int i)
{
    return i&(-i);
}
void add(int x, int y, int val)
{
    for(int i = x; i <= n; i += lowbit(i))
    {
        for(int j = y; j <= n; j += lowbit(j))
        {
            c[i][j] += val;
        }
    }
}
int sum(int x, int y)
{
    int ans = 0;
    for(int i = x; i > 0; i -= lowbit(i))
        for(int j = y; j > 0; j -= lowbit(j))
            ans += c[i][j];
    return ans;
}
int query(int x1, int y1, int x2, int y2)
{
    return sum(x2,y2) - sum(x2, y1-1) - sum(x1-1, y2) + sum(x1-1, y1-1);
}
int x1,x2,y1,y2,q,type;
int main()
{
    n = 1001;
    scanf("%d", &t);
    while(t--)
    {
        memset(c, 0, sizeof(c));
        printf("Case %d:\n", ++kase);
        scanf("%d", &q);
        while(q--)
        {
            scanf("%d", &type);
            if(type == 0)
            {
                scanf("%d%d", &x1,&y1);
                x1++,y1++;
                if(!query(x1,y1,x1,y1))
                    add(x1,y1,1);
            }
            else
            {
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                x1++,y1++,x2++,y2++;
                printf("%d\n", query(x1,y1,x2,y2));
            }
        }
    }
    return 0;


}



