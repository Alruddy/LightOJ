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
const int N = 300 + 5;
int t,a,b,n,kase = 0;

int main()
{
    while(scanf("%d", &t) != EOF)
    {
        kase = 0;
        while(t--)
        {
            scanf("%d", &n);
            int sum = 0;
            for(int i = 0; i < n; i++)
            {
                scanf("%d%d", &a, &b);
                sum ^= b-a-1;
            }
            printf("Case %d: ", ++kase);
            if(!sum)
                printf("Bob\n");
            else
                printf("Alice\n");
        }
    }
    return 0;
}








