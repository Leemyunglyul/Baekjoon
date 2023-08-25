
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



int main()
{
    int T, i,x1, y1, r1, x2, y2, r2;
    double d, r, r_;
    scanf("%d", &T);
    for (i = 0; i < T; i++)
    {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        r = r1 + r2;
        if (r1 >= r2)
            r_ = r1 - r2;
        else
            r_ = r2 - r1;
        if(x1==x2 && y1==y2 && r1==r2)
            printf("-1\n");
        else if (d>r_ && d<r)
            printf("2\n");
        else if(r==d || r_==d)
            printf("1\n");
        else if(r<d || d<r_ || x1 == x2 && y1 == y2)
            printf("0\n");
    }
}