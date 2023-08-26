

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int num, n;
    scanf("%d", &n);
    double a, b, c, v1, v2, va, vb;
    a = (double)(n * n - 1)/(n*n+1);
    b = (double)(2 * n * n) / (n * n + 1);
    c = (double)2 / (n * n + 1);
    v1 = b;
    v2 = -a;
    num = 1;
    while (1)
    {
        if (v1 < v2)
        {
            num++;
            break;
        }
        else if(v1 == 0)
        {
            break;
        }
        va = v1;
        vb = v2;
        v1 = -a * va + b * vb;
        v2 = c * va + a * vb;
        num += 2;
        if (v1 > 0 && v1 < v2)
            break;
        v1 = -v1;
        
    }
    printf("%d", num);
}