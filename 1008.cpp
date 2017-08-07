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

int t;
LL n;
int main()
{
    int kase = 0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld", &n);
        LL k = sqrt(n);
        printf("Case %d: ", ++kase);
        if(k*k == n)
        {
            if(k&1)
                printf("%d %lld\n", 1, k);
            else
                printf("%lld %d\n", k, 1);
            continue;
        }
        else
        {
            n -= k*k;
            k++;
            LL row,col;
            if(k&1)
            {
                if(n<=k)
                {
                    row = n;
                    col = k;
                }
                else
                {
                    row = k;
                    col = 2*k-n;
                }
            }
            else
            {
                if(n<=k)
                {
                    row = k;
                    col = n;
                }
                else
                {
                    row = 2*k-n;
                    col = k;
                }
            }
            printf("%lld %lld\n", col, row);
        }
    }
    return 0;
}
