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
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int t, kase = 0;
int c[N];
int n,q,type,x,y;
inline int lowbit(int i)
{
    return i&(-i);
}
void add(int x, int val)
{
    while(x <= n)
    {
        c[x] += val;
        x += lowbit(x);
    }
}
int sum(int x)
{
    int res = 0;
    while(x)
    {
        res += c[x];
        x -= lowbit(x);
    }
    return res;
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        printf("Case %d:\n", ++kase);
        scanf("%d%d", &n, &q);
        memset(c, 0, sizeof(c));
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &x);
            add(i, x);
        }
        while(q--)
        {
            scanf("%d", &type);
            if(type == 1)
            {
                scanf("%d", &x);
                x++;
                int ans = sum(x) - sum(x-1);
                add(x, -ans);
                printf("%d\n", ans);
            }
            else if(type == 2)
            {
                scanf("%d%d", &x,&y);
                x++;
                add(x, y);
            }
            else
            {
                scanf("%d%d", &x, &y);
                x++;y++;
                int ans = sum(y) - sum(x-1);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}


