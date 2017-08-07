#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
using namespace std;
typedef pair<int,int> P;
typedef unsigned long long LL;
const int INF = 0x3f3f3f3f;
const int N = 5e6 + 5;
int phi[N];
LL pre[N];
void init()
{
    memset(pre, 0, sizeof(pre));
    for(int i = 1; i < N; i++)
        phi[i] = i;
    for(int i = 2; i < N; i++)
    {
        if(phi[i] == i)
        {
            for(int j = i; j < N; j += i)
                phi[j] -= phi[j]/i;
        }
    }
    for(int i = 2; i < N; i++)
        pre[i] = pre[i-1] + (LL)phi[i]*(LL)phi[i];
}

int t,a,b;
int main()
{
    init();
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &a,&b);
        static int kase = 0;
        printf("Case %d: %llu\n", ++kase, pre[b]-pre[a-1]);
    }
    return 0;
}










