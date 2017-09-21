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
#include <bitset>
#include <ctype.h>
using namespace std;
typedef pair<int,int> P;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
const int N = 700 + 5;
const LL mod = 1LL << 32;

int n;
LL c[N][N];
inline int lowbit(int i)
{
    return i&(-i);
}
void add(int x, int y, int val)
{
    for(int i = x; i <= n; i += lowbit(i))
    {
        for(int j = y; j <= n; j += lowbit(j))
            c[i][j] = (c[i][j] + val)%mod;
    }
}
LL sum(int x, int y)
{
    LL ans = 0;
    for(int i = x; i > 0; i -= lowbit(i))
    {
        for(int j = y; j > 0; j -= lowbit(j))
            ans = (c[i][j] + ans)%mod;
    }
    return ans;
}


struct Node
{
    int x,y;
    LL sum;
    Node(){}
    Node(int _x, int _y, LL s)
    {
        x = _x; y = _y;
        sum = s;
    }
};
bool cmp(Node a, Node b)
{
    if(a.sum == b.sum)
    {
        return a.x == b.x ? a.y>b.y : a.x<b.x;
    }
    return a.sum < b.sum;
}
vector<Node> tmp;
int t, kase = 0;
LL a[N];
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        tmp.clear();
        scanf("%d", &n);
        memset(c, 0, sizeof(c));
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = i+1; j <= n; j++)
            {
                tmp.push_back(Node(i,j,(a[i]+a[j])%mod));
            }
        }
        sort(tmp.begin(), tmp.end(), cmp);
        LL res = 0;
        for(int i = 0; i < tmp.size(); i++)
        {
            int x = tmp[i].x, y = tmp[i].y;
            LL ans = (sum(y-1,y-1) - sum(x,y-1) - sum(y-1, x) + sum(x,x) + 4*mod) % mod;
            ans = (ans + 1)%mod;
            add(x,y,ans);
            res += ans;
            res %= mod;
        }
        printf("Case %d: %lld\n", ++kase, res);
    }
    return 0;
}






