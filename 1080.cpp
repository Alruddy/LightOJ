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
using namespace std;
typedef pair<int,int> P;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-9;
const int N = 1e5 + 5;
int n;
int c[N];
inline int lowbit(int i)
{
    return i&(-i);
}
void add(int val, int x)
{
    while(x <= n)
    {
        c[x] += val;
        x += lowbit(x);
    }
}
int sum(int x)
{
    int sum = 0;
    while(x)
    {
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}

void update(int i, int j)
{
    add(1,  i);
    add(-1, j+1);
}

int query(int x)
{
    return sum(x)&1;
}

void init(char *s, int n)
{
    memset(c, 0, sizeof(c));
    for(int i = 1; i <= n; i++)
    {
        if(s[i] == '1')
        {
            int j = i;
            while(j <= n && s[j] == '1') j++;
            update(i,j-1);
            i = j;
        }
    }
}
int t, kase = 0;
char s[100005];
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", s+1);
        n = strlen(s+1);
        init(s, n);
        int q;
        scanf("%d", &q);
        printf("Case %d:\n",++kase);
        while(q--)
        {
            int x,y;
            scanf("%s", s);
            if(s[0] == 'I')
            {
                scanf("%d%d", &x,&y);
                update(x,y);
            }
            else if(s[0] == 'Q')
            {
                scanf("%d", &x);
                printf("%d\n", query(x));
            }
        }
    }
    return 0;
}














