#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
using namespace std;
typedef pair<int,int> P;
typedef long long LL;
const int INF = 0x3f3f3f3f;

int t,n,k,kase = 0;
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &k);
        printf("Case %d: ", ++kase);
        if(k > n)
        {
            printf("0\n");
            continue;
        }
        LL ans = 1;
        for(int i = 1, j = n; i <= k; i++, j--)
        {
            ans = ans * j / i * j;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
