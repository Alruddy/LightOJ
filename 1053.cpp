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

int t,a,b,c,kase = 0;
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d", &a,&b,&c);
        if(a > b) swap(a,b);
        if(a > c) swap(a,c);
        if(b > c) swap(b,c);
        if(a*a + b*b == c*c)
            printf("Case %d: yes\n", ++kase);
        else
            printf("Case %d: no\n", ++kase);
    }
    return 0;
}

