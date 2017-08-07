#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int t,n,a,b;
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        if(n > 10) a = n - 10, b = 10;
        else a = 0, b = n;
        printf("%d %d\n", a, b);
    }
    return 0;
}
