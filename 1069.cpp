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

int t,a,b,ans,kase = 0;
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &a,&b);
        ans = 19;
        ans += 4*(abs(a-b) + a);
        printf("Case %d: %d\n", ++kase, ans);
    }
    return 0;
}
