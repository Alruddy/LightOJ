#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
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
int t, kase = 0;

set<int> s;
int a[10];
int A[10];
struct Node
{
    int a[10];
    int t;
    Node(){}
    Node(int *B, int T)
    {
        for(int i = 0; i < 8; i++)
            a[i] = B[i];
        t = T;
    }
};
int Hash(int* A)
{
    int ret = 0;
    for(int i = 0; i < 8; i++)
        ret = ret*10 + abs(A[i]);
    return ret;
}
bool inHash(int tmp)
{
    return s.count(tmp);
}
bool isprime(int x)
{
    if(x == 1) return false;
    for(int i = 2; i <= (int)sqrt(x); i++)
        if(x % i == 0) return false;
    return true;
}
bool judgeSorted(int *A)
{
    for(int i = 0; i < 8; i++)
    {
        if(abs(A[i]) != i+1) return false;
    }
    return true;
}
int bfs()
{
    queue<Node> Q;
    s.clear();
    Node st(a,0);
    Q.push(st);
    int tmp = Hash(a);
    s.insert(tmp);
    while(!Q.empty())
    {
        Node u = Q.front(); Q.pop();
        if(judgeSorted(u.a))
        {
            return u.t;
        }
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                if(i == j) continue;
                if(u.a[i]*u.a[j] > 0) continue;
                if(!isprime(abs(u.a[i]) + abs(u.a[j]))) continue;

                Node v;
                int index;
                for(int k = 0, p = 0; k < 7; k++,p++)
                {
                    if(k == i) p++;
                    v.a[k] = u.a[p];
                    if(p == j) index = k;
                }
                int tmp = u.a[i];
                // after
                for(int k = 6; k > index; k--)
                {
                    v.a[k+1] = v.a[k];
                }
                v.a[index+1] = tmp;
                v.t = u.t+1;
                int h = Hash(v.a);
                if(!inHash(h))
                {
                    s.insert(h);
                    Q.push(v);
                }
                //before
                v.a[index+1] = v.a[index];
                v.a[index] = tmp;
                v.t = u.t+1;
                h = Hash(v.a);
                if(!inHash(h))
                {
                    s.insert(h);
                    Q.push(v);
                }
            }
        }
    }
    return -1;
}
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        for(int i = 0; i < 8; i++)
        {
            scanf("%d", &a[i]);
        }
        printf("Case %d: %d\n", ++kase, bfs());
    }
    return 0;
}
