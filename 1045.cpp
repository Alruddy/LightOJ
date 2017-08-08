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
const int N = 1e6 + 5;
int t,n,b,kase = 0;
double f[N];
void init()
{
    f[0] = 0.0;
    for(int i = 1; i < N; i++)
        f[i] = f[i-1] + log(i);
}
int main()
{
    init();
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &b);
        LL k = f[n]/log(b);
        printf("Case %d: %lld\n", ++kase, k+1LL);
    }
    return 0;
}
