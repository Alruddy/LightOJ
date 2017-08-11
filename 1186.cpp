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
const int N = 100 + 5;
int t,n,w[N],b[N],r[N],kase=0;
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &w[i]);
        for(int i = 0; i < n; i++)
            scanf("%d", &b[i]);
        for(int i = 0; i < n; i++)
            r[i] = b[i]-w[i]-1;
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum ^= r[i];
        printf("Case %d: ", ++kase);
        if(!sum)
            printf("black wins\n");
        else
            printf("white wins\n");
    }
    return 0;
}















