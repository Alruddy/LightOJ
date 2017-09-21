#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <math.h>
#include <bitset>
#include <ctype.h>
using namespace std;
typedef pair<int,int> P;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-9;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int n;
LL c[N];
inline LL lowbit(int i)
{
    return i&(-i);
}
void add(int x, LL val)
{
    while(x <= n)
    {
        c[x] += val;
        c[x] %= mod;
        x += lowbit(x);
    }
}
LL sum(int x)
{
    LL sum = 0;
    while(x)
    {
        sum += c[x];
        sum %= mod;
        x -= lowbit(x);
    }
    return sum;
}
int t,kase = 0;
struct Node
{
    int id;
    int val;
    Node(){}
    Node(int a, int b) { id = a; val = b;}
}node[N];
bool cmp1(Node a, Node b)
{
    return a.val < b.val;
}
bool cmp2(Node a, Node b)
{
    return a.id < b.id;
}
map<LL,int> mp;
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &node[i].val);
            node[i].id = i;
        }
        sort(node+1, node+1+n, cmp1);
        mp.clear();
        int pos = 1;
        for(int i = 1; i <= n; i++)
        {
            if(!mp.count(node[i].val)) mp[node[i].val] = pos++;
            node[i].val = mp[node[i].val];
        }
        sort(node+1, node+1+n, cmp2);
        memset(c, 0, sizeof(c));
        for(int i = 1; i <= n; i++)
        {
            int tmp = sum(node[i].val-1) + 1;
            add(node[i].val, tmp);
        }
        printf("Case %d: %d\n", ++kase, sum(pos-1));
    }
    return 0;
}
