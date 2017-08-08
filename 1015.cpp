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

int t,a,n,ans,kase = 0;
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        ans = 0;
        scanf("%d", &n);
        while(n--)
        {
            scanf("%d", &a);
            if(a > 0) ans += a;
        }
        printf("Case %d: %d\n", ++kase, ans);
    }
    return 0;
}
