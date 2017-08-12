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
const int N = 1e8 + 2;
const int MAXN = 6E6;
unsigned int vis[(N+31)/32 + 5];
int prime[MAXN],tot;
unsigned int sum[MAXN];
inline int Get(int x)
{
    int low = x%32, high = x/32;
    return (1<<low) & vis[high];
}
inline void Set(int x)
{
    int low = x%32, high = x/32;
    vis[high] |= 1<<low;
}
void getprime(int n)
{
    tot = 0;
    for(int i = 2; i <= n; i++)
    {
        if(!Get(i)) prime[tot++] = i;
        for(int j = 0; j < tot; j++)
        {
            if(i*prime[j] > n) break;
            Set(i*prime[j]);
            if(i % prime[j] == 0) break;
        }
    }
    sum[0] = prime[0];
    for(int i = 1; i < tot; i++)
        sum[i] = sum[i-1]*(unsigned int)prime[i];
}

int n,t,kase=0;
bool check(int cnt, int mid)
{
    LL ans = 1;
    for(int i = 0; i < cnt; i++)
    {
        ans *= prime[mid];
        if(ans > n)
            return false;
    }
    return true;
}

unsigned int solve(int x)
{
    int l = 6, r = tot;
    unsigned int ans = 1;
    int cnt = 0;
    while(l > 0)
    {
        l = 0; r = tot-1;
        cnt++;
        while(l <= r)
        {
            int mid = (l+r)>>1;
            if(check(cnt, mid))
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        if(l >= 1)
            ans = (ans * sum[l-1]);
    }
    return ans;
}

int main()
{
    getprime(100000000);
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        printf("Case %d: %u\n", ++kase, solve(n));
    }
    return 0;
}










