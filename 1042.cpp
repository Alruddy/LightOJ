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

int t, n, kase = 0;
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        int k = n&(-n);
        int cnt = -1;
        while(n&k)
        {
            cnt++;
            k <<= 1;
        }
        n += k;
        do
        {
            k >>= 1;
            if(n&(k)) n -= k;
        }while(k);
        for(int i = 0; i < cnt; i++)
            n |= 1<<i;
        printf("Case %d: %d\n", ++kase, n);
    }
    return 0;
}
