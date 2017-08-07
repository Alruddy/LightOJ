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
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int mod = 10000007;
struct Matrix
{
    LL c[10][10];
    Matrix(){memset(c, 0, sizeof(c)); for(int i = 0; i < 10; i++) c[i][i] = 1;}
    void cls() {memset(c, 0, sizeof(c));}
};

int t,f[6],n,kase = 0;
Matrix multi(Matrix a, Matrix b, int mod)
{
    Matrix ret;
    ret.cls();
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            for(int k = 0; k < 6; k++)
            {
                ret.c[i][j] += a.c[i][k]*b.c[k][j];
                ret.c[i][j] %= mod;
            }
        }
    }
    return ret;
}

Matrix quick_exp(Matrix a, int n, int mod)
{
    Matrix ret;
    while(n)
    {
        if(n&1) ret = multi(ret, a, mod);
        n >>= 1;
        a = multi(a, a, mod);
    }
    return ret;
}

int main()
{
    Matrix a; a.cls();
    for(int i = 0; i < 6; i++) a.c[0][i] = 1;
    for(int i = 1; i < 6; i++) a.c[i][i-1] = 1;
    scanf("%d", &t);
    while(t--)
    {
        for(int i = 0; i < 6; i++)
        {
            scanf("%d", &f[i]);
            f[i] %= mod;
        }
        scanf("%d", &n);
        printf("Case %d: ", ++kase);
        if(n <= 5)
        {
            printf("%d\n", f[n]);
        }
        else
        {
            Matrix tmp = a;
            tmp = quick_exp(tmp, n-5, mod);
            LL ans = 0;
            for(int i = 0; i < 6; i++)
                ans = (ans + tmp.c[0][i]*f[5-i])%mod;
            printf("%lld\n", ans);
        }
    }
    return 0;
}


