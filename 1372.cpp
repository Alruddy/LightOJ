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
const int N = 1e6 + 5;
const int mod = 1e9 + 7;
int n,t,kase=0;
int c[N],a[N];
inline int lowbit(int x)
{
    return x&(-x);
}

void add(int x, int val)
{
    while(x < N)
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
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a+n);
        memset(c, 0, sizeof(c));
        LL ans = 0;
        for(int k = n-1; k >= 0; k--)
        {
            for(int i = 0; i < k; i++)
            {
                for(int j = i+1; j < k; j++)
                {
                    int tmp = a[i]+a[j]+a[k];
                    ans += sum(tmp-1);
                }
            }

            for(int i = k+1; i < n; i++)
            {
                for(int j = i+1; j < n; j++)
                {
                    int tmp = a[j]-a[i]-a[k];
                    if(tmp <= 0) tmp = 1;
                    add(tmp, 1);
                }
            }
        }


        printf("Case %d: %lld\n", ++kase, ans);
    }
    return 0;
}














