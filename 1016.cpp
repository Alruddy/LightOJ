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
const int N = 5e4 + 5;
int x,y[N];
int t,kase=0,n,w,cnt;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &w);
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &x, &y[i]);
        }
        sort(y, y + n);
        cnt = 0;
        int pos = 0;
        int i = 0;
        while(i < n)
        {
            while(i < n && y[pos] + w >= y[i]) i++;
            cnt++;
            pos = i;
        }
        printf("Case %d: %d\n", ++kase, cnt);
    }
    return 0;
}



