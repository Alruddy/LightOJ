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
const int INF = 0x3f3f3f3f;
const int N = 20000 + 5;
int t,n,m,kase = 0;
string drink1,drink2;
map<string, int> mp;
int cnt;
vector<int> G[N];
int ind[N];
void init()
{
    cnt = 0;
    mp.clear();
    memset(ind, 0, sizeof(ind));
    for(int i = 0; i < N; i++) G[i].clear();
}
bool toposort()
{
    priority_queue<P, vector<P>, greater<P> > pq; while(!pq.empty()) pq.pop();
    int k = 0;
    for(int i = 0; i < n; i++) pq.push(P(ind[i], i));
    while(!pq.empty())
    {
        P p = pq.top(); pq.pop(); k++;
        int in = p.first, u = p.second;
        if(in > 0) return false;
        if(k == n) return true;
        for(int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            ind[v]--;
            pq.push(P(ind[v], v));
        }
    }
    return true;
}
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        init();
        scanf("%d", &m);
        for(int i = 0; i < m; i++)
        {
            cin>>drink1>>drink2;
            if(!mp.count(drink1)) mp[drink1] = cnt++;
            if(!mp.count(drink2)) mp[drink2] = cnt++;
            G[mp[drink1]].push_back(mp[drink2]);
            ind[mp[drink2]]++;
        }
        n = cnt;
        printf("Case %d: ", ++kase);
        if(toposort())
            printf("Yes\n");
        else
            printf("No\n");
    }
}
