
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



int main()
{
    int n, i, x;
    long int f1[41] = { 0 };
    long int f0[41] = { 0 };
    f1[0] = 0;
    f1[1] = 1;
    f0[0] = 1;
    f0[1] = 0;
    for (i = 2; i < 41; i++)
    {
        f0[i] = f0[i - 1] + f0[i - 2];
        f1[i] = f1[i - 1] + f1[i - 2];
    }
    
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        printf("%ld %ld\n", f0[x], f1[x]);
    }
}