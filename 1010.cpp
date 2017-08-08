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

int t,x,y,kase=0;
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &x, &y);
        if(x > y) swap(x,y);
        if(x == 1)
            printf("Case %d: %d\n", ++kase, x*y);
        else if(x == 2)
        {
            int ans = 0;
            int tmp = y/4;
            ans += tmp*4;
            y %= 4;
            if(y >= 2) y = 2;
            ans += 2*y;
            printf("Case %d: %d\n", ++kase, ans);
        }else
            printf("Case %d: %d\n", ++kase, (x*y+1)/2);
    }
    return 0;
}
