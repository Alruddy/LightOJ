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

int t,ans,kase = 0;
double r;
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lf", &r);
        printf("Case %d: %.2f\n", ++kase, (4-PI)*r*r+eps
               );
    }
    return 0;
}

