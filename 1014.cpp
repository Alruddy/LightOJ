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
vector<int> ans;
int t,kase=0,p,l;
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        ans.clear();
        scanf("%d%d", &p, &l);
        int tmp = p-l;
        int flag = 1;
        printf("Case %d:", ++kase);
        if(tmp <= l)
            printf(" impossible");
        else
        {
            int m = sqrt(tmp+0.5);
            for(int i = 1; i <= m; i++)
            {
                if(tmp%i==0)
                {
                    if(i > l) ans.push_back(i);
                    if(i != tmp/i && tmp/i > l) ans.push_back(tmp/i);
                }
            }
            sort(ans.begin(),ans.end());
            for(int i = 0; i < ans.size(); i++)
                printf(" %d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
