#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int t,a,b;
int kase = 0;
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &a,&b);
        printf("Case %d: %d\n", ++kase, a+b);
    }
    return 0;
}
